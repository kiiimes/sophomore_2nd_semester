#include <stdio.h>
#include <stdlib.h>

typedef struct QueueType {
	int *data;
	int front, rear;
	int max;
}QueueType;

void init(QueueType *q) {
	int i;
	for (i = 0; i < q->max; i++) {
		q->data[i] = 0;
	}
}

int is_empty(QueueType *q) {
	return q->front == q->rear;
}

int is_full(QueueType *q) {
	return (q->rear + 1) % q->max == q->front;
}

int enqueue(QueueType *q, int item) {
	int i;
	if (is_full(q)) {
		printf("overflow");
		for (i = 0; i < q->max; i++) {
			printf(" %d", q->data[i]);
		}
		printf("\n");
		return 1;
	}
	else {
		q->rear = (q->rear + 1) % q->max;
		q->data[q->rear] = item;
	}
	return 0;
}

int dequeue(QueueType *q) {
	if (is_empty(q)) {
		printf("underflow\n");
		return 1;
	}
	else {
		q->front = (q->front + 1) % q->max;
		q->data[q->front] = 0;
		return 0;
	}
}

void print(QueueType *q) {
	int i;
	for (i = 0; i < q->max; i++) {
		printf(" %d", q->data[i]);
	}
	printf("\n");
}

void main() {
	QueueType *q = (QueueType*)malloc(sizeof(QueueType));
	int i, qnum, y,item,sav;
	char type;
	q->front = 0;
	q->rear = 0;
	
	scanf("%d", &qnum);
	q->data = (int*)malloc(sizeof(int)*qnum);
	q->max = qnum;
	init(q);
	scanf("%d", &y);
	

	for (i = 0; i < y; i++) {
		getchar();
		scanf("%c", &type);
		switch (type) {
		case 'I':scanf("%d", &item); sav = enqueue(q, item); if (sav)return 0; break;
		case 'D':sav = dequeue(q); if (sav) return 0; break;
		case 'P':print(q); break;
		}

	}
	free(q);



}