#include <stdio.h>

void main() {
	int n, m,a;
	int i, j, k, z,sav=0,cnt=1,p[100][100],sn,sm;

	scanf("%d %d", &n, &m);

	sn = n;
	sm = m;

	
	for (i = 0; i < n; i++) {
		sav = i;
		for (j = i; j < m-1; j++) {
			p[i][j] = cnt;
			if (cnt == (sn*sm)) {
				break;
			}
			cnt++;
		}

		for (k = sav; k < n - 1; k++) {
			p[k][m - 1] = cnt;
			if (cnt == (sn*sm)) {
				break;
			}
			cnt++;
		}

		for (z = m-1; z >sav; z--) {
			p[n-1][z] = cnt;
			if (cnt == (sn*sm)) {
				break;
			}
			cnt++;
		}

		for (a = n - 1; a > sav; a--) {
			p[a][sav] = cnt;
			if (cnt == (sn*sm)) {
				break;
			}
			cnt++;
			
		}

		if (cnt == (sn*sm)) {
			break;
		}

		i = sav;
		n--;
		m--;

	}

	if (sn == sm&&sn%2!=0) {
		p[sn / 2][sm / 2] = cnt;
	}


	for (i = 0; i < sn; i++) {
		for (j = 0; j < sm; j++) {
			printf(" %d", p[i][j]);
		}
		printf("\n");
	}


}