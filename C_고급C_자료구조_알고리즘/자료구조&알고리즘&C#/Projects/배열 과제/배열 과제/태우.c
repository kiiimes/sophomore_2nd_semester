#include<stdio.h>


int main()
{
	int n, m, cnt = 1, i, j, tmpx=0,tmpy=0;
	int arr[100][100];

	scanf("%d %d", &n, &m);

	for (i = 0; i < m + n - 1; i++)
	{
		if (i < m) {
			tmpy = 0;
			tmpx = i;
		}
		else {
			tmpy = i - m + 1;
			tmpx = m - 1;
		}
		while (1)
		{
			if (tmpx < 0 || tmpy >= n)
				break;
			arr[tmpy++][tmpx--] = cnt++;
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			printf(" %d", arr[i][j]);
		printf("\n");
	}
	return 0;
}