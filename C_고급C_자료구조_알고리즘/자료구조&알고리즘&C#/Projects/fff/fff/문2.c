#include <stdio.h>
#include <stdlib.h>

void main() {
	int n,i,j,sav;
	int *p;

	scanf("%d", &n);

	p = (int*)malloc(sizeof(int)*n);

	for (i = 0; i < n; i++) {
		scanf("%d", p + i);
	}

	for (i = 1; i < n; i++) {
		sav = p[i];
		j = i - 1;
		while ((j >= 0) && (p[j] > sav)) {
			p[j + 1] = p[j];
			j = j - 1;
		}
		p[j + 1] = sav;
	}

	for (i = 0; i < n; i++) {
		printf(" %d", p[i]);
	}

	free(p);


}