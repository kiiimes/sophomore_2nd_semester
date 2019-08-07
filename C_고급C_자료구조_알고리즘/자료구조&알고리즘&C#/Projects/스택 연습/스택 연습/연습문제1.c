#include <stdio.h>
#include <stdlib.h>

typedef struct stackNode {
	int item;
	struct StackNode *link;
}StackNode;

typedef struct LinkedStackType {
	StackNode *top;
}LinkedStackType;

StackNode* get_node(int item){
	StackNode *p = (StackNode*)malloc(sizeof(StackNode));
	p->item = item;
	p->link = NULL;
	return p;
}

void push(LinkedStackType *s, int item) {
	StackNode *New = get_node(item);
	StackNode *p = s->top;

	if (p == NULL) {
		p = New;
	}
	else {
		New->link = p;
		p = New;
	}
}

int pop(LinkedStackType *s) {
	StackNode *p=s->top;
	StackNode *tmp=s->top;
	int item;
	
	if (p == NULL) {
		printf("ºó ½ºÅÃ");
	}
	else {
		p = p->link;
		item = tmp->item;
		free(tmp);
		return item;
	}
}




