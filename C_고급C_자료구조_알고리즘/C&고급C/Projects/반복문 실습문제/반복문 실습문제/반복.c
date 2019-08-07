#include <stdio.h>
int main()
	/*{
	int a,b;
	a=1;
	scanf("%d",&b);
	while(a<b)
	{
	if(b%a==0)
	{
	printf("%d ",a);
	}
	a++;}
	printf("%d",b);

	return 0;}*/
	/*{
	int n;
	int sum=0;
	do
	{
	scanf("%d",&n);
	if(n!=0)
	{sum=sum+n;}
	}
	while(n!=0);
	printf("%d",sum);
	return 0;}
	*/
	/*#include < stdio.h> 
	int main1() {
	int a,b;
	a=1;
	scanf("%d",&b);
	while(a<b)
	{
	if(b%a==0)
	{
	printf("%d ",a);
	}
	a++;}
	printf("%d",b);

	return 0;}*/
	/*{
	int i,j;
	for(i=1;i<=5;i++)
	{
	for(j=1;j<=i;j++)
	{
	printf("*");}

	printf("\n");}


	return 0;
	}*/
	/*{
	int i=1,j=1;
	while(i<=5){
	j=1;
	while(j<=i){//i=2,j=1
	printf("*");
	j++; 
	}
	printf("\n");
	i++;
	}
	return 0;
	}*/
	/*{
	int i,j;
	int a1=1;
	for(i=1;i<=5;i++)
	{
	for(j=5;j>=i;j--)
	{
	printf("%3d",a1);
	a1++;
	}
	printf("\n");
	}
	return 0;}*/
{
	int i,j;
	int a1=1,a2=1,k=0;
	for(i=1;i<=3;i++)
	{
		for(j=1;j<=5;j++)
		{	
			while(a1<=50)
			{
			a1++;
			a2=1;
			while(a2<=a1)
			{
				if(a1%a2==0)
				{
					k++;}//if

				a2++;
			}//while
			if(k==2)
				printf("%d ",a1);}
		}
		printf("\n");
	}
	return 0;}









