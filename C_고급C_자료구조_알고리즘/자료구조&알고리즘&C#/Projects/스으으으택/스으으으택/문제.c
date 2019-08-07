#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackList {
	char item[101];
	int top;
}StackList;

int prec1(char *str, int i) {
	int s1;
	char ch = str[i];

	if (ch == '-' || ch == '+') {
		s1 = 4;
	}
	else if (ch == '*' || ch == '/') {
		s1 = 5;
	}
	else if (ch == '<' || ch == '>') {
		s1 = 3;
	}
	else if (ch == '&') {
		s1 = 2;
	}
	else if (ch == '|') {
		s1 = 1;
	}
	else if (ch == '!') {
		s1 = 6;
	}
	if (i != 0) {
		if (str[i - 1] < 'A' || str[i - 1] > 'Z') {
			if (str[i - 1] != ')')
				s1 = 6;
		}
	}
	else if (i == 0) {
		if (ch > 'A' || ch < 'Z') {
			s1 = 6;
		}
	}
	return s1;
}
int Sprec(char *str, int i) {
	int s1;
	char ch = str[i];

	if (ch == '-' || ch == '+') {
		s1 = 4;
	}
	else if (ch == '*' || ch == '/') {
		s1 = 5;
	}
	else if (ch == '<' || ch == '>') {
		s1 = 3;
	}
	else if (ch == '&') {
		s1 = 2;
	}
	else if (ch == '|') {
		s1 = 1;
	}
	else if (ch == '!') {
		s1 = 6;
	}
	else {
		s1 = 0;
	}

	return s1;
}

char pop(StackList *s) {
	char sav = s->item[s->top--];
	return sav;
}

void push(StackList *s, char ch) {
	s->item[++s->top] = ch;
}

void infix_to_postfix(char exp[]) {
	StackList *s = (StackList*)malloc(sizeof(StackList));
	s->top = -1;
	int i;
	char ch, top_op, sav = '\0',s1='\0';

	for (i = 0; i <= strlen(exp); i++) {
		ch = exp[i];
		switch (ch) {
		case '+':case '-':case '*':case '/':case '>':case '<':case '!':case '&':case '|': {
			if (i == 0) {
				sav = ch;
			}
				while (s->top != -1 && (prec1(exp, i) <= Sprec(s->item, s->top))) {
					printf("%c", pop(s));
				}
				push(s, ch);
			}
			break;
		
		case '(':
			push(s, ch);
			s1 = ch;
			break;
		case ')':
			top_op = pop(s);
			while (top_op != '(') {
				printf("%c", top_op);
				top_op = pop(s);
			}
			break;
		default:
			if (ch != '\0') {
				printf("%c", ch);
				if (sav != '\0'&&s1!='(') {
					printf("%c", sav);
					sav = '\0';
					pop(s);
				}
			}
			break;
		}
	}
	while (s->top != -1) {
		printf("%c", pop(s));
	}
	printf("\n");
	free(s);
}

void main() {
	char str[101];
	int n, i;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		getchar();
		scanf("%s", str);
		infix_to_postfix(str);
	}



}