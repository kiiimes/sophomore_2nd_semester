#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <dos.h>
#include <conio.h>

//log ��ȯ �Լ�
int logB(int x, int base);

FILE *fp;//���� ���� ������
unsigned int fetched_inst; //��ɾ��� 16������ ���������� �б� ���� ����

int operand; // (0�϶� read data, 1 write data)  <- data cache , 2 instruction fetch <- instruction cache  
int inMiss, inAccess;//insruction cache �� miss, access ����
int dtMiss, dtAccess;//data cache �� miss, access ����

typedef struct QueueNode {
	int tag;
	struct QueueNode *link;
}QueueNode;//ť ��� ����ü

typedef struct QueueType {
	QueueNode *head;
}QueueType;//ť�� ��带 �����ϴ� ť Ÿ�� ����ü

QueueNode* getNode(int tag) {
	QueueNode *p = (QueueNode*)malloc(sizeof(QueueNode));
	p->tag = tag;
	p->link = NULL;
	return p;
}//��带 �����ϴ� �Լ�

int confirmAssoc(QueueType *q) {
	QueueNode *p = q->head;
	int cnt = 0;
	while (p != NULL) {
		cnt++;
		p = p->link;
	}
	return cnt;
}//�ش� index�� �ڸ��� �� á���� Ȯ���ϱ� ���� �Լ�

int confirmHit(QueueType *q, int t) {
	QueueNode* p = q->head;

	while (p != NULL) {
		if (p->tag == t) return 1;
		p = p->link;
	}
	return 0;
}// �ش� index�� ��� �߿� hit�� �Ǵ� ��尡 �ִ��� Ȯ���ϴ� �Լ�

void dequeue(QueueType *q) {
	QueueNode *p = q->head;

	q->head = q->head->link;
	free(p);
}//�ش� index�� �� ���ִµ� miss�� �� ��� �� �� ��带 �����ϴ� �Լ�


//LRU �Լ�
void enqueueLRU(QueueType *q, int tag, int assoc) {
	QueueNode *p = q->head;
	QueueNode *prev = q->head;
	int x;//hit���� �ƴ��� �����ϴ� ����

	x = confirmHit(q, tag);//hit���� �ƴ��� ����

	if (confirmAssoc(q) == assoc) {
		if (!x) {
			dequeue(q); //�� á�µ� miss�� ��� ȣ��
		}
	}

	//hit�� �ִ� ���
	if (x) {
		while (p != NULL) {
			if (p->tag == tag) {
				
				if (p == q->head) {
					if (p->link != NULL) {
						q->head = p->link;
					}
					else q->head = NULL;
				}//p��q->head�� ��� �߿� ���� ��尡 �ִ� ���� ���� ��츦 ������ ó��

				else {
					prev->link = p->link;
				}//p�� q->head�� �ƴϰ��

				free(p);//hit �� ��� ����
				break;
			}
			prev = p;
			p = p->link;
		}
	}

	p = q->head;

	//�� �ڿ� ��� ����
	if (p == NULL) {
		q->head = getNode(tag);
	}
	else {
		while (p->link != NULL) {
			p = p->link;
		}
		p->link = getNode(tag);
	}

	//miss �� ��� operand�� ���� miss�� �÷��ش�.
	if (x == 0) {
		if(operand==0||operand==1) dtMiss++;
		else inMiss++;
	}
}

//FIFO �Լ�
void enqueueFIFO(QueueType *q, int tag, int assoc) {
	QueueNode *p = q->head;
	QueueNode *prev = q->head;
	int x;

	x = confirmHit(q, tag);//hit�� �ִ��� ������ �Ǵ�
	
	if (x) return; //hit�� �ִ� ���

	if (confirmAssoc(q) == assoc) {
		if (!x) {
			dequeue(q); //�� á�µ� miss�� ���
		}
	}

	p = q->head;

	//miss�ΰ�� �� �ڿ� ��� ����
	if (p == NULL) {
		q->head = getNode(tag);
	}
	else {
		while (p->link != NULL) {
			p = p->link;
		}
		p->link = getNode(tag);
	}

	//miss �� ��� operand�� ���� miss����
	if (operand == 0 || operand == 1) dtMiss++;
	else inMiss++;
}

void init(QueueType *q, int r) {
	int i;

	for (i = 0; i < r; i++) {
		q[i].head = NULL;
	}
}//ť �ʱ�ȭ �Լ�

void freedom(QueueType *q,int r) {
	int i;
	QueueNode *prev,*p;

	for (i = 0; i < r; i++) {
		prev = q[i].head;
		p = q[i].head;
		while (p != NULL) {
			prev = p;
			p = p->link;
			free(prev);
		}
	}
	
	free(q);
}

int main()
{
	QueueType *q,*dtq;//instruct cache�� data cache�� �ش��ϴ� ť
	char str_file[20] = { 0 };//���� �Է� �ޱ� ���� ����
	int modeN, inCacheN, inBlockN, inAssocN, dtCacheN, dtBlockN, dtAssocN;//�Է� ������ ���õ� ���� in : instruction ���� , dt : data ����
	int n, m, tagBit, indexBit, offsetBit,dm,dn,dTagBit,dIndexBit,dOffsetBit;//instruction �� data���õ� indexBit,offsetBit,tagBit ����
	unsigned int index, tag,dIndex,dTag;//index,tag�� �߶� �ֱ� ���� ���� 
	double inMissratio=0,dtMissratio=0; //missratio ����

	// Trace file �Է� �ޱ�
	printf("File : ");
	scanf("%s", str_file);

	//  Ʈ���̽� ���� �б�
	if ((fp = fopen(str_file, "r")) == NULL) {
		printf("file open error");
		exit(1);
	}

	//�Է� ���� �Է� �ޱ�
	printf("Mode select (LRU : 1 / FIFO : 2) : ");
	scanf("%d", &modeN);
	printf("Instruction cache size (KB) : ");
	scanf("%d", &inCacheN);
	printf("Instruction cache block size (B) : ");
	scanf("%d", &inBlockN);
	printf("Instruction associativity : ");
	scanf("%d", &inAssocN);
	printf("Data cache size (KB) : ");
	scanf("%d", &dtCacheN);
	printf("Data cache block size (B) : ");
	scanf("%d", &dtBlockN);
	printf("Data associativity : ");
	scanf("%d", &dtAssocN);

	//instruction �� ���õ� m,n,tagBit,indexBit,offsetBit�� ���ϰ� miss�� access�� 0���� �ʱ�ȭ�Ѵ�.
	m = logB(inBlockN / 4, 2) + 2;
	n = logB((inCacheN * 1024 / (inBlockN*inAssocN)), 2);
	tagBit = 32 - n - m;
	indexBit = n;
	offsetBit = m;
	inMiss = 0;
	inAccess = 0;

	//data �� ���õ� m,n,tagBit,indexBit,offsetBit�� ���ϰ� miss�� access�� 0���� �ʱ�ȭ�Ѵ�.
	dm = logB(dtBlockN / 4, 2) + 2;
	dn = logB(dtCacheN * 1024 / (dtBlockN*dtAssocN), 2);
	dTagBit = 32 - dn - dm;
	dIndexBit = dn;
	dOffsetBit = dm;
	dtMiss = 0;
	dtAccess = 0;
	
	//instruction ť�� data ť�� ũ�⸸ŭ �����Ҵ��Ѵ�.
	q = (QueueType*)malloc(sizeof(QueueType)*((inCacheN * 1024) / (inBlockN*inAssocN)));
	dtq = (QueueType*)malloc(sizeof(QueueType)*((dtCacheN * 1024) / (dtBlockN*dtAssocN)));

	//instruction ť�� data ť�� �ʱ�ȭ �Ѵ�.
	init(q, (inCacheN * 1024) / (inBlockN*inAssocN));
	init(dtq, (dtCacheN * 1024) / (dtBlockN*dtAssocN));

	while (feof(fp) == 0)		//���� ������ ���ڿ� �ҷ�����.
	{
		fscanf(fp, "%d", &operand);//operand �б�
		//Trace file ��ɾ ���������� �б� - ��ɾ ���ڿ��� �д� �Լ��� ��ü�� Ȱ�� ����
		fscanf(fp, "%x", &fetched_inst);

		if (operand == 0 || operand == 1)		//data cahce ���� ����
		{
			//index�� tag�� �߶� ����
			dIndex = (fetched_inst << dTagBit);
			dIndex = (dIndex >> (32 - dIndexBit));
			dTag = (fetched_inst >> (32 - dTagBit));

			//data cache�� ������ ������ access�� ����
			dtAccess++;

			//LRU���� FIFO������ �����ؼ� ������ �Լ��� ȣ��
			if (modeN == 1) enqueueLRU(dtq + dIndex, dTag, dtAssocN);
			else if (modeN == 2) enqueueFIFO(dtq + dIndex, dTag, dtAssocN);
		}
		if (operand == 2)				//inst cache ���� ����
		{
			//index�� tag�� �߶� ����
			index = (fetched_inst << tagBit);
			index = (index >> (32 - indexBit));
			tag = (fetched_inst >> (32 - tagBit));
			
			//insruction cache�� ������ ������ access�� ����
			inAccess++;

			//LRU���� FIFO������ �����ؼ� ������ �Լ��� ȣ��
			if (modeN == 1) enqueueLRU(q+index, tag, inAssocN);
			else if (modeN == 2) enqueueFIFO(q + index, tag, inAssocN);
		}
	}
	
	//instruction cache�� data cache�� missratio�� ���Ѵ�.
	inMissratio = (double)inMiss / (double)inAccess;
	dtMissratio = (double)dtMiss / (double)dtAccess;
	
	//instruction cache ���� ���
	printf("\nInstruction cache\n");
	printf("Access : %d\n", inAccess);
	printf("Miss : %d\n", inMiss);
	printf("Miss ratio : %.4lf\n", inMissratio);

	//data cache ���� ���
	printf("\nData cache\n");
	printf("Access : %d\n", dtAccess);
	printf("Miss : %d\n", dtMiss);
	printf("Miss ratio : %.4lf\n", dtMissratio);

	//�����Ҵ� ����
	freedom(q, (inCacheN * 1024) / (inBlockN*inAssocN));
	freedom(dtq, (dtCacheN * 1024) / (dtBlockN*dtAssocN));

	return 0;
}

int logB(int x, int base) {
	return log(x) / log(base);
}//�α� ��ȯ �Լ� 


