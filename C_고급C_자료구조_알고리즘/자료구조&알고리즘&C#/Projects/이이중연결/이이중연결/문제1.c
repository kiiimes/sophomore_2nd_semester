#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//������ tail ��� ���� ���� �Ƚ��ѳ��� 

typedef struct ListNode {
	char data;
	struct ListNode* llink;
	struct ListNode* rlink;
}ListNode;

typedef struct ListType {
	ListNode *head;
	ListNode *tail;
	int length;
}ListType;

ListNode* get_node(char pdata) {
	ListNode* p;
	p = (ListNode*)malloc(sizeof(ListNode));
	p->data = pdata;
	p->llink = NULL;
	p->rlink = NULL;
	return p;
}//������ ��忡 �����Ҵ�

ListType *init(ListType *list) {
	list->head = get_node(NULL);
	list->tail = get_node(NULL);
	list->head->llink = NULL;
	list->tail->rlink = NULL;
	list->head->data = NULL;
	list->tail->data = NULL;
	list->head->rlink = list->tail;
	list->tail->llink = list->head;
	list->length = 0;
	return list;
}//init �ʱ�ȭ ���� ���Ͽ� �����Ҵ� ���ְ� �� �ʱ�ȭ ���ְ� ���θ� �����Ŵ
//list�� ���̴� 0

ListNode* get_node_at(ListType *list, int pos) {
	int i;
	ListNode *p;// Ž���ϴ� �����ʹ� ���� �����Ҵ� x
	p = list->head;
	
	/*if (pos<=0||pos>=list->length + 1) {
		return;
	}*/
	for (i = 1; i <= pos; i++) {
		p = p->rlink;
	}
	
	return p;
}


char get_entry(ListType *list, int pos) {
	if (pos<=0||pos>list->length) {
		return 1;
	}
	else {
		ListNode *p ;
		p = get_node_at(list, pos);
		return p->data;
	}
}//get_entry(list,position) �Լ�



void add(ListType *list, int pos, char item) {
	if (pos>0&&pos <= list->length + 1) {
		ListNode *p ;
		ListNode *new = get_node(item);
		p = get_node_at(list, pos - 1);
		new->llink = p;
		new->rlink = p->rlink;
		p->rlink = new;
		new->rlink->llink = new;
		list->length++;
	}
	else {
		printf("invalid position\n");
	}
}//add(list, position, item) �Լ�

void delete(ListType *list, int pos) {
	if (pos>0&&pos <= list->length) {
		ListNode *p;
		p = get_node_at(list, pos);
		p->llink->rlink = p->rlink;
		p->rlink->llink = p->llink;
		list->length--;
		free(p);
	}
	else {
		printf("invalid position\n");
	}
}//delete (list,pos) �Լ�

void print(ListType* list) {
	int i;
	ListNode* phead ;
	phead = list->head->rlink;
	if (list->length == 0) {
	}
	else {
		while (phead != list->tail) {
			printf("%c", phead->data);
			phead = phead->rlink;
		}
		printf("\n");
	}
}

void freedom(ListType* list) {
	ListNode *p;
	ListNode *sav;
	p = list->head->rlink;

	while (p != list->tail) {
		sav = p->rlink;
		free(p);
		p = sav;
	}

	free(list->head);
	free(list->tail);
}

void main() {
	int n, i, position;
	char type = { '\0' }, item;
	ListType *list = (ListType*)malloc(sizeof(ListType));
	list=init(list);

	//���� Ʈ���Ϸ� �ʿ�
	scanf("%d", &n);//���� ����
	getchar();

	for (i = 0; i < n; i++) {
		scanf("%c", &type);
		getchar();

		switch (type) {
		case 'A':scanf("%d %c", &position, &item); getchar(); add(list, position, item); break;
		case 'D':scanf("%d", &position); getchar(); delete(list, position); break;
		case 'G':scanf("%d", &position); getchar(); if (get_entry(list, position) == 1)printf("invalid position\n"); else printf("%c\n", get_entry(list, position)); break;
		case 'P':print(list);  break;
		default:;
		}
		
		//free �ʿ��� �����¡ 
	}
	freedom(list);
	free(list);


}