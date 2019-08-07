#include <stdio.h>
#include <stdlib.h>

int* prefixAverage1(int *p, int n) {
	int i, j,*arr2;
	double sum;

	arr2 = (int*)malloc(n * sizeof(int));

	for (i = 0; i < n; i++) {
		sum = 0;
		for (j = 0; j <= i; j++) {
			sum = sum + p[j];
		}
		arr2[i] = sum / (i + 1)+0.5;
	}

	return arr2;

}

int* prefixAverage2(int *p, int n) {
	int i, j,*arr;
	double sum = 0;

	arr = (int*)malloc(n * sizeof(int));

	for (i = 0; i < n; i++) {
		sum += p[i];
		arr[i] = sum / (i + 1) +0.5;
	}

	return arr;
}



void main() {
	int n, *p, i, *sav1, *sav2;

	scanf("%d", &n);

	p = (int*)malloc(n * sizeof(int));

	for (i = 0; i < n; i++) {
		scanf("%d", p + i);
	}

	sav1 = prefixAverage1(p, n);
	sav2 = prefixAverage2(p, n);

	for (i = 0; i < n-1; i++) {
		printf("%d ", sav1[i]);
	}
	printf("%d\n", sav1[n - 1]);
	for (i = 0; i < n-1; i++) {
		printf("%d ", sav2[i]);
	}
	printf("%d", sav2[n - 1]);


	
	free(sav1);
	free(sav2);
	free(p);

}