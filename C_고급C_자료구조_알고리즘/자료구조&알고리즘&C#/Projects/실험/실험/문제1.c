#include<stdio.h>
#include<stdlib.h>

int *H = NULL;
int n;
int cnt;

void insertItem();
void upHeap();
void downHeap();
void rBuildHeap();
void inplaceHeapSort();
void printArray();

void insertItem(int key)
{
	n++;
	H[n] = key;
	upHeap(n);
	//printf("삽입완료\n");
}

void upHeap(int i)
{
	int tmp;
	while (i > 1) {
		//int key = (p[i / 2] > p[i * 2] + 1) ? i * 2 : i * 2 + 1;
		if (H[i] > H[i / 2])
		{
			tmp = H[i];
			H[i] = H[i / 2];
			H[i / 2] = tmp;
			i /= 2;
		}
		else   i /= 2;
	}
}

void downHeap(int i)
{
	int tmp, larger,j;


	if (cnt < i * 2 && cnt < (i * 2) + 1)
		return;

	larger = i * 2;
	if (cnt >= (i * 2) + 1) //오른쪽자식이 존재하면
	{
		if (H[i * 2 + 1] < H[larger])
			larger = (i * 2) + 1;
	}
	if (H[i] < H[larger])
		return;

	tmp = H[i];
	H[i] = H[larger];
	H[larger] = tmp;

	downHeap(larger);
}

void rBuildHeap(int i)
{
	if (i > n)      return;

	rBuildHeap(2 * i);
	rBuildHeap(2 * i + 1);
	downHeap(i);
}

void inplaceHeapSort()
{
	int i;
	int tmp;

	//rBuildHeap(i);

	for (i = n; i >= 2; i--)
	{
		tmp = H[1];
		H[1] = H[i];
		H[i] = tmp;
		cnt--;
		downHeap(1);
	}
}

void printArray()
{
	int i;

	for (i = 1; i <= n; i++)
		printf(" %d", H[i]);
}

int main()
{
	int i;

	scanf("%d", &n);
	H = (int*)malloc((n + 1) * sizeof(int));

	for (i = 1; i <= n; i++)
		scanf("%d", &H[i]);

	rBuildHeap(1);
	/*for(i=1;i<=n;i++)
	printf("%d",H[i]);
	*/
	cnt = n;
	inplaceHeapSort();
	printArray();

	return 0;

}