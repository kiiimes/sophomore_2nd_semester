#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//�ڸ��ٲٴ� �Լ�
void swap(int *x, int *y) {
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

//�ٿ��� �Լ�
void downHeap(int L[],int i,int n) {
	
	int left = i * 2;
	int right = i * 2 + 1;
	int bigger = left;

	//�ڽ� ��尡 ������ Ȯ��
	if (left> n) {
		return;
	}
	
	//ũ�� ���Ͽ� �ڸ��ٲ�
	if (right <= n) {
		if (L[right] > L[bigger]) {
			bigger = right;
		}
	}
	if (L[i] >= L[bigger])return;

	swap(&L[i], &L[bigger]);
	
	//����Ͽ� �������鼭 �ڸ��� ã�ư���. 
	downHeap(L,bigger,n);


}

//�� ���� �Լ�
void rBuildHeap(int L[],int i,int n) {
	if (i > n) {
		return;
	}
	//���� �ڽİ� ������ �ڽ����� ����Ͽ� ������ �� downheap �Լ��� �ڸ��� ���� �´� �ڸ��� ã�ư���.
	rBuildHeap(L,2 * i,n);
	rBuildHeap(L,2 * i + 1,n);
	downHeap(L,i,n);
	return;
}

//�ش� ������ ���� ã�� �Լ�
int findKthSmallest(int L[], int n, int k) {
	int i;
	//���� ������ �ʿ� �����Ƿ� k��°���� ���� 
	for (i = n; i >= k; i--) {
		//�̹� ������ �Ǿ��ִ� ��츦 ���ǹ����� �Ÿ���.
		if (L[i] < L[1]) {
			swap(&L[1], &L[i]);
			downHeap(L, 1, i - 1);
		}
	}
	return L[k];
}


//main
void main() {
	//n : ����Ʈũ��,i : �ݺ��� �� �ε��� ,k : ����, *L : �迭
	int n, i, k, *L;

	//����Ʈ ũ�� �Է�
	printf("����Ʈ ũ��:");
	scanf("%d", &n);

	//�����Ҵ�
	L = (int*)malloc(sizeof(int)*(n+1));
	

	//���� �߻�
	srand(time(NULL));

	for (i = 1; i <= n; i++) {
		L[i] = rand() % 1000000 + 1;
	}

	
	//����� ���� ���� ��� ����Ʈ ���
	if (n <= 20) {
		printf("����Ʈ:");
		for (i = 1; i <= n; i++) {
			printf(" %d", L[i]);
		}
		printf("\n");
	}
	//������
	rBuildHeap(L,1,n);

	for (i = 0; i < 3; i++) {
		//���� �Է�
		printf("����:");
		scanf("%d", &k);
		//�ش� ������ ���� ���
		printf("����:%d\n", findKthSmallest(L, n, k));
	}

	//�����Ҵ� ����
	free(L);
	


}