#include <stdio.h>
int main()
/*{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	if(c==1)
	{
	printf("%d",a+b);
	}
	else if(c==2)
	{
	printf("%d",a-b);}
	else if(c==3)
	{
	printf("%d",a*b);
	}
	else if(c==4&&b!=0)
	{	
	printf("%d",a/b);
	}
	else if(c==4&&b==0)
	{
		printf("Incorrect!");}
	else if(c==5&&b!=0)
	{
		printf("%d",a%b);}
	else if(c==5&&b==0)
	{	
		printf("Incorrect!");}
	return 0;
	}*/
{
	int a;
	int r1,r2,r3,r4,r5;
	scanf("%d",&a);
	r1=a/10000;
	r2=a%10000/1000;
	r3=a%1000/100;
	r4=a%100/10;
	r5=a%10;
	