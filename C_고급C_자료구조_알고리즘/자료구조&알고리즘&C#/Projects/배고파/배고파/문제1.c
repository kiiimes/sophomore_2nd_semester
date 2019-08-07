#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int data;
	struct ListNode* link;
}ListNode;



ListNode* get_node(int item) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = item;
	p->link = NULL;
	return p;
}

ListNode* get_node_at(ListNode* head) {
	ListNode *p = head;
	ListNode *b=head;
	while (p != NULL) {
		b = p;
		p = p->link;
	}
	return b;
}

int listnum(ListNode* head) {
	ListNode *p = head;
	int count = 0;
	while (p != NULL) {
		count++;
		p = p->link;
	}
	return count;
}


void add(ListNode** head, ListNode *p, ListNode *new_node) {

	if (*head==NULL) {
		new_node->link = NULL;
		*head = new_node;
	}
	else {
		p->link = new_node;
		new_node->link = NULL;
	}
}

int member(ListNode *ahead, ListNode *bhead) {
	int sav;
	ListNode *tmp = bhead;
	
	int cnt = 0;
	while (bhead != NULL && ahead != NULL) {
		if (ahead->data==bhead->data) {
			bhead = bhead->link;
			cnt++;
		}
		else {
			sav = bhead->data;
		}
		ahead = ahead->link;
	}


	if (cnt==listnum(tmp)) {
		return 0;
	}
	else {
		return sav;
	}
}

int subset(ListNode* ahead, ListNode* bhead) {
	int alength = listnum(ahead);
	int blength = listnum(bhead);
	int sav;

	if (alength > blength) {
		sav=member(ahead, bhead);
	}
	else if (alength == blength) {
		sav = member(ahead, bhead);
	}
	else {
		sav=member(bhead, ahead);
	}

	return sav;
	//alength>blength
	//alength==blength
	//alength<blength

}

void freedom(ListNode* head) {
	ListNode* sav;

	while (head != NULL) {
		sav = head->link;
		free(head);
		head = sav;
	}

}

void main() {
	ListNode *ahead=NULL;
	ListNode *bhead=NULL;
	ListNode *New;
	ListNode *p=NULL ;

	int item;
	int asize, bsize,i;


	scanf("%d", &asize);
	for (i = 0; i < asize; i++) {
		scanf("%d", &item);
		New = get_node(item);
		p = get_node_at(ahead);
		add(&ahead,p,New);
	}

	scanf("%d", &bsize);
	for (i = 0; i < bsize; i++) {
		scanf("%d", &item);
		New = get_node(item);
		p = get_node_at(bhead);
		add(&bhead, p,New);
	}

	printf("%d", subset(ahead, bhead));

	freedom(ahead);
	freedom(bhead);

}