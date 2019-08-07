#include <stdio.h>
#include <stdlib.h>

typedef struct QueueList {
	int *item;
	int front, rear;
	int max;
}QueueList;

void init(QueueList *q) {
	int i;
	for (i = 0; i < q->max; i++) {
		q->item[i] = 0;
	}
}

int is_full(QueueList *q) {
	return ((q->rear + 1) % q->max == q->front);
}

int is_empty(QueueList *q) {
	return q->front == q->rear;
}


void enqueue(QueueList *q, int elem) {
	int i;

	if (is_full(q)) {
		printf("overflow");
		for (i = 0;i<q->max; i++) {
			printf(" %d", q->item[i]);
		}
		printf("\n");
	}
	else {
		q->rear = (q->rear + 1) % q->max;
		q->item[q->rear] = elem;
	}
	
}

void dequeue(QueueList *q) {
	int i;

	if (is_empty(q)) {
		printf("underflow\n");
	}
	else {
		q->front = (q->front + 1) % q->max; 
		q->item[q->front] = 0;
	}
}

void print(QueueList *q) {
	int i;

	for (i = 0; i <q->max; i++) {
		printf(" %d", q->item[i]);
	}
	printf("\n");
}

void main() {
	QueueList *q = (QueueList*)malloc(sizeof(QueueList));
	int size,n,i,elem;
	char type;

	scanf("%d", &size);//큐 사이즈
	q->item = (int*)malloc(sizeof(int)*size);
	q->front = 0;//처음 삽입 위치 1번!
	q->rear = 0;
	q->max = size;
	init(q);

	scanf("%d", &n);//연산개수
	getchar();

	for (i = 0; i < n; i++) {
		scanf("%c", &type);
		switch (type) {
		case 'I':scanf("%d", &elem); getchar(); enqueue(q, elem); break;
		case 'D':dequeue(q); getchar(); break;
		case 'P':print(q); getchar(); break;
		default:;
		}
	}
	free(q);


}