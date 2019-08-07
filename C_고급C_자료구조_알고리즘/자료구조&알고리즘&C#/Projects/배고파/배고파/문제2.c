#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int data;
	struct ListNode* link;
}ListNode;

typedef struct ListType {
	ListNode* head;
}ListType;

ListNode* get_node(int item) {
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));
	p->data = item;
	p->link = NULL;
	return p;
}

void add(ListType* list, int item) {
	ListNode* New = get_node(item);
	ListNode* p = list->head;

	if (p->link == NULL) {
		p->link = New;
	}
	else {
		while (p->link != NULL) {
			p = p->link;
		}
		p->link = New;
	}
}

ListType* intersect(ListType* alist, ListType* blist) {
	ListType* sav = (ListType*)malloc(sizeof(ListType));
	ListNode* pa = alist->head->link;
	ListNode* pb = blist->head->link;
	ListNode* ps;

	sav->head = get_node(NULL);
	ps = sav->head;

	while (pa != NULL&&pb != NULL) {
		if (pa->data == pb->data) {
			
			ps->link = pa;
			ps = ps->link;
			pb = pb->link;
			pa = pa->link;
		}
		else {
			pa = pa->link;
		}
	}
	return sav;
}


ListType* uni(ListType* alist, ListType* blist)
{
	ListType* sav = (ListType*)malloc(sizeof(ListType));
	ListNode* pa = alist->head->link;
	ListNode* pb = blist->head->link;
	ListType* pint = intersect(alist, blist)->head->link;

	sav->head = get_node(NULL);


	while (pa != NULL&&pb != NULL) {
		if (pa < pb) {
			if (pa == pint) {
				add(sav, pa->data);
				pa = pa->link;
			}
			else if (pb == pint) {
				pb = pb->link;
			}
			else {
				add(sav, pa->data);
				add(sav, pb->data);
				pa = pa->link;
				pb = pb->link;
			}
		}
		else if (pa > pb) {
			if (pb == pint) {
				add(sav, pb->data);
				pb = pb->link;
			}
			else if (pa == pint) {
				pa = pa->link;
			}
			else {
				add(sav, pb->data);
				add(sav, pa->data);
				pa = pa->link;
				pb = pb->link;
			}
		}
		else {
			if (pb == pint) {
				add(sav, pb->data);
				pb = pb->link;
			}
			else if (pa == pint) {
				pa = pa->link;
			}
		}
		return sav;

	}
}
void print(ListType* list){
	ListNode *p=list->head->link;
	
	if (p == NULL) {
		printf(" 0");
	}
	else {
		while (p != NULL) {
			printf(" %d", p->data);
		}
	}

}


void main() {
	ListType *alist=(ListType*)malloc(sizeof(ListType));
	ListType *blist = (ListType*)malloc(sizeof(ListType));
	int asize, bsize, i, item;

	alist->head = get_node(NULL);
	blist->head = get_node(NULL);

	scanf("%d", &asize);
	for (i = 0; i < asize; i++) {
		scanf("%d", &item);
		add(alist, item);
	}

	scanf("%d", &bsize);
	for (i = 0; i < bsize; i++) {
		scanf("%d", &item);
		add(blist, item);
	}

	/*print(uni(alist, blist));*/
	printf("\n");
	if (asize >= bsize) {
		print(intersect(alist, blist));
	}
	else {
		print(intersect(blist, alist));
	}
	
}