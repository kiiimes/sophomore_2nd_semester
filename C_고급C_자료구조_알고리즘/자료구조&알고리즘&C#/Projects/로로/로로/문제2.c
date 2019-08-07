#include <stdio.h>

int mostOnes(int p[][100], int n) {
	int i = 0, j = 0, sav = 0;

	while (p[i][j] != 0) {
		j++;
		if (j == n - 1) {
			if (p[i][j] == 1) {
				return i;
			}
		}
	}
	sav = i;
	i++;
	while (1) {
		while (p[i][j] != 0) {
			j++;
			if (j == n - 1) {
				if (p[i][j] == 1) {
					return i;
				}
			}
		}
		sav = i;
		if (i == n - 1) {
			break;
		}
		i++;
	}
	return sav;

}

void main() {
	int n, p[100][100], i, j;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &p[i][j]);
		}
	}
	printf("%d", mostOnes(p, n));

}