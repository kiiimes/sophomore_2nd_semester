#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int num;
	struct ListNode *link;
}ListNode;

typedef struct ListType {
	ListNode *head;
	int length;
}ListType;

void init(ListType *list) {
	list->head = NULL;
	list->length = 0;
}

ListNode* get_node(int item) {
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));
	p->num = item;
	p->link = NULL;
	return p;
}

ListNode* get_node_at(ListType* list) {
	ListNode* p = list->head;

	while (p != NULL) {
		p = p->link;
	}
	return p;

}

void add(ListNode *head, int item) {
 	ListNode *p = head;
	ListNode *New = get_node(item);

	if (p == NULL) {
		p = New;
	}
	else {
		while (p != NULL) {
			p = p->link;
		}
		p = New;
	}
	
}

ListNode* subset(ListType* alist, ListType* blist) {
	ListNode *pa = alist->head;
	ListNode *pb = blist->head;
	int cnt = 0;

	if (alist->length > blist->length) {
		while (pb->link != NULL) {
			if (pb == pa) {
				pb = pb->link;
				cnt++;
			}
			pa = pa->link;
		}
	}


}

void main() {
	int asize, bsize, i, j, item;

	ListNode* ahead=NULL;
	ListNode* bhead=NULL;

	scanf("%d", &asize);	
	for (i = 0; i < asize; i++) {
		scanf("%d", &item);
		add(ahead, item);
	}

	scanf("%d", &bsize);
	for (i = 0; i < bsize; i++) {
		scanf("%d", &item);
		add(bhead, item);
	}


}