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

	//����Ʈ ũ�� �Է�
	printf("����Ʈ ũ��:");
	scanf("%d", &n);
	L = (int*)malloc(sizeof(int)*n);

	//���� �߻�
	srand(time(NULL));
	
	for (i = 1; i <= n; i++) {
		 L[i]=rand()%1000000+1;
	}
	printf("\n");

	//����� ���� ���� ��� ����Ʈ ���
	if (n <= 20) {
		printf("����Ʈ:");
		for (i = 1; i <= n; i++) {
			printf(" %d", L[i]);
		}
		printf("\n");
	}

	insertItem(&L, n, k);

	//���� �Է�
	printf("����:");
	scanf("%d", &k);

	//���� ��ȯ�� ���
	printf("����:",findKthSmallest(L, n, k));

	

}