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

ListNode* addpoly(ListType* alist, ListType* blist) {
	ListType* result = (ListType*)malloc(sizeof(ListType));
	init(result);
	ListNode *ap, *bp, *rehead;
	ap = alist->head;
	bp = blist->head;
	rehead = result->head->link;

	while (1) {
		if (ap->link == NULL) {
			if (bp->link == NULL) {
				break;
			}
			else {
				while (bp->link != NULL) {
					rehead->link = bp;
					bp = bp->link;
				}
			}//ap->link==NULL인경우
		}
		else if (bp->link == NULL) {
			if (ap->link == NULL) {
				break;
			}
			else {
				while (ap->link != NULL) {
					rehead->link = ap;
					ap = ap->link;
				}
			}
		}//bp->link==NULL인경우
		else {
			if (ap->exp > bp->exp) {
				rehead = get_node(ap->coef, ap->exp);
			}
			else if (bp->exp > ap->exp) {
				rehead = get_node(bp->coef, bp->exp);
			}
			else {
				rehead = get_node(ap->coef + bp->coef, ap->exp);
			}
			ap = ap->link;
			bp = bp->link;
			rehead = rehead->link;

		}
		return result->head;

	}
}


void main() {
	int n1, n2, i, c, e;
	ListNode* ka;
	ListNode* kb;
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

	rresult->head=addpoly(alist, blist);
	printf("%d %d", rresult->head->link->coef, rresult->head->link->exp);
	
	//두번째 다항식 개수
	


}