#include <stdio.h>
#include <stdlib.h>

void main() {
	int n, *p, m,i,j,sav;

	scanf("%d", &n);

	p = (int*)malloc(n * sizeof(int));

	for (i = 0; i < n; i++) {
		p[i] = i;
	}
	sav = p[n - 1];

	p = (int*)realloc(p, (n - 1) * sizeof(int));

	for (i = 0; i < n - 1; i++) {
		p[i] = i;
		if (p[i] == n / 2) {
			for (j = i + 1; j < n - 1; j++) {
				p[j - 1] = p[j];
			}
			break;
		}
	}
	p[n - 2] = sav;

	for (i = 0; i < n - 1; i++) {
		printf(" %d", p[i]);

	}

	free(p);

}