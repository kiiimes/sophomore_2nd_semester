#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void iss(int *arr, int size)
{
	int i, j;
	int max, maxp;

	for (i = size - 1; i > 0; i--)
	{
		max = arr[0];
		maxp = 0;
		for (j = 1; j <= i; j++)
		{
			if (max < arr[j])
			{
				max = arr[j];
				maxp = j;
			}
		}

		swap(&arr[maxp], &arr[i]);
	}
}

void iis(int *arr, int size)
{
	int i, j;
	int k, temp;

	for (i = 1; i < size; i++)
	{
		temp = i;
		for (j = i - 1; j >= 0; j--)
		{

			if (arr[temp] < arr[j])
			{
				swap(&arr[temp], &arr[j]);
				temp--;
			}

		}



	}
}
void main()
{
	int n;
	int i;
	int *arr1, *arr2;
	int temp;
	clock_t iss_start_t, iss_end_t, iis_start_t, iis_end_t;

	srand((unsigned)time(NULL));
	scanf("%d", &n);

	arr1 = (int *)malloc(sizeof(int)*n);
	arr2 = (int *)malloc(sizeof(int)*n);

	for (i = 0; i < n; i++)
	{
		temp = rand() % n + 1;

		arr1[i] = temp;
		arr2[i] = temp;
	}

	iss_start_t = clock();
	iss(arr1, n);
	iss_end_t = clock();

	iis_start_t = clock();
	iis(arr2, n);
	iis_end_t = clock();

	printf("선택정렬 :  %lf s\n", (double)(iss_end_t - iss_start_t) / CLOCKS_PER_SEC);


	printf("삽입정렬 :  %lf s\n", (double)(iis_end_t - iis_start_t) / CLOCKS_PER_SEC);

	free(arr1);
	free(arr2);

}