#include <stdio.h>
#include <stdlib.h>

void main() {
	int n,i;
	int *pa, *pb,*sum;

	scanf("%d", &n);

	pa = (int*)malloc(sizeof(int)*n);
	pb = (int*)malloc(sizeof(int)*n);
	sum = (int*)malloc(sizeof(int)*n);


	for (i = 0; i < n; i++) {
		scanf("%d", pa + i);
	}
	for (i = 0; i < n; i++) {
		scanf("%d", pb + i);
		sum[i] = 0;
	}
	
	for (i = 0; i < n; i++) {
		sum[i] =pa[i]+pb[n-i-1];
		printf(" %d", sum[i]);
	}
	free(pa);
	free(pb);
	free(sum);


}