#include <stdio.h>
#include <string.h>

typedef struct StackList {
	char item[101];
	int top;
}StackList;

void insert(StackList *s,int sav) {
	s->item[++s->top] = sav;
}

int pop(StackList *s) {
	char sav=s->item[s->top--];
	return sav;
}
void confirm(char citem, StackList *s) {
	int sav = 0,first,second;
	if (citem >= '1'&&citem <= '9') {
		s->item[++s->top] = 0 + citem - '0';
	}
	else {
		if (citem == '*') {
			sav = pop(s)*pop(s);
			insert(s, sav);
		}
		else if (citem == '/') {
			second = pop(s);
			first=pop(s);
			sav = first / second;
			insert(s, sav);
		}
		else if (citem == '+') {
			sav = pop(s) + pop(s);
			insert(s, sav);
		}
		else if (citem == '-') {
			second = pop(s);
			first = pop(s);
			sav = first - second;
			insert(s, sav);
		}
	}
}


int calc(char *str, StackList *s) {
	int i;
	for (i = 0; i < strlen(str); i++) {
		confirm(str[i],s);
	}
	return pop(s);
}


void main() {
	StackList *s = (StackList*)malloc(sizeof(StackList));
	int num,i;
	char str[101];
	scanf("%d", &num);
	s->top = -1;

	for (i = 0; i < num; i++) {
		getchar();
		scanf("%s", str);
		printf("%d\n",calc(str, s));
	}

}