#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode *link;
}ListNode;//노드 구조체

ListNode* create_node(element data, ListNode* link) {
	ListNode *p;
	p = (ListNode*)malloc(sizeof(ListNode));
	p->data = data;
	p->link = link;
	return p;
}

void insert_node(ListNode **phead, ListNode *p,ListNode *new) {
	if (*phead== NULL) {
		*phead = new;
	}//phead가 null인 경우
	else if (p == NULL) {
		new->link = *phead;
		*phead = new;
	}//p가 null 인 경우 (그냥 전 노드가 없는 경우임)
	else {
		new->link = p->link;
		p->link = new;
	}//그 외 중간 암데나 끼워 놓는 경우
}

void delete_node(ListNode **phead, ListNode *p,ListNode *removed) {
	if (p == NULL) {
		*phead = removed->link;
	}
	else {
		p->link = removed->link;
	}
	free(removed);
}//삭제 함수

void display(ListNode *phead) {
	ListNode *p = phead;
	while (p!=NULL) {
		printf("%d", p->data);
		phead = phead->link;
	}
}//보여주는 함수

ListNode* search(ListNode *phead, int s) {
	ListNode *p;
	
	while (p->link != NULL) {
		if (p->data == s) {
			return p;
		}
		p = p->link;
	}
	return p;
}

ListNode* concat(ListNode *ahead, ListNode *bhead) {
	ListNode *p = ahead;
	if (ahead == NULL) {
		return bhead;
	}
	else if (bhead == NULL) {
		return ahead;
	}
	else {
		while (p->link!=NULL) {
			p = p->link;
		}
		p->link = bhead;
		return p;
	}
}








int main() {
	ListNode* head;



	return 0;
}