#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* hi1(int n, int p[]) {
	int i,j,sum;
	int *A;
	A=(int*)malloc(n*sizeof(int));
	for (i = 0; i < n; i++) {
		sum = 0;
		for (j = 0; j <= i; j++) {
			sum += p[j];
		}
		A[i] = (int)(sum / (i + 1)+0.5);
	}
	return A;
}
int* hello2(int n, int p[]) {
	int i, j, sum=0;
	int *A = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		sum += p[i];
		A[i] = (int)(sum / (i + 1)+0.5);
	}
	return A;
}

void main() {
	int *p, n,i,*pa,*pb;
	clock_t start_t1, end_t1,start_t2,end_t2;

	scanf("%d", &n);

	p = (int*)malloc(n*sizeof(int));

	srand((unsigned int)(time(NULL)));
	for (i = 0; i < n; i++)
	{
		p[i] = rand() % 10000 + 1;
	}
	
	start_t1 = clock();
	pa=hi1(n, p);
	end_t1 = clock();
	
	start_t2 = clock();
	pb = hello2(n, p);
	end_t2 = clock();

	/*for (i = 0; i < n; i++) {
		printf(" %d", pa[i]);
	}
	printf("\n");
	for (i = 0; i < n; i++) {
		printf(" %d", pb[i]);
	}
	printf("\n");*/

	printf("%lf\n", (double)(end_t1 - start_t1) / CLOCKS_PER_SEC);
	printf("%lf\n", (double)(end_t2 - start_t2) / CLOCKS_PER_SEC);

	free(pa);
	free(pb);
	free(p);
	
}