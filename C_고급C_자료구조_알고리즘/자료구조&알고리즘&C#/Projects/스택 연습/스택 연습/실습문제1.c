#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackType {
	char *item;
	int MAX;
	int top;
}StackType;

void push(StackType *s, char item) {
	if (s->top==s->MAX-1) {
		printf("Stack FULL\n");
	}
	else {
		s->item[++(s->top)] = item;
	}
}

char pop(StackType *s) {
	char sav;

	if (s->top == -1) {
		printf("Stack Empty\n");
	}
	else {
		sav = s->item[s->top];
		s->item[s->top--] = NULL;
		return sav;
	}
}

void peek(StackType *s) {

	if (s->top == -1) {
		printf("Stack Empty\n");
	}
	else {
		printf("%c\n", s->item[s->top]);
	}
}

void duplicate(StackType *s) {
	char sav;

	if (s->top == s->MAX - 1) {
		printf("Stack FULL\n");
	}
	else {
		sav = s->item[s->top];
		pop(s);
		push(s, sav);
		push(s, sav);
	}
}

void upRotate(StackType *s, int n) {
	int i;
	char sav=s->item[s->top];//r

	if (n > s->top + 1) {

	}
	else {
		for (i = s->top; i > s->top - n + 1; i--) {
			s->item[i] = s->item[i - 1];
		}
		s->item[s->top - n + 1] = sav;
	}
}

void downRotate(StackType *s, int n) {
	int i;

	char sav = s->item[s->top-n+1];
	char tmp;

	if (n > s->top + 1) {

	}
	else {
		for (i = s->top - n+1; i < s->top ; i++) {
			s->item[i] = s->item[i + 1];
		}
		s->item[s->top] = sav;
	}
}

void print(StackType* s) {
	int i;

	for (i = s->top; i >= 0; i--) {
		printf("%c", s->item[i]);
	}
	printf("\n");
}

void main() {
	StackType *s = (StackType*)malloc(sizeof(StackType));;
	int n,y,i,rn;
	char item;
	char type[6];


	scanf("%d", &(s->MAX));
	s->item = (char*)malloc(s->MAX*sizeof(char));
	s->top = -1;

	scanf("%d", &y);
	getchar();

	for (i = 0; i < y; i++) {
		scanf("%s", type);
		getchar();
		
		if (strcmp(&type, "POP")==0) {
			pop(s);
		}
		else if (strcmp(&type, "PUSH")==0) {
			scanf("%c", &item); 
			getchar();
			push(s, item);
		}
		else if (strcmp(&type, "PEEK") == 0) {
			peek(s); break;
		}
		else if (strcmp(&type, "DUP") == 0) {
			duplicate(s);
		}

		else if (strcmp(&type, "UpR") == 0) {
			scanf("%d", &rn);
			getchar();
			upRotate(s, rn);
		}

		else if(strcmp(&type,"DownR")==0){
			scanf("%d", &rn);
			getchar();
			downRotate(s, rn);
		}
		else if(strcmp(&type,"PRINT")==0){
			print(s);
		}
	
	}
	free(s);
}