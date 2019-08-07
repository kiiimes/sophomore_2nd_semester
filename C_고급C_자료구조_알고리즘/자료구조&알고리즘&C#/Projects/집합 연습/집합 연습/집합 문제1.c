#include <stdio.h>

typedef struct ListNode {
	int data;
	struct ListNode* link;
}ListNode;

typedef struct ListType {
	ListNode *head;
	int asize, bsize;
}ListType;

ListNode* create_node(int item) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = item;
	p->link = NULL;
}

int is_empty(ListType *list) {
	if (list->head == NULL) return 0;
	return 1;
}

ListNode* get_node_at(ListType *list) {
	int i;
	ListNode *p;
	p = list->head;

	while (p->link != NULL) {
		p = p->link;
	}
	return p;
}

void insert(ListType *list,int item) {
	ListNode *new = create_node(item);
	ListNode *p;
	if (list->head == NULL) {
		list->head = new;
	}
	else {
		p= get_node_at(list);
		p->link = new;
	}
}

int member(ListType *list) {
	if (is_empty(list)) {
		return 0;
	}
}

void main() {
	ListType *a, *b;
	a = (ListType*)malloc(sizeof(ListType));
	b = (ListType*)malloc(sizeof(ListType));
	a->head = NULL;
	b->head = NULL;
	int i,item;

	scanf("%d", &(a->asize));

	for (i = 0; i < a->asize; i++) {
		scanf("%d", &item);
		insert(a, item);
		
	}
	scanf("%d", &(b->bsize));

	for (i = 0; i < b->bsize; i++) {
		scanf("%d", &item);
		insert(b, item);
	}

	printf("%d", subset(a, b));

}