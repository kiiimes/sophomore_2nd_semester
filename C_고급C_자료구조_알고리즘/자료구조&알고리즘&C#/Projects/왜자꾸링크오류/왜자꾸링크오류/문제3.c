#include <stdio.h>

void main() {
	int n,p[100][100],cnt=1,i,j,k;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			p[i][j] = cnt++;
		}
		i++;
		for (k = n - 1; k >= 0; k--) {
			p[i][k] = cnt++;
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf(" %d", p[i][j]);
		}
		printf("\n");
	}



}
