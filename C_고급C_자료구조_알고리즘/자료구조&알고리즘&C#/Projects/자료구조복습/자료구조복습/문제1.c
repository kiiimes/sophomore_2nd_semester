#include <stdio.h>

typedef struct ListNode {
	char item;
	struct ListNode* llink;
	struct ListNode* rlink;
}ListNode;

typedef struct ListType {
	ListNode* head;
	ListNode* tail;
}ListType;

ListNode* get_node(char item) {
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));
	p->llink = NULL;
	p->rlink = NULL;
	p->item = item;
	return p;
}

void init(ListType *list) {
	list->head = get_node(NULL);
	list->tail = get_node(NULL);
}

ListNode* get_node_at(ListType *list,int num) {
	ListNode *p = list->head;
	int i;
	for (i = 0; i < num; i++) {
		p = p->llink;
	}
	return p;
}

ListNode* add(ListType* list, int pos, char item) {
	ListNode* p = list->head;
	
}

void main() {
	ListType *list = (ListType*)malloc(sizeof(ListType));
	int n,i,pos;
	char type, str;
	
	scanf("%d", &n);
	getchar();

	for (i = 0; i < n; i++) {
		scanf("%c", &type);
		switch (type) {
		case 'A':scanf("%d %c", &pos, &str); add(list, pos, str); break;
		case 'D':scanf("%d", &pos); del(list, pos); break;
		case 'G':scanf("%d", &pos); get_entry(list, pos); break;
		case 'P':print(list); break;
		}
		getchar();

	}



}