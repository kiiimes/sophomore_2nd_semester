#include <stdio.h>

void main() {
	int n, m,i,j,si,sj,p[100][100],cnt=1;

	scanf("%d %d", &n, &m);

	for (i = 0; i < m+n-1; i++) {
		if (i < m) {
			si = 0;
			sj = i;
		}
		else {
			si = i - m+1;
			sj = m - 1;
		}
		while (1) {
			if (si == n-1 || sj == 0) {
				p[si++][sj++] = cnt++;
				break;
			}
			p[si++][sj--] = cnt++;
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf(" %d", p[i][j]);
		}
		printf("\n");
	}



}