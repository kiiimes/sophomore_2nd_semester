#include <stdio.h>
int main()
/*{
	int n;
	scanf("%d",&n);
	if(n>=0)
	if(n>40)
	printf("실내활동");
	else
	printf("실외활동");
	else
	printf("실내활동");
	return 0;}
{
	int n,m;
	scanf("%d %d",&n,&m);
	if(n<m)
	if(n*n==m)
	{printf("%d*%d=%d",n,n,m);}
	else
	printf("none");
	else
	if(n>m)
	if(m*m==n)
	printf("%d*%d=%d",m,m,n);
	else
	printf("none");
	else
	printf("none");
	return 0;}
{
	int a,b;
	scanf("%d %d",&a,&b);
	if(a>b)
	printf("%d",a);
	else
	printf("%d",b);
	return 0;}
{
	int a,b,c;
	int max=0; int min=0;
	scanf("%d %d %d",&a,&b,&c);
	if(a>b)
	{
		max=a;
		min=b;
		
		if(max>c&&min>c)
		{
			max=max;
			min=c;
		}
		else if(max>c&&c>min)
		{
			max=max;
			min=min;
		}
		else
		{
			max=c;
			min=min;
		}
	}

	else if(a<b)
	{
		max=b;
		min=a;

		if(max>c&&min>c)
		{
			max=max;
			min=c;
		}
		else if(max>c&&c>min)
		{
			max=max;
			min=min;
		}
		else
		{
			max=c;
			min=min;
		}
	}
	printf("%d %d",max,min);
	return 0;
}
{
	int a;
	scanf("%d",&a);
	if(a%2==0&&a%3==0&&a%5==0)
	printf("A");
	else
	if(a%2==0&&a%3==0)
	printf("B");
	else
	if(a%2==0&&a%5==0)
	printf("C");
	else
	if(a%3==0&&a%5==0)
	printf("D");
	else
	if(a%2==0||a%3==0||a%5==0)
	printf("E");
	else
	printf("N");
	return 0;}*/
{
	int a;
	scanf("%d",&a);
	if(a%4!=0)
	printf("평년");
	else {if(a%100!=0)
		printf("윤년");
	else{ if(a%400!=0)
	printf("평년");
	else
	printf("윤년");}

	return 0;}

/*#include <stdio.h>
int main1()
	{
	int a,b,c;
	int max=0; int min=0;
	scanf("%d %d %d",&a,&b,&c);
	if(a>b)
	{
		max=a;
		min=b;
		
		if(max>c&&min>c)
		{
			max=max;
			min=c;
		}
		else if(max>c&&c>min)
		{
			max=max;
			min=min;
		}
		else
		{
			max=c;
			min=min;
		}
	}

	else if(a<b)
	{
		max=b;
		min=a;

		if(max>c&&min>c)
		{
			max=max;
			min=c;
		}
		else if(max>c&&c>min)
		{
			max=max;
			min=min;
		}
		else
		{
			max=c;
			min=min;
		}
	}
	printf("%d %d",max,min);
}
int main2()
	{
	int a,b,c;
	int max=0; int min=0;
	scanf("%d %d %d",&a,&b,&c);
	if(a>b)
	{
		max=a;
		min=b;
		
		if(max>c&&min>c)
		{
			max=max;
			min=c;
		}
		else if(max>c&&c>min)
		{
			max=max;
			min=min;
		}
		else
		{
			max=c;
			min=min;
		}
	}

	else if(a<b)
	{
		max=b;
		min=a;

		if(max>c&&min>c)
		{
			max=max;
			min=c;
		}
		else if(max>c&&c>min)
		{
			max=max;
			min=min;
		}
		else
		{
			max=c;
			min=min;
		}
	}
	printf("%d %d",max,min);
}
int main3()
	{
	int a,b,c;
	int max=0; int min=0;
	scanf("%d %d %d",&a,&b,&c);
	if(a>b)
	{
		max=a;
		min=b;
		
		if(max>c&&min>c)
		{
			max=max;
			min=c;
		}
		else if(max>c&&c>min)
		{
			max=max;
			min=min;
		}
		else
		{
			max=c;
			min=min;
		}
	}

	else if(a<b)
	{
		max=b;
		min=a;

		if(max>c&&min>c)
		{
			max=max;
			min=c;
		}
		else if(max>c&&c>min)
		{
			max=max;
			min=min;
		}
		else
		{
			max=c;
			min=min;
		}
	}
	printf("%d %d",max,min);
}
int main() 
{ int pro_num=0;
scanf("%d",&pro_num);
switch(pro_num){ 
case 1: main1();break; 
case 2: main2(); break; 
case 3: main3(); break; }
return 0;
}*/




	




	

