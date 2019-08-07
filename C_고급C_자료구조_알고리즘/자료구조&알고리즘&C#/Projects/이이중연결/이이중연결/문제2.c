#include <stdio.h>
#include <stdlib.h>
//단일 연결 리스트

typedef struct ListNode {
	int coef;
	int exp;
	struct ListNode* link;
}ListNode;

typedef struct ListType {
	ListNode* head;
	int length;
}ListType;

ListNode* get_node(int citem, int eitem) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->link = NULL;
	p->coef = citem;
	p->exp = eitem;
	return p;
}//동적할당 함수 

void init(ListType *list) {
	list->head = get_node(NULL, NULL);
	list->length = 0;
}//head 초기화 시킨 함수

ListNode* get_node_at(ListType *list) {
	ListNode *p = list->head;
	while (p->link != NULL) {
		p = p->link;
	}
	return p;
}

ListNode* add(ListNode* k, int citem, int eitem) {
	ListNode* new = get_node(citem, eitem);
	k->link = new;
	k = new;
	return k;
}

void main() {
	int n1, n2, i, c, e;
	ListNode* k;
	ListType* list = (ListType*)malloc(sizeof(ListType));
	init(list);
	k = get_node_at(list);

	scanf("%d", &n1);

	for (i = 0; i < n1; i++) {
		scanf("%d %d", &c, &e);
		k = add(k, c, e);
	}
	printf("%d %d", list->head->link->coef, list->head->link->exp);





	//add 함수 쓸때 넘겨줘야하는거는 그 마지막 노드
	//첫번째 다항식 개수
	/*scanf("%d", n2);

	for (i = 0; i < n2; i++) {

	}
	//두번째 다항식 개수
	*/


}