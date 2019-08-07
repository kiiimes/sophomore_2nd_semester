#include <stdio.h>
#include <stdlib.h>

void order(int *pa, int *pb, int *pc) {
	int max, min, mid;

	max = *pa;

	if (max < *pb) {
		max = *pb;
	}
	if (max < *pc) {
		max = *pc;
	}
	


}


void main() {
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	order(&a, &b, &c);//order함수 호출


}