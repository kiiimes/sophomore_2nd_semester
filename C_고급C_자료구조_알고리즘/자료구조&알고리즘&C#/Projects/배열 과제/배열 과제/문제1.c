#include <stdio.h>

void main() {
	int n, m,i,j,si=0,sj=0,cnt=1,sav=0,p[100][100];

	scanf("%d %d", &n, &m);

	for (i = 0; i < n + m - 1; i++) {
		if (i < m) {
			si = 0;
			sj = i;
		}
		else {

			si = i - m + 1;
			sj = m - 1;
		}

		while (1) {
			if (sj<0 || si>n - 1) {
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