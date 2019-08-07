#include <stdio.h>
#include <stdlib.h>

int main() {
	int *p,i,n=5,j,k;

	p = (int*)malloc(5 * sizeof(int));

	for (i = 0; i < 5; i++) {
		
		scanf("%d", p + i);
		
		if (p[i] == -1) {
			for (j = 0; j <= i; j++) {
				printf(" %d", p[j]);
			
			}
			free(p);
			return 0;
		}
	}


	for (i = 0;; i++) {
		n = n + 3;//8 ¿ø·¡ n=5
		p = (int*)realloc(p, n * sizeof(int));
		for (j = n-3; j < n; j++) {
			scanf("%d", p + j);
			if (p[j] == -1) {
				for (k = 0; k <= j; k++) {
					printf(" %d", p[k]);
				}
				free(p);
				return 0;
			}
		}
	}


}