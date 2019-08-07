#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <dos.h>
#include <conio.h>

//16���� 2���� ��ȯ�Լ� ����.
void Convert16to2(char *Hex_array);
int logB(int x, int base);

FILE *fp;
char *Hex_array; // ���ϼ� �о�� 16������ ���ڿ��� �б� ���� ������ ����
unsigned int fetched_inst; //��ɾ��� 16������ ���������� �б� ���� ����

						   ////////////////////////////////////////////////////////////////
int operand; // (0�϶� read data, 1 write data)  <- data cache , 2 instruction fetch <- instruction cache  
char binary[33];//16 -> 2������ ��ȯ ���� ����
				///////////////////////////////////////////////////////////////
int inMiss,inAccess;
int dtMiss, dtAccess;

typedef struct QueueNode {
	int tag;
	struct QueueNode *link;
}QueueNode;

typedef struct QueueType {
	QueueNode *head;
}QueueType;

QueueNode* getNode(int tag) {
	QueueNode *p = (QueueNode*)malloc(sizeof(QueueNode));
	p->tag = tag;
	p->link = NULL;
	return p;
}

int confirmAssoc(QueueType *q) {
	QueueNode *p = q->head;
	int cnt=0;
	while (p != NULL) {
		cnt++;
		p = p->link;
	}
	return cnt;
}

int confirmHit(QueueType *q,int t) {
	QueueNode* p = q->head;

	while (p != NULL) {
		if (p->tag == t) return 1;
		p = p->link;
	}
	return 0;
}

QueueNode* returnNode(QueueType* q, int t) {
	QueueNode* p = q->head;
	
	while (p != NULL) {
		if (p->tag == t) return p;
		p = p->link;
	}
	return NULL;
}

void dequeue(QueueType *q) {
	QueueNode *p = q->head;

	q->head = q->head->link;
	free(p);	
}

void enqueueLRU(QueueType *q, int tag,int assoc) {
	QueueNode *p=q->head;
	QueueNode *prev=q->head;
	int x;

	x = confirmHit(q, tag);

	if (p == NULL) {
		q->head = getNode(tag);
	}

	if (confirmAssoc(q) == assoc) {
		if (!x) {
			dequeue(q); //�� á�µ� miss�� ���
		}
	}

	if(x) {
		while (p != NULL) {
			if (p->tag == tag) {
				prev->link = p->link;
				free(prev);
			}
			prev = p;
			p = p->link;
		}
		p = prev;
	}
	
	if(p!=NULL) {
		while (p->link != NULL) {
			p = p->link;
		}
		p->link = getNode(tag);
	}

	if (x == 0) {
		inMiss++;
	}
}
 
void init(QueueType *q,int r) {
	int i;

	for (i = 0; i < r; i++) {
		q[i].head = NULL;
	}
}

int main()
{
	QueueType *q;
	char str_file[20] = { 0 };
	int modeN, inCacheN, inBlockN, inAssocN, dtCacheN, dtBlockN, dtAssocN;
	int n, m, tagBit, indexBit, offsetBit;
	int index, tag, offset;

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

	m = logB(inBlockN/4, 2)+2;
	n = logB((inCacheN*1024/ (inBlockN*inAssocN)),2);
	tagBit = 32 - n - m;
	indexBit = n;
	offsetBit = m;
	inMiss = 0;
	inAccess = 0;
	
	Hex_array = (char *)malloc(sizeof(char) * 11);
	q = (QueueType*)malloc(sizeof(QueueType)*((inCacheN * 1024) / (inBlockN*inAssocN)));



	while (feof(fp) == false)		//���� ������ ���ڿ� �ҷ�����.
	{
		fscanf(fp, "%d", &operand);
		//fscanf(fp, "%s", Hex_array); //��ɾ ���ڿ��� ����
		//Trace file ��ɾ ���������� �б� - ��ɾ ���ڿ��� �д� �Լ��� ��ü�� Ȱ�� ����
		fscanf(fp, "%x", &fetched_inst);
								 
		//Convert16to2(Hex_array); //16���� ���ڿ��� 2���� ������ ���ڿ��� ����
								 //���������� ��ɾ �о��ٸ� Convert16to2 �Լ��� Ȱ���� �ʿ� ����

								 //������ ��ɾ��� Ư�� bit �ڸ��� ���� (tag 22bit, index 8bit, direct-mapped cache)
								 //index = (fetched_inst<<22);
								 //index = (index>>24); -> index�� �ش��ϴ� ���� �����
		
		if (operand == 0 || operand == 1)		//data cahce ���� ����
		{
			//printf("data %d    %s    %s\n", operand, Hex_array, binary);
		}
		if (operand == 2)				//inst cache ���� ����
		{
			index = (fetched_inst << tagBit);
			index = (index >> (32 - indexBit));
			tag = (fetched_inst >> (32 - tagBit));
			
			inAccess++;

			if(modeN==1) enqueueLRU(&(q[index]), tag, inAssocN);

			printf("%d",inAccess);
			//printf("inst %d    %s    %s\n", operand, Hex_array, binary);
		}
	}

	return 0;
}


//16���� 2���� ��ȯ�Լ�.
void Convert16to2(char *Hex_array)
{
	int res = 0;
	char temp;
	unsigned long Hex = strtoul(Hex_array, NULL, 16);

	for (int i = 0; i < 32; i++)
	{
		res = Hex & (0x01 << (31 - i));
		if (res == 0)
		{
			temp = '0';
			binary[i] = temp;
		}
		else
		{
			temp = '1';
			binary[i] = temp;
		}
	}
}

int logB(int x, int base) {
	return log(x) / log(base);
}
