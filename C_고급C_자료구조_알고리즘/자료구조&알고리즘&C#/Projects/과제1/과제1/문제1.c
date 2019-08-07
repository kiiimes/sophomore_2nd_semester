#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findKthSmallest(int *L, int n, int k) {
	
}

void upHeap(int L[],int i) {
	int temp;
	if (i == 1) {
		return;
	}

	if (L[i] <= L[i / 2]) {
		return;
	}


	temp = L[i];
	L[i] = L[i / 2];
	L[i / 2] = temp;

	upHeap(*L,i / 2);
}

void insertItem(int *L,int n,int k) {
	L[n + 1] = k;
	n++;
	upHeap(*L,n);
}

void main() {
	int n,i,k,*L;

	//리스트 크기 입력
	printf("리스트 크기:");
	scanf("%d", &n);
	L = (int*)malloc(sizeof(int)*n);

	//난수 발생
	srand(time(NULL));
	
	for (i = 1; i <= n; i++) {
		 L[i]=rand()%1000000+1;
	}
	printf("\n");

	//충분히 작은 수일 경우 리스트 출력
	if (n <= 20) {
		printf("리스트:");
		for (i = 1; i <= n; i++) {
			printf(" %d", L[i]);
		}
		printf("\n");
	}

	insertItem(&L, n, k);

	//순위 입력
	printf("순위:");
	scanf("%d", &k);

	//원소 반환값 출력
	printf("원소:",findKthSmallest(L, n, k));

	

}