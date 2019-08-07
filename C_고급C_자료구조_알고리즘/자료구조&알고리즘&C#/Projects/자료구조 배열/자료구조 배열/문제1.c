#include <stdio.h>

void main() {
	int n, arr[100] = { 0 }, dnum, *p;
	int i, sav[100] = { 0 }, cnt = 0, j, k;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}
	
	scanf("%d", &dnum);

	p = (int*)malloc(2 * dnum * sizeof(int));

	for (i = 0; i < 2*dnum; i++) {
		scanf("%d", p + i);
	}

	for (i = 0; i < dnum; i++) {
		cnt = 0;
		for (j = p[i+1]; j <= p[i]; j++) {
			sav[cnt] = arr[j];
			cnt++;
		}
		cnt = 0;
		for (k = p[i]; k <= p[i + 1]; k++) {
			arr[k] = sav[cnt];
			cnt++;
		}
		i++;
	
	}

	for (i = 0; i < n; i++) {
		printf("%d", arr[i]);
	}
	free(p);
}