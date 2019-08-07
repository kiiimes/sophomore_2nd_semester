#include <stdio.h>

void main() {
	int n, i, j, p[100][100] = { 0 },k,cnt=1;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			p[i][j] = cnt;
			cnt++;
		}
		i++;
		for (k = n - 1; k >= 0; k--) {
			p[i][k] = cnt;
			cnt++;
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf(" %d", p[i][j]);
		}
		printf("\n");
	}




}