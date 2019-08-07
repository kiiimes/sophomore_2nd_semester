#include <stdio.h>
#include <stdlib.h>
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

 ListNode* get_node(char pdata){
	 ListNode* p;
	 p = (ListNode*)malloc(sizeof(ListNode));
	 p->data = pdata;
	 return p;
}
 void *init(ListType *list) {
	list->head = get_node(NULL);
	list->tail = get_node(NULL);
	list->head->rlink = list->tail;
	list->tail->llink = list->head;
 }//init �ʱ�ȭ 


ListNode* get_entry(ListType *list, int pos) {
	if (pos<0 || pos>list->length) {
		printf("invalid postion");
		return;
	}
	else {
		int i;
		ListNode *p=get_node(NULL);
		p = list->head;
		for (i = 0; i <= pos; i++) {
			p = p->rlink;
		}
		return p;
	}
}//get_entry(list,position) �Լ�



void add(ListType *list, int pos, char item) {

	if (pos >= 0 && pos < list->length) {
		ListNode *new;
		ListNode *p;
		new = get_node(item);
		p = get_node(NULL);
		p = get_entry(list, pos);
		new->rlink = p;
		new->rlink = new->llink->rlink;
		p->rlink = new;
		new->rlink->llink = new;
		list->length++;
	}
	else {
		printf("invalid position");
	}
}//add(list, position, item) �Լ�
void delete(ListType *list,int pos) {
	if (pos >= 0 && pos < list->length) {
		ListNode *p = get_node(NULL);
		char pdata;
		p=get_entry(list, pos);
		p->llink->rlink = p->rlink;
		p->rlink->llink = p->llink;
		list->length--;
		pdata = p->data;
		free(p);
	}
	else {
		printf("invalid position");
	}
}//remove (list,remove) �Լ�

void print(ListType* list) {
	ListNode* phead = get_node(NULL);
	phead = list->head->rlink;
	while (phead->rlink !=list->tail) {
		printf("%c", phead);
		phead = phead->rlink;
	}
}

void main() {
	int n,i,position;
	char type,item;
	ListType *list = (ListType*)malloc(sizeof(ListType));
	init(list);
	
	//���� Ʈ���Ϸ� �ʿ�
	scanf("%d", &n);//���� ����

	for (i = 0; i < n; i++) {
		scanf("%c", &type);

		switch (type) {
		case 'A':scanf("%d %c", &position, &item); add(list,position, item); break;
		case 'D':scanf("%d", &position); delete(list,position); break;
		case 'G':scanf("%d", &position); printf("%c", get_entry(list, position)); break;
		default:;
		}
	}


}