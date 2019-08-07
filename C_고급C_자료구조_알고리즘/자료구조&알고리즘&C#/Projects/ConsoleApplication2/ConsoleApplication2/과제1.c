#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int n;
int *L;

void downHeap(int i, int n) {
	int larger;

	if (i * 2>n)   return;//�ڽĳ�尡 ������ return

						  //�ڽĳ�带 ���ؼ� �� ū ��� ã��
	else if (i * 2 + 1>n)
		larger = i + 2;
	else
		larger = i + 2 + 1;

	downHeap(larger, n);
}

void BuildHeap(int n)
{
	int i;
	for (i = n; i >= 1; i--)
		downHeap(i, n);
	return;
}

int findKthSmallest(int L[], int n, int k)
{
	int i;
	int temp;

	for (i = n; i >= k; i--)
	{
		if (L[i]<L[1]) {
			temp = L[1];
			L[1] = L[i];
			L[i] = temp;
			downHeap(1, i - 1);
		}
	}
	return L[k];
}

int main()
{
	int key, elem, i;


	printf("����Ʈ ũ��:");
	scanf_s("%d", &n);

	L = (int*)malloc(sizeof(int)*(n + 1));


	//�����߻��Լ��� ���� ����
	srand((unsigned)time(NULL));
	for (i = 1; i <= n; i++)
		L[i] = (rand() % 1000000) + 1;


	//n�� �������� ��� ����Ʈ ���
	if (n <= 100) {
		printf("����Ʈ: ");

		for (i = 1; i <= n; i++) {
			printf("%d ", L[i]);
		}
	}
	printf("\n");

	BuildHeap(n);

	for (i = 1; i <= n; i++) {
		printf(" %d", L[i]);
	}
	printf("\n");

	//k��°�� ���� Ű ���
	for (i = 0; i<3; i++) {

		printf("\n");
		printf("����:");
		scanf("%d", &key);
		elem = findKthSmallest(L, n, key);
		printf("����:%d", elem);
	}


	free(L);
	return 0;

}