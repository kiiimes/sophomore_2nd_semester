#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
	int n, *p,i,tmp;

	scanf("%d", &n);

	p = (int*)malloc(n * sizeof(int));

	for (i = 0; i < n; i++) {
		scanf("%d", p+i);
	}

	for (i = 0; i < n-1; i++) {
		if (p[i] > p[i + 1]) {
			tmp = p[i];
			p[i] = p[i + 1];
			p[i + 1] = tmp;
		}
	}

	for (i = 0; i < n; i++) {
		printf("%d\n", p[i]);
	}

}