#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int data;
	struct ListNode *link;
}ListNode;

typedef struct ListType {
	ListNode *head;
}ListType;

void init(ListType* list) {
	list->head = NULL;
}

ListNode* getNode(int item) {
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));

	p->data = item;
	p->link = NULL;

	return p;
}

void insertNode(ListType* list, int item) {
	ListNode *p = list->head;
	ListNode *New = getNode(item);

	if (p == NULL) {
		list->head = New;
	}

	else {
		while (p->link != NULL) {
			p = p->link;
		}

		p->link = New;
	}

}

void printNode(ListType *list) {
	ListNode *p = list->head;

	while (p->link != NULL) {
		printf(" %d", p->data);
		p = p->link;
	}
	printf(" %d", p->data);
}

void freedom(ListType* list) {
	ListNode *sav = list->head;
	while (list->head != NULL) {
		list->head = list->head->link;
		free(sav);
		sav = list->head;
	}
}

ListNode* partition(ListType* list, int n) {
	int i;
	ListNode *p = list->head;
	ListNode *sav;


	for (i = 0; i < n - 1; i++) {
		list->head = list->head->link;
	}

	sav = list->head->link;
	list->head->link = NULL;
	list->head = p;

	return sav;
}

int size(ListType* list) {
	ListNode* p = list->head;
	int count = 0;

	while (p != NULL) {
		count++;
		p = p->link;
	}

	return count;
}

ListNode* merge(ListType *a, ListType *b) {
	ListNode *pa = a->head, *pb = b->head, *prev, *sav;

	if (pa->link == NULL&&pb->link == NULL) {
		if (pa->data > pb->data) {
			pb->link = pa;
			return pb;
		}
		pa->link = pb;
		return pa;
	}
	else {
		while (pa != NULL&&pb != NULL) {
			if (pa->data < pb->data) {
				prev = pa;
				pa = pa->link;
			}
			else {
				if (pa == a->head) {
					sav = pa;
					pa = pb;
					pb = pb->link;
					pa->link = sav;
				}
				else {
					sav = pb->link;
					pb->link = pa;
					prev->link = pb;
					pb = sav;
					prev = prev->link;
				}
			}
		}
	}

	while (pa != NULL) {
		pa = pa->link;
	}

	if (pb != NULL) {
		pa = pb;
	}

	return a->head;
}


void mergeSort(ListType* list) {
	ListType *b;
	ListNode *p;
	b = (ListType*)malloc(sizeof(ListType));

	int n = size(list);


	if (n > 1) {
		b->head = partition(list, n / 2);
		mergeSort(list);
		mergeSort(b);
		p= merge(list, b);
	}

}

void print(ListType *list) {
	ListNode *p = list->head;

	while (p != NULL) {
		printf(" %d", p->data);
		p = p->link;
	}
}

void main() {
	ListType *list;
	int n, i, num;

	list = (ListType*)malloc(sizeof(ListType));

	scanf("%d", &n);

	init(list);

	for (i = 0; i < n; i++) {
		scanf("%d", &num);
		insertNode(list, num);
	}

	mergeSort(list);

	print(list);

	freedom(list);

}