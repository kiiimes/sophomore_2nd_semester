#include <stdio.h>
#include <stdlib.h>

void main() {

	int n, m,**p,i,j,savi=0,savj=0,cnt=1,k=0;
	int a,z;

	scanf("%d %d", &n, &m);

	p = (int**)malloc(n * sizeof(int*));

	for (i = 0; i < m; i++) {
		p[i] = (int*)malloc(m * sizeof(int));
	}

	while (1) {
		for (j = savj; j < m - savj - 1; j++) {
			p[savi][j] = cnt++;
			if (cnt == n*m + 1) {
				break;
			}
		}
		for (k = savi; k < n - savi - 1; k++) {
			p[k][j] = cnt++;
			if (cnt == n*m + 1) {
				break;
			}
		}

		for (z = m -1 - savj; z > savj; z--) {
			p[k][z] = cnt++;
			if (cnt == n*m + 1) {
				break;
			}
		}

		for (a = n -1- savi; a > savi; a--) {
			p[a][z] = cnt++;
			if (cnt == n*m + 1) {
				break;
			}
		}
		savi++;
		savj++;
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf(" %d", p[i][j]);
		}
		printf("\n");
	}


	for (i = 0; i < n; i++) {
		free(p[i]);
	}

	free(p);

}