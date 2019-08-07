#include <stdio.h>
#include <stdlib.h>

typedef struct StackType{
	int *stack;
	int top;
}StackType;

void init(StackType *s) {
	s->top = -1;
}

int is_empty(StackType *s) {
	return (s->top == -1);
}

int is_full(StackType *s) {
	return (s->top==
}

void push(StackType *s, int item) {
	if(
}

void main() {




}