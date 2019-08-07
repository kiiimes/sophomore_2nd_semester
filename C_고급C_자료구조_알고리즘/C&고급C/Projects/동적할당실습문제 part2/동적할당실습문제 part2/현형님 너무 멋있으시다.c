#include <stdio.h>

int A[10] = { 0,1,3,6,11,17 };
int H[10] = { 0,2,5,1,5,0 };

int airtel(int);
int airtel(int n)
{
	int i,k;
	int m[7];
	int cost=0;
	m[0] = 0;

	for (i = 1; i < n; i++) 
	{
		m[i] = 999999;
		for (k = 0; k < i; k++)
		{
			cost = m[k] + H[k] + A[i - k];
			if (m[i] > cost) 
				m[i] = cost;
		}
	}
	printf("%d", m[n-1]);
}
int main()
{
	int n;
	printf("15010994 Á¶ÇöÇü\n");
	scanf("%d", &n);
	airtel(n);
}