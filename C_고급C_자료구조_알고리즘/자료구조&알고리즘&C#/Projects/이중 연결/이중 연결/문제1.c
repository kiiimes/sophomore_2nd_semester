#include <stdio.h>
#include <stdlib.h>
//헤드노드랑 tail 노드 아직 연결 안시켜놓음 

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

ListNode* get_node(char pdata) {
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
}//init 초기화

ListNode* get_node_at(ListType *list, int pos) {
	int i;
	ListNode *p = get_node(NULL);
	p = list->head;
	
	if (pos < 0&&pos>list->length+1) {
		printf("invalid position");
		return;
	}

	for (i = 0; i < pos; i++) {
		p = p->rlink;
	}
	return p;
}


ListNode* get_entry(ListType *list, int pos) {
	if (pos<0 || pos>list->length) {
		printf("invalid postion");
		return;
	}
	else {
		ListNode *p = get_node(NULL);
		p=get_node_at(list, pos);
		return p->data;
	}
}//get_entry(list,position) 함수



void add(ListType *list, int pos, char item) {
	if (pos > 0 && pos <= list->length + 1) {
		ListNode *p = get_Node(NULL);
		ListNode *new = get_Node(item);
		p = get_node_at(list, pos - 1);
		new->llink = p;
		new->rlink = new->llink->rlink;
		p->rlink = new;
		new->rlink->llink = new;
		list->length++;
	}
	else {
		printf("invalid position");
	}
}//add(list, position, item) 함수

void delete(ListType *list, int pos) {
	if (pos > 0 && pos <= list->length) {
		ListNode *p = get_node(NULL);
		p = get_node_at(list, pos);
		p->llink->rlink = p->rlink;
		p->rlink->llink = p->llink;
		list->length--;
		free(p);
	}
	else {
		printf("invalid position\n");
	}
}//delete (list,pos) 함수

void print(ListType* list) {
	ListNode* phead = get_node(NULL);
	phead = list->head->rlink;
	while (phead!= list->tail) {
		printf("%c", phead->data);
		phead = phead->rlink;
	}
}

void main() {
	int n, i, position;
	char type = { '\0' }, item;
	ListType *list = (ListType*)malloc(sizeof(ListType));
	init(list);
	list->length = 0;

	//헤드랑 트레일러 필요
	scanf("%d", &n);//연산 개수
	getchar();

	for (i = 0; i < n; i++) {
		scanf("%c", &type);

		switch (type) {
		case 'A':getchar(); scanf("%d %c", &position,&item); getchar(); add(list, position, item); break;
		case 'D':getchar(); scanf("%d", &position); getchar(); delete(list, position); break;
		case 'G':getchar(); scanf("%d", &position); getchar(); printf("%c\n", get_entry(list, position)); break;
		case 'P':print(list); break;
		default:;
		}

	}


}