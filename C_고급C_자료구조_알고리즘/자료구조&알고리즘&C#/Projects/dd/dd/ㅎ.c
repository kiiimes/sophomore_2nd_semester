
#include <stdio.h>

void main() {
	int n;
	int i, j, k;

	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		for (j = i; j <= n; j++) {
			if (j == i) {

			}
			else {
				for (k = j; k <= n; k++) {
					if (k == i || k == j) {

					}
					else {
						printf("%d %d %d\n", i, j, k);
					}
				}
			}
		}

	}



}