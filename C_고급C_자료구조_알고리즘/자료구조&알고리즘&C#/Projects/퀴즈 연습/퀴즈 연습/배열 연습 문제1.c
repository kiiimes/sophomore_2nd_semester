#include <stdio.h>
#include <stdlib.h>

void main() {
	int n, arr[100] = { 0 },info,*p,i,j;
	int sav[100] = { 0 },cnt=0,k;

	scanf("%d", &n);
	
	for (i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}
	scanf("%d", &info);
	p = (int*)malloc(info*2 * sizeof(int));
	for (i = 0; i < 2 * info; i++) {
		scanf("%d", p + i);
	}

	for (i = 0; i < 2 * info; i++) {
		cnt = 0;
		for (j = p[i+1]; j >= p[i]; j--) {
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
		printf(" %d", arr[i]);
	}
	

}