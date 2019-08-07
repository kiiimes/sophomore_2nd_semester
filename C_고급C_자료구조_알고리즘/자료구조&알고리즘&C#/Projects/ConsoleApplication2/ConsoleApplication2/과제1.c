#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int n;
int *L;

void downHeap(int i, int n) {
	int larger;

	if (i * 2>n)   return;//자식노드가 없으면 return

						  //자식노드를 비교해서 더 큰 노드 찾기
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


	printf("리스트 크기:");
	scanf_s("%d", &n);

	L = (int*)malloc(sizeof(int)*(n + 1));


	//난수발생함수로 난수 생성
	srand((unsigned)time(NULL));
	for (i = 1; i <= n; i++)
		L[i] = (rand() % 1000000) + 1;


	//n이 작은수인 경우 리스트 출력
	if (n <= 100) {
		printf("리스트: ");

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

	//k번째로 작은 키 출력
	for (i = 0; i<3; i++) {

		printf("\n");
		printf("순위:");
		scanf("%d", &key);
		elem = findKthSmallest(L, n, key);
		printf("원소:%d", elem);
	}


	free(L);
	return 0;

}