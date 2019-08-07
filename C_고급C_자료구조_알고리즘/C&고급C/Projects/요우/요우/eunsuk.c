#include <stdio.h>
int main()
{
	int a,b,c;
	int max=0,sec=0,min=0;
	scanf("%d %d %d",&a,&b,&c);
	
	if(a>b)
	{
		max=a;
		min=b;
	}
	else
	{
		max=b;
		min=a;
	}

	if(max<=c)
	{
		min=sec;
		sec=max;
		
	}
	else if(c>=sec)
		sec=c;

	printf("%d",sec);
	return 0;
}
