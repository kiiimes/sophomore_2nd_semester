#include <stdio.h>

void main() {
	
	int n, m, p[100][100] = { 0 },i,j,k,z;
	int cnt = 1,sn,sm,si,a;

	scanf("%d %d", &n, &m);
	
	sn = n; sm = m; 

	for (i = 0;; i++) {
		for (j = i; j < n - 1; j++) {
			p[i][j] = cnt;
			cnt++;
			if (cnt == sn*sm) {
				break;
			}
		}

		si = i;

		for (k = n - 1; k > m - 1; k--) {
			p[i][k] = cnt;
			cnt++;
			i++;
			if (cnt == sn*sm) {
				break;
			}
			printf("%d", o[n-k]
			);
		}

		for (z = m - 1; z > i; z--) {
			p[i][z] = cnt;
			cnt++;
			if (cnt == sn*sm) {
				break;
			}
		}

		for (a = n - 1; a > si; a--) {
			p[i][a] = cnt;
			cnt++;
			i--;
			if (cnt == sn*sm) {
				break;
			}
		}

		n--;
		m--;
		if (cnt == sn*sm) {
			break;
		}

	}

	for (i = 0; i < sn; i++) {
		for (j = 0; j < sm; j++) {
			printf("%d", p[i][j]);
		}
	}



}