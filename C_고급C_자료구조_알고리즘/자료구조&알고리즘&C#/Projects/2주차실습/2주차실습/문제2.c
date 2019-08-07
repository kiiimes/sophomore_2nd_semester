#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
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
	int *arr;

	scanf("%d", &n);

	arr = (int *)malloc(sizeof(int)*n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", arr + i);
	}

	iis(arr, n);

	for (i = 0; i < n; i++)
	{
		printf(" %d", *(arr + i));
	}

	free(arr);

}