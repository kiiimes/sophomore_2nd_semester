#include <stdio.h>
#include <stdlib.h>

typedef struct _ListNode {
	int data;
	struct _ListNode *next;
}ListNode;

ListNode* getNode() {
	ListNode *tmp = NULL;
	tmp = (ListNode *)malloc(sizeof(ListNode));
	tmp->next = NULL;
}

void *setnum(ListNode ** line, ListNode **f, int data) {

	ListNode *tmp;
	tmp = getNode();
	tmp->data = data;
	if (*line == NULL) {
		*line = tmp; *f = *line;
	}
	
	else {
		(*line)->next = tmp;
		*line = tmp;
	}
}
int subset(ListNode *a, ListNode *b) {

	while (a != NULL && b != NULL) {
		if (a->data > b->data)
			b = b->next;
		else if (a->data == b->data) {
			a = a->next;
			b = b->next;
		}
		else
			b = b->next;
	}
	while (a == NULL && b == NULL)
		return 0;
	while (a != NULL) {
		return a->data;
	}
	while (b != NULL) {
		return 0;
	}
}

void freedom(ListNode* head) {
	ListNode* p=head;

	while (p != NULL) {
		free(p);
		p = p->next;
	}

	
}

int main()
{
	int Acnt, Bcnt;
	int i, j;
	int N, ans;
	ListNode *Ha = NULL, *Hb = NULL;
	ListNode *A = NULL, *B = NULL;
	scanf("%d", &Acnt);
	for (i = 0; i<Acnt; i++) {
		scanf("%d", &N);
		setnum(&A, &Ha, N);
	}

	scanf("%d", &Bcnt);
	for (i = 0; i<Bcnt; i++) {
		scanf("%d", &N);
		setnum(&B, &Hb, N);
	}

	ans = subset(Ha, Hb);
	printf("%d", ans);

	freedom(Ha);
	freedom(Hb);
}