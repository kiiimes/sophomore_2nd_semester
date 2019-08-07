#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;//��� ������
	struct ListNode* link;//���� ����� �ּ�
}ListNode;

ListNode *create_node(element data, ListNode* link) {
	ListNode* list;

	list = (ListNode*)malloc(sizeof(ListNode));

	list->data = data;
	list->link = link;

	return list;
	
}//��� ���� �Լ�

void insert_node(ListNode **phead, ListNode *p, ListNode *New) {
	int i;
	if (*phead == NULL) {
		*phead = New;
		New->link = NULL;
		return ;
	}
	
	else if (p == NULL) {
		New->link = *phead;
		phead = New;
	}

	else {
		New->link = p->link;
		p->link = New;
	}
}//��� �߰� �Լ�

void remove_node(ListNode **phead, ListNode *p, ListNode *now) {
	//p�� null �ΰ��� �߰� ��� �����ϴ� ��� ����� �����ϴ� ���
	if (p == NULL) {
		*phead = now->link;
		
	}
	else if (now->link == NULL) {
		p->link = NULL;
		
	}
	else {
		p->link = now->link;
	}
	free(now);
	now->link = NULL;

}//���� �Լ�

void display(ListNode *head) {
	ListNode *p;

	p = head;

	while (p->link != NULL) {
		printf("%d->", p->data);
		p = p->link;
	}
	printf("NULL");

}//�����ִ� �Լ�
//���⼭�� head�� ���� ���������� �� �ʿ� ���� �ֳĸ� ��尡 �ٲ� ���� ���� ����

ListNode* search(ListNode *head,ListNode *p) {//p�� ã������ ���
	
	while (head != NULL) {
		if (p == head) {
			return head;
		}
		head = head->link;
	}
}

void main() {
	ListNode *list1 = NULL, *list2 = NULL;
	ListNode *p;

		insert_node(&list1, create_node(30, NULL));
		insert_node(&list1, create_node(20, NULL));
	





}