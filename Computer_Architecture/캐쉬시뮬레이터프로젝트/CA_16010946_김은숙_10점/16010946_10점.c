#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <dos.h>
#include <conio.h>

//log 변환 함수
int logB(int x, int base);

FILE *fp;//파일 읽을 포인터
unsigned int fetched_inst; //명령어의 16진수를 정수형으로 읽기 위한 변수

int operand; // (0일때 read data, 1 write data)  <- data cache , 2 instruction fetch <- instruction cache  
int inMiss, inAccess;//insruction cache 의 miss, access 변수
int dtMiss, dtAccess;//data cache 의 miss, access 변수

typedef struct QueueNode {
	int tag;
	struct QueueNode *link;
}QueueNode;//큐 노드 구조체

typedef struct QueueType {
	QueueNode *head;
}QueueType;//큐의 헤드를 저장하는 큐 타입 구조체

QueueNode* getNode(int tag) {
	QueueNode *p = (QueueNode*)malloc(sizeof(QueueNode));
	p->tag = tag;
	p->link = NULL;
	return p;
}//노드를 생성하는 함수

int confirmAssoc(QueueType *q) {
	QueueNode *p = q->head;
	int cnt = 0;
	while (p != NULL) {
		cnt++;
		p = p->link;
	}
	return cnt;
}//해당 index의 자리가 꽉 찼는지 확인하기 위한 함수

int confirmHit(QueueType *q, int t) {
	QueueNode* p = q->head;

	while (p != NULL) {
		if (p->tag == t) return 1;
		p = p->link;
	}
	return 0;
}// 해당 index의 노드 중에 hit이 되는 노드가 있는지 확인하는 함수

void dequeue(QueueType *q) {
	QueueNode *p = q->head;

	q->head = q->head->link;
	free(p);
}//해당 index가 꽉 차있는데 miss가 난 경우 맨 앞 노드를 제거하는 함수


//LRU 함수
void enqueueLRU(QueueType *q, int tag, int assoc) {
	QueueNode *p = q->head;
	QueueNode *prev = q->head;
	int x;//hit인지 아닌지 저장하는 변수

	x = confirmHit(q, tag);//hit인지 아닌지 저장

	if (confirmAssoc(q) == assoc) {
		if (!x) {
			dequeue(q); //꽉 찼는데 miss인 경우 호출
		}
	}

	//hit이 있는 경우
	if (x) {
		while (p != NULL) {
			if (p->tag == tag) {
				
				if (p == q->head) {
					if (p->link != NULL) {
						q->head = p->link;
					}
					else q->head = NULL;
				}//p가q->head인 경우 중에 다음 노드가 있는 경우와 없는 경우를 나눠서 처리

				else {
					prev->link = p->link;
				}//p가 q->head가 아니경우

				free(p);//hit 된 노드 삭제
				break;
			}
			prev = p;
			p = p->link;
		}
	}

	p = q->head;

	//맨 뒤에 노드 삽입
	if (p == NULL) {
		q->head = getNode(tag);
	}
	else {
		while (p->link != NULL) {
			p = p->link;
		}
		p->link = getNode(tag);
	}

	//miss 난 경우 operand에 따라 miss를 올려준다.
	if (x == 0) {
		if(operand==0||operand==1) dtMiss++;
		else inMiss++;
	}
}

//FIFO 함수
void enqueueFIFO(QueueType *q, int tag, int assoc) {
	QueueNode *p = q->head;
	QueueNode *prev = q->head;
	int x;

	x = confirmHit(q, tag);//hit이 있는지 없는지 판단
	
	if (x) return; //hit이 있는 경우

	if (confirmAssoc(q) == assoc) {
		if (!x) {
			dequeue(q); //꽉 찼는데 miss인 경우
		}
	}

	p = q->head;

	//miss인경우 맨 뒤에 노드 삽입
	if (p == NULL) {
		q->head = getNode(tag);
	}
	else {
		while (p->link != NULL) {
			p = p->link;
		}
		p->link = getNode(tag);
	}

	//miss 난 경우 operand에 따라 miss증가
	if (operand == 0 || operand == 1) dtMiss++;
	else inMiss++;
}

void init(QueueType *q, int r) {
	int i;

	for (i = 0; i < r; i++) {
		q[i].head = NULL;
	}
}//큐 초기화 함수

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
	QueueType *q,*dtq;//instruct cache와 data cache에 해당하는 큐
	char str_file[20] = { 0 };//파일 입력 받기 위한 변수
	int modeN, inCacheN, inBlockN, inAssocN, dtCacheN, dtBlockN, dtAssocN;//입력 정보와 관련된 변수 in : instruction 관련 , dt : data 관련
	int n, m, tagBit, indexBit, offsetBit,dm,dn,dTagBit,dIndexBit,dOffsetBit;//instruction 과 data관련된 indexBit,offsetBit,tagBit 변수
	unsigned int index, tag,dIndex,dTag;//index,tag를 잘라서 넣기 위한 변수 
	double inMissratio=0,dtMissratio=0; //missratio 변수

	// Trace file 입력 받기
	printf("File : ");
	scanf("%s", str_file);

	//  트레이스 파일 읽기
	if ((fp = fopen(str_file, "r")) == NULL) {
		printf("file open error");
		exit(1);
	}

	//입력 정보 입력 받기
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

	//instruction 과 관련된 m,n,tagBit,indexBit,offsetBit을 구하고 miss와 access를 0으로 초기화한다.
	m = logB(inBlockN / 4, 2) + 2;
	n = logB((inCacheN * 1024 / (inBlockN*inAssocN)), 2);
	tagBit = 32 - n - m;
	indexBit = n;
	offsetBit = m;
	inMiss = 0;
	inAccess = 0;

	//data 와 관련된 m,n,tagBit,indexBit,offsetBit을 구하고 miss와 access를 0으로 초기화한다.
	dm = logB(dtBlockN / 4, 2) + 2;
	dn = logB(dtCacheN * 1024 / (dtBlockN*dtAssocN), 2);
	dTagBit = 32 - dn - dm;
	dIndexBit = dn;
	dOffsetBit = dm;
	dtMiss = 0;
	dtAccess = 0;
	
	//instruction 큐와 data 큐를 크기만큼 동적할당한다.
	q = (QueueType*)malloc(sizeof(QueueType)*((inCacheN * 1024) / (inBlockN*inAssocN)));
	dtq = (QueueType*)malloc(sizeof(QueueType)*((dtCacheN * 1024) / (dtBlockN*dtAssocN)));

	//instruction 큐와 data 큐를 초기화 한다.
	init(q, (inCacheN * 1024) / (inBlockN*inAssocN));
	init(dtq, (dtCacheN * 1024) / (dtBlockN*dtAssocN));

	while (feof(fp) == 0)		//파일 끝까지 문자열 불러오기.
	{
		fscanf(fp, "%d", &operand);//operand 읽기
		//Trace file 명령어를 정수형으로 읽기 - 명령어를 문자열로 읽는 함수의 대체로 활용 가능
		fscanf(fp, "%x", &fetched_inst);

		if (operand == 0 || operand == 1)		//data cahce 동작 구현
		{
			//index와 tag를 잘라서 저장
			dIndex = (fetched_inst << dTagBit);
			dIndex = (dIndex >> (32 - dIndexBit));
			dTag = (fetched_inst >> (32 - dTagBit));

			//data cache에 접근할 때마다 access를 증가
			dtAccess++;

			//LRU인지 FIFO인지를 구분해서 각각의 함수를 호출
			if (modeN == 1) enqueueLRU(dtq + dIndex, dTag, dtAssocN);
			else if (modeN == 2) enqueueFIFO(dtq + dIndex, dTag, dtAssocN);
		}
		if (operand == 2)				//inst cache 동작 구현
		{
			//index와 tag를 잘라서 저장
			index = (fetched_inst << tagBit);
			index = (index >> (32 - indexBit));
			tag = (fetched_inst >> (32 - tagBit));
			
			//insruction cache에 접근할 때마다 access를 증가
			inAccess++;

			//LRU인지 FIFO인지를 구분해서 각각의 함수를 호출
			if (modeN == 1) enqueueLRU(q+index, tag, inAssocN);
			else if (modeN == 2) enqueueFIFO(q + index, tag, inAssocN);
		}
	}
	
	//instruction cache와 data cache의 missratio를 구한다.
	inMissratio = (double)inMiss / (double)inAccess;
	dtMissratio = (double)dtMiss / (double)dtAccess;
	
	//instruction cache 정보 출력
	printf("\nInstruction cache\n");
	printf("Access : %d\n", inAccess);
	printf("Miss : %d\n", inMiss);
	printf("Miss ratio : %.4lf\n", inMissratio);

	//data cache 정보 출력
	printf("\nData cache\n");
	printf("Access : %d\n", dtAccess);
	printf("Miss : %d\n", dtMiss);
	printf("Miss ratio : %.4lf\n", dtMissratio);

	//동적할당 해제
	freedom(q, (inCacheN * 1024) / (inBlockN*inAssocN));
	freedom(dtq, (dtCacheN * 1024) / (dtBlockN*dtAssocN));

	return 0;
}

int logB(int x, int base) {
	return log(x) / log(base);
}//로그 변환 함수 


