#include <stdio.h>

int prefixAverages1(int *p, int n,int *sav) {
	int i;
	double sum = 0;

	for (i = 0; i < n; i++) {
		sum =sum+ p[i];
		sav[i] = (int)(sum / (i + 1)+0.5);
	}

}

void main() {
	int n,i,*p,*sav;

	scanf("%d", &n);

	p = (int*)malloc(n * sizeof(int));
	sav = (int*)malloc(n * sizeof(int));

	for (i = 0; i < n; i++) {
		scanf("%d", p + i);
	}

	prefixAverages1(p, n, sav);

	for (i = 0; i < n; i++) {
		printf(" %d", sav[i]);
	}
	

}