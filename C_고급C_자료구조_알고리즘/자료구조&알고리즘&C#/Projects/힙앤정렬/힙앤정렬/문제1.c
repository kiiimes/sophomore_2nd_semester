#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	char item;
	struct ListNode *llink, *rlink;
}ListNode;

typedef struct ListType {
	ListNode *head;
	ListNode *tail;
	int length;
}ListType;

ListNode* get_node(char data) {
	ListNode *p;
	p = (ListNode*)malloc(sizeof(ListNode));
	p->item = data;
	p->llink = NULL;
	p->rlink = NULL;
	return p;
}

ListType* init(ListType* list) {
	list->head = get_node(NULL);
	list->tail = get_node(NULL);
	list->head->rlink = list->tail;
	list->tail->llink = list->head;
}

ListNode* ins_order(ListType *list,int pos) {
	ListNode *p = list ->head;
	int cnt=1;
	if (p->rlink == list->tail) {
		return p;
	}

	while (cnt!=pos) {
		p = p->rlink;
		cnt++;
	}
	return p;
}

int print(ListType* list) {
	ListNode* p=list->head;
	if (p->rlink == list->tail) {
		return 0;
	}

	while (p->rlink != list->tail) {
		p = p->rlink;
		printf("%c", p->item);
	}

}

void add(ListType* list, int pos, char data) {
	ListNode *New = get_node(data);
	ListNode *p=ins_order(list, pos);

	New->rlink = p->rlink;
	p->rlink = New;
	New->llink = p;
	New->rlink->llink = New;
	list->length++;
	
}

char get_entry(ListType* list, int pos) {
	ListNode* p;
	p = ins_order(list, pos);
	return p->rlink->item;
}

ListNode* del_order(ListType *list, int pos) {
	ListNode* p = list->head;
	int cnt = 0;
	while (cnt!=pos) {
		p = p->rlink;
		cnt++;
	}
	return p;
}

void delete(ListType *list, int pos) {
	ListNode *p = del_order(list, pos);
	p->llink->rlink = p->rlink;
	p->rlink->llink = p->llink;
	list->length--;
	free(p);
}

void freedom(ListType* list) {
	ListNode *p = list->head->rlink;
	ListNode  *sav;
	if (p == list->tail) {

	}
	else {
		while (p!=list->tail) {
			sav = p;
			p = p->rlink;
			free(sav);
		}
	}
	free(list->head);
	free(list->tail);
}


void main() {
	ListType *list;
	list = (ListType*)malloc(sizeof(ListType));
	init(list);
	list->length = 1;
	int n,i,pos;
	char type,data;

	scanf("%d", &n);
	getchar();

	for (i = 0; i < n; i++) {
		scanf("%c", &type);
		switch (type) {
		case 'A':scanf("%d %c", &pos, &data); if (pos > list->length || pos < 1) { if (pos == 1) { add(list, pos, data); } else { printf("invalid position\n"); } }
				 else { add(list, pos,data); }  break;
		case 'D':scanf("%d", &pos); if (pos >= list->length || pos < 1) { printf("invalid position\n"); }
				 else { delete(list, pos); } break;
		case 'G':scanf("%d", &pos); if (pos >= list->length || pos < 1) { printf("invalid position\n"); }
				 else { printf("%c\n", get_entry(list, pos)); } break;
		case 'P':print(list); printf("\n"); break;
		}
		getchar();
	}
	freedom(list);
	printf("%c", list->head->rlink->item);
	free(list);
}