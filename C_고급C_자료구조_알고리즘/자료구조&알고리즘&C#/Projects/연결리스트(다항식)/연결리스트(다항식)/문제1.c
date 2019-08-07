#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int coef;
	int exp;
	struct ListNode* link;
}ListNode;

typedef struct ListType {
	ListNode* head;
	int length;
}ListType;

ListNode* getnode(char coef,char exp) {
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));
	p->coef = coef;
	p->exp = exp;
	p->link = NULL;
	return p;
}
ListNode* init(ListType* list) {
	list->head->coef = NULL;
	list->head->exp = NULL;
	list->head->link = NULL;
	list->length = 0;
}
ListType* addpoly(ListType* alist, ListType* blist) {
	ListType* result = (ListType*)malloc(sizeof(ListType));
	ListNode* k;
	ListNode *a=alist->head, *b=blist->head;
	int sum;
	init(result);
	k = result->head;
	if (a->exp > b->exp) {
		k = add(k, a->coef, a->exp);
		a = a->link;
	}
	else if (b->exp > a->exp) {
		k = add(k, b->coef, b->exp);
		b = b->link;
	}
	else {
		sum = a->coef + b->coef;
		if (sum != 0) {
			k = add(k, sum, a->exp);
			a = a->link;
			b = b->link;
		}
	}
	return result;
}

ListNode* add(ListNode* k, char coef, char exp) {
	ListNode *new = getnode(coef, exp);
	k->link = new;
	k = new;
	return k;
}

void main() {
	ListType* alist = (ListType*)malloc(sizeof(ListType));
	ListType* blist = (ListType*)malloc(sizeof(ListType));
	ListType* sav = (ListType*)malloc(sizeof(ListType));
	ListNode* ka;
	ListNode* kb;
	int anum, bnum,i,num1,num2;
	init(alist);
	init(blist);

	ka = alist->head;
	kb = blist->head;

	scanf("%d", &anum);

	for (i = 0; i < anum; i++) {
		scanf("%d %d", &num1, &num2);
		ka = add(ka, num1, num2);
		alist->length++;
	}

	scanf("%d", &bnum);

	for (i = 0; i < bnum; i++) {
		scanf("%d %d", &num1, &num2);
		kb = add(kb, num1, num2);
		blist->length++;
	}

	sav = addpoly(alist, blist);
	sav = sav->head;

	while (sav!= NULL) {
		printf(" %d", sav->head->link->coef);
		sav = sav->link;
	}

}