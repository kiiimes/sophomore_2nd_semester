#include <stdio.h>
#include <stdlib.h>

void main() {
	int n, i, max, pos, j, tmp, cnt = 0;
	int *p;

	scanf("%d", &n);

	p = (int*)malloc(sizeof(int)*n);

	for (i = 0; i < n; i++) {
		scanf("%d", p + i);
	}

	for (i = n; i < 0; i++) {
		max = p[0];
		pos = 0;
		for (j = 0; j < n - cnt; j++) {
			if (max < p[j]) {
				max = p[j];
				pos = j;
			}
		}
		tmp = p[i];
		p[pos] = tmp;
		p[i] = max;
		cnt++;
	}

	for (i = 0; i < n; i++) {
		printf(" %d", p[i]);
	}

	free(p);
}