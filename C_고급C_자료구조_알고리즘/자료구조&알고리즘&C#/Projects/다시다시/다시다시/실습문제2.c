#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackType {
	char item[1001];
	int top;
}StackType;

char pop(StackType *s) {
	char sav;
	if (s->top == -1) {
		printf("Stack Empty\n");
	}
	else {
		sav = s->item[s->top];
		s->item[s->top--] = '\0';
		return sav;
	}

}

int number(char *str) {
	int i, cnt = 0;

	for (i = 0; i<strlen(str); i++) {
		switch (str[i]) {
		case '(':case '[':case '{':case ')':case ']':case '}':
			cnt++; break;
		}
	}
	return cnt;
}


int matching(char *str) {
	StackType *s = (StackType*)malloc(sizeof(StackType));
	char ch;
	s->top = -1;
	int i, n = strlen(str);

	for (i = 0; i < n; i++) {
		switch (str[i]) {
		case '(':case '[':case '{':
			s->item[++s->top] = str[i];
			break;
		case ')':case ']':case '}':
			if (s->top == -1) {
				free(s);
				return 0;
			}
			else {
				ch = pop(s);
				if (ch == '('&&str[i]==')'||ch=='{'&&str[i]=='}'||ch=='['&&str[i]==']') {
				}
				else {
					free(s);
					return 0;
				}
			}
			break;
		
		}
	}

	if (s->top != -1) {
		free(s);
		return 0;
	}
	else {
		free(s);
		return 1;
	}
	

}

int main() {
	char str[1001] = {'\0'};
	int i;

	scanf("%[^\n]", str);

	if (matching(str) == 1) {
		printf("OK_%d", number(str));
	}
	else {
		printf("Wrong_%d", number(str));
	}

	

}