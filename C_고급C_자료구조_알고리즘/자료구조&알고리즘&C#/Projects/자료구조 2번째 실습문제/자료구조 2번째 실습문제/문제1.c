#include <stdio.h>
#include <stdlib.h>

void main() {
	int len, arr[100] = { 0 }, n, *p;
	int i, sav[100] = { 0 },j,cnt=0,k;

	scanf("%d", &len);

	for (i = 0; i < len; i++) {
		scanf("%d", arr + i);
	}

	scanf("%d", &n);

	p = (int*)malloc(2 * n * sizeof(int));

	for (i = 0; i < 2 * n; i++) {
		scanf("%d", p + i);
	}
	for (i = 0; i < 2* n; i++) {
		cnt = 0;
		for (j = p[i+1]; j >= p[i ]; j--) {
			sav[cnt] = arr[j];
			cnt++;
		}
		printf("\n");
		cnt = 0;
		for (k = p[i]; k <= p[i + 1]; k++) {
			arr[k] = sav[cnt];
			cnt++;
		}
		printf("\n");
		i++;
	}

	for (i = 0; i < len; i++) {
		printf(" %d", arr[i]);
	}


	free(p);

}