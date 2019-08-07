#include <stdio.h>
#include <stdlib.h>

void swapElements(int *pa, int *pb) {
	int *temp;

	temp = pa;
	pa = pb;
	pb = temp;

}


void main() {
	int n, i, j, max, pos;
	int *p;

	scanf("%d", &n);

	p = (int*)malloc(sizeof(int)*n);

	for (i = 0; i < n; i++) {
		scanf("%d", p + i);
	}



	for (i = 0; i < n - 1; i++) {
		max = p[i];
		pos = i;
		for (j = 0; j < n - i; j++) {
			if (max < p[j]) {
				max = p[j];
				pos = j;

			}
		}
		printf("%d\n", max);

		swapElements(p + pos, p + i);
	}

	for (i = 0; i < n; i++) {
		printf(" %d", p[i]);
	}

	free(p);

}