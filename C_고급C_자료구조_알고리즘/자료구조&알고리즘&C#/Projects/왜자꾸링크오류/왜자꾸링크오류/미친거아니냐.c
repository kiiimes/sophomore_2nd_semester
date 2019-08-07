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

ListType* addpoly(ListType* alist, ListType* blist) {
	ListType* result = (ListType*)malloc(sizeof(ListType));
	init(result);
	ListNode *ap, *bp, *rehead;
	int sum;
	ap = alist->head->link;
	bp = blist->head->link;
	rehead = result->head;

	while (ap!=NULL&&bp!=NULL) {

			if (ap->exp > bp->exp) {
				rehead = add(rehead,ap->coef, ap->exp);
				result->length++;
				ap = ap->link;
			}
			else if (bp->exp > ap->exp) {
				rehead = add(rehead,bp->coef, bp->exp);
				result->length++;
				bp = bp->link;
			}
			else {
				sum = ap->coef + bp->coef;
				if (sum != 0) {
					rehead = add(rehead,sum, ap->exp);
					result->length++;
				}
				sum = 0;
				ap = ap->link;
				bp = bp->link;
			}
		}
	while (bp != NULL) {
		rehead = add(rehead,bp->coef, bp->exp);
		result->length++;
		bp = bp->link;
	}
	while (ap != NULL) {
		rehead = add(rehead,ap->coef, ap->exp);
		result->length++;
		ap = ap->link;
	}	
	return result;
}
void freedom(ListType* list) {
	ListNode* p=list->head;
	ListNode* sav;
	while (p->link != NULL) {
		sav = p->link;
		free(p);
		p = sav;
	}
	free(p);
}


void main() {
	int n1, n2, i, c, e;
	ListNode* ka;
	ListNode* kb;
	ListNode* reprint;
	ListType* alist = (ListType*)malloc(sizeof(ListType));
	ListType* blist = (ListType*)malloc(sizeof(ListType));
	ListType* rresult = (ListType*)malloc(sizeof(ListType));
	init(rresult);
	init(alist);
	init(blist);

	ka = get_node_at(alist);
	kb = get_node_at(blist);

	scanf("%d", &n1);

	for (i = 0; i < n1; i++) {
		scanf("%d %d", &c, &e);
		ka = add(ka, c, e);
		alist->length++;
	}
	//첫번째 다항식 개수

	scanf("%d", &n2);

	for (i = 0; i < n2; i++) {
		scanf("%d %d", &c, &e);
		kb = add(kb, c, e);
		blist->length++;
	}

	rresult = addpoly(alist, blist);
	reprint = rresult->head->link;

	while (reprint != NULL) {
		printf(" %d %d", reprint->coef, reprint->exp);
		reprint = reprint->link;
	}
	//두번째 다항식 개수

	freedom(alist);
	free(alist);
	freedom(blist);
	free(blist);
	freedom(rresult);
	free(rresult);

}