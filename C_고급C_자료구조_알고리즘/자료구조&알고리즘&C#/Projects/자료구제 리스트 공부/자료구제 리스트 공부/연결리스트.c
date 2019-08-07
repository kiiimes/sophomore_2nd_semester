#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;//노드구조체 선언

typedef struct ListType {
	ListNode *head;
	int length;
}ListType;//헤드 껍데기 만들음

is_empty(ListType *list) {
	if (list == NULL) {
		return 1;
	}
	return 0;
}

int get_length(ListType *list) {
	return list->length;
}

ListNode* get_node_at(ListType *list, int pos) {
	int i;
	ListNode* tmp = list->head;


	for (i = 0; i < pos; i++) {
		if (i == pos) {
			tmp=tmp->link;
		}
	}
	return tmp;
}//리스트 안에서 pos 위치의 노드를 반환한다.

void insert_node(ListType *phead, ListNode *p, ListNode *new) {
	if (phead == NULL)
		phead = new;
	else if (p == NULL) {
		new->link = phead;
		phead = new;
	}
	else {
		new->link = p->link;
		p->link = new;
	}
}


void add(ListType *list, int pos, element data) {
	ListType list1;
	init(&list1);
}




















