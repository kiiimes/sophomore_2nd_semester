#include <stdio.h>
#include <stdlib.h>

void main() {

	int n, arr[100] = { 0 },i,info,*p,j,*sav;
	int cnt = 0,k,z;

	scanf("%d", &n);

	sav = (int*)malloc(n * sizeof(int));
	
	
	for (i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}

	scanf("%d", &info);
	p = (int*)malloc(2*info * sizeof(int));

	for (i = 0; i < 2*info; i++) {
		scanf("%d", p + i);
	}

	for (i = 0; i < 2*info; i++) {
		for (j = p[i]; j < p[i + 1]; j++) {
			sav[cnt] = arr[j];
			cnt++;
		}
		cnt = 0;
		for (k = p[i + 1]; k >= p[i]; k--) {
			arr[k] = sav[cnt];
			cnt++;
		}
		for (z = 0; z < cnt; z++) {
			sav[z] =  0 ;
		}
		i++;
	}

	for (i = 0; i < n; i++) {
		printf(" %d", arr[i]);
	}



}