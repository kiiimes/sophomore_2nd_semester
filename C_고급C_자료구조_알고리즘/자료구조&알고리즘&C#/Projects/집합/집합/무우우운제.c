#include <stdio.h>
#include <stdlib.h>
typedef struct _ListNode {
	int data;
	struct _ListNode *next;
}ListNode;


ListNode* setnum(ListNode *k, int n)
{
	ListNode *Term;
	Term = (ListNode *)malloc(sizeof(ListNode));
	Term->data = n;
	Term->next = NULL;
	k->next = Term;
	k = Term;

	return k;
}
ListNode * Union(ListNode *a, ListNode *b)
{
	ListNode *sum, *s_H;
	ListNode *tmp;
	sum = (ListNode *)malloc(sizeof(ListNode));//동적할당
	s_H = sum;

	a = a->next;
	b = b->next;
	while (a != NULL && b != NULL) {
		if (a->data < b->data) {
			tmp = (ListNode *)malloc(sizeof(ListNode));
			tmp->data = a->data;
			a = a->next;
			tmp->next = NULL;
			sum->next = tmp;
			sum = tmp;

		}
		else if (a->data == b->data) {
			tmp = (ListNode *)malloc(sizeof(ListNode));
			tmp->data = a->data;
			a = a->next;
			b = b->next;
			tmp->next = NULL;
			sum->next = tmp;
			sum = tmp;

		}
		else {
			tmp = (ListNode *)malloc(sizeof(ListNode));
			tmp->data = b->data;
			b = b->next;
			tmp->next = NULL;
			sum->next = tmp;
			sum = tmp;
		}

	}
	while (a != NULL) {
		tmp = (ListNode *)malloc(sizeof(ListNode));
		tmp->data = a->data;
		a = a->next;
		tmp->next = NULL;
		sum->next = tmp;
		sum = tmp;

	}
	while (b != NULL) {
		tmp = (ListNode *)malloc(sizeof(ListNode));
		tmp->data = b->data;
		b = b->next;
		tmp->next = NULL;
		sum->next = tmp;
		sum = tmp;
	}
	return s_H;
}

ListNode * intersect(ListNode *a, ListNode *b)
{
	ListNode *same, *s_H;
	ListNode *tmp;
	same = (ListNode *)malloc(sizeof(ListNode));
	s_H = same;
	a = a->next; b = b->next;
	while (a != NULL && b != NULL) {
		if (a->data < b->data) {
			a = a->next;
		}
		else if (a->data == b->data) {
			tmp = (ListNode *)malloc(sizeof(ListNode));
			tmp->data = a->data;
			tmp->next = NULL;
			same->next = tmp;
			same = tmp;
			a = a->next;
			b = b->next;
		}
		else {
			b = b->next;
		}

	}
	return s_H;
}

void freedom(ListNode* head) {
	ListNode* p=head;
	ListNode* sav;

	while (p != NULL) {
		/*sav = p->next;
		free(p);
		p = sav;*/

		sav = p;
		p = p->next;
		free(sav);
	}
}

int main()
{

	int Acnt, Bcnt;
	int i, n;
	ListNode *p1, *p2;
	ListNode *H1 = NULL, *H2 = NULL;
	ListNode *an1, *an2;

	p1 = (ListNode *)malloc(sizeof(ListNode));
	p2 = (ListNode *)malloc(sizeof(ListNode));
	p1->next = NULL;
	p2->next = NULL;

	H1 = p1;
	H2 = p2;

	scanf("%d", &Acnt);
	for (i = 0; i<Acnt; i++) {
		scanf("%d", &n);
		H1 = setnum(H1, n);
	}
	scanf("%d", &Bcnt);
	for (i = 0; i<Bcnt; i++) {
		scanf("%d", &n);
		H2 = setnum(H2, n);
	}
	if (Acnt != 0 || Bcnt != 0) {
		an1 = Union(p1, p2);

		an1 = an1->next;
		while (an1 != NULL) {
			printf(" %d", an1->data);
			an1 = an1->next;
		}
	}
	else
		printf(" %d", 0);

	printf("\n");
	an2 = intersect(p1, p2);

	if (Acnt != 0 && Bcnt != 0) {
		an2 = an2->next;
		while (an2 != NULL) {
			printf(" %d", an2->data);
			an2 = an2->next;
		}
	}
	else {
		printf(" %d\n", 0);
	}

	freedom(p1);
	freedom(p2);

	free(p1);
	free(p2);
}



