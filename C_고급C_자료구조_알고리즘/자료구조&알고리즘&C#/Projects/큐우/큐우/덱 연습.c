#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DlistNode {
	int data;
	struct DlistNode *llink, *rlink;
}DlistNode;

typedef struct DequeType {
	DlistNode *head;
	DlistNode *tail;
}DequeType;

int is_empty(DequeType *dq) {
	if (dq->head ==NULL) {
		return 1;
	}
	return 0;
}

DlistNode* create_node(DlistNode *llink, int item, DlistNode *rlink) {
	DlistNode *p = (DlistNode*)malloc(sizeof(DlistNode));
	p->data = item;
	p->llink = llink;
	p->rlink = rlink;
	return p;
}

void add_front(DequeType *dq, int item) {
	DlistNode *new = create_node(NULL, item, dq->head);
	if (is_empty(dq)) {
		dq->tail = new;
	}
	else {
		dq->head->llink = new;
	}
	dq->head = new;
}

void add_rear(DequeType *dq, int item) {
	DlistNode *new = create_node(dq->tail, item, NULL);
	if (is_empty(dq)) {
		dq->head = new;
	}
	else {
		dq->tail->rlink = new;
	}
	dq->tail = new;
}

int delete_front(DequeType *dq) {
	DlistNode *p;
	int sav;
	if (is_empty(dq)) {
		printf("underflow");
		return 0;
	}
	else {
		p= dq->head;
		sav = p->data;
		dq->head = dq->head->rlink;
		free(p);
		if (dq->head == NULL) {
			dq->tail = NULL;
		}
		else {
			dq->head->llink = NULL;
		}
	}
	return sav;
}

int delete_rear(DequeType *dq) {
	DlistNode *p;
	int sav;
	if (is_empty(dq)) {
		printf("underflow");
		return 0;
	}
	else {
		p = dq->tail;
		sav = p->data;
		dq->tail = dq->tail->llink;
		free(p);
		if (dq->tail == NULL) {
			dq->head = NULL;
		}
		else {
			dq->tail->rlink = NULL;
		}
	}
	return sav;
}

int print(DequeType *dq) {
	DlistNode *p = dq->head;
	if (is_empty(dq)) {
		return 0;
	}
	while (p != dq->tail) {
		printf(" %d", p->data);
		p = p->rlink;
	}
	printf(" %d", dq->tail->data);
	printf("\n");
}


int main() {
	DequeType *dq = (DequeType*)malloc(sizeof(DequeType));
	int i,n,item,sav;
	char type[3];
	dq->head = NULL;
	dq->tail = NULL;


	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		getchar();

		scanf("%s", type);
		if (strcmp(type, "AF") == 0) {
			scanf("%d", &item);
			add_front(dq, item);
		}
		else if (strcmp(type, "AR") == 0) {
			scanf("%d", &item);
			add_rear(dq,item);
		}
		else if (strcmp(type, "DF") == 0) {
			sav=delete_front(dq);
			if (sav == 0) {
				return 0;
			}
		}
		else if (strcmp(type, "DR") == 0) {
			sav = delete_rear(dq);
			if (sav == 0) {
				return 0;
			}
		}
		else if (strcmp(type, "P") == 0) {
			print(dq);
		}
	}
	free(dq);
}