#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackType {
	char item[1001];
	int top;
}StackType;

char pop(StackType *s) {
	char sav;

	sav = s->item[s->top];
	s->item[s->top--] = NULL;
	return sav;
	
}

int numbe(char *str){
	int i, cnt=0;	

	for (i = 0; i<strlen(str); i++) {
		switch (str[i]) {
		case '(':case '[':case '{':case ')':case ']':case '}':
			cnt++;break;
		}
	}
	return cnt;
}


void matching(char *str) {
	StackType *s = (StackType*)malloc(sizeof(StackType));
	int cnt = number(str);
	char ch;
	s->top = -1;
	int i,n = strlen(str);

	for (i = 0; i < n; i++) {
		switch (str[i]) {
		case '(':case '[':case '{':
			s->item[++s->top] = str[i];
			break;
		case ')':case ']':case '}':
			if (s->top == -1) {
				printf("Wrong_%d", cnt);
				break;
			}
			else {
				ch = pop(s);
				if (ch != str[i]) {
					printf("Wrong_%d", cnt);
					break;
				}
			}
			break;
		default:;
		}
	}

	if (s->top != -1) {
		printf("Wrong_%d", cnt);
	}
	else {
		printf("OK_%d", cnt);
	}
	
}

void main() {
	char str[1001];

	scanf("%s", str);

	matching(str);

}