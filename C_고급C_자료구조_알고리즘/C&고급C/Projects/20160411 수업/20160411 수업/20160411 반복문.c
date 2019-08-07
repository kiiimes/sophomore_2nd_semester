#include <stdio.h>
int main()
/*{
nt main()
{
   int i, j;

   for ( i = 0 ; i < 6 ; i++ )
   {
      for ( j = 0 ; j < i ; j++ )
      {
         printf("*");
      }
   printf("\n");
   } //for ( i = 0 ; i < 6 ; i++ )
return 0 ;
}*/
/*{
	int an1,an2,an3;
	int gu1,gu2,gu3;
	int sum1=0,sum2=0;
	scanf("%d %d %d",&an1,&an2,&an3);
	scanf("%d %d %d",&gu1,&gu2,&gu3);
	if(an1==gu1)
		sum1=sum1+1;
	if(an2==gu2)
		sum1=sum1+1;
	if(an3==gu3)
		sum1=sum1+1;
	if(an1==gu2||an1==gu3)
		sum2=sum2+1;
	if(an2==gu1||an2==gu3)
		sum2=sum2+1;
	if(an3==gu1||an3==gu2)
		sum2=sum2+1;
	printf("%dS%dB",sum1,sum2);
	
	return 0;
}*/
/*{
	int num1,num3;
	char num2;
	int sum;
	scanf("%d %c %d",&num1,&num2,&num3);
	if(num2=='+')
	{	sum=num1+num3;
	printf("%d",sum);}
	else if(num2=='-')
	{	sum=num1-num3;
	printf("%d",sum);}
	return 0;}*/
/*{
	int n,m;
	int fiv,one;
	scanf("%d %d",&n,&m);
	if(n==1)
	{

		fiv=(m-500)/500;
		one=(m-500)%500/100;

		printf("아메리카노\n%d %d",fiv,one);
	}
	else if(n==2)
	{
		fiv=(m-400)/500;
		one=(m-400)%500/100;

		printf("카페라떼\n%d %d",fiv,one);
	}
	else if(n==3)
	{
		fiv=(m-300)/500;
		one=(m-300)%500/100;

		printf("레몬티\n%d %d",fiv,one);
	}

	return 0;}*/
/*{
	int n,m;
	m=1;
	scanf("%d",&n);
	while(m<n)
	{
		if(n%m==0)
			printf("%d ",m);
		m++;
	}
	printf("%d",n);
	return 0;}*/
/*{
	int num1;
	int guess1=0;
	int i=0;
	scanf("%d",&num1);
do
{
		scanf("%d",&guess1);
	if(guess1>num1)
		printf("%d>?",guess1);
	else if(guess1<num1)
		printf("%d<?",guess1);
	i++;
	}while(guess1!=num1);
	printf("%d==?",guess1);
	printf("\n%d",i);
	return 0;
}*/

/*{
	int n;
	int sum=0;
	do {
		scanf("%d",&n);
		if(n!=0)
			sum=sum+n;
	}while(n!=0);
	printf("%d",sum);
	return 0;
}*/
/*
{
	int i,j,fac;
	fac=1;
	for(i=1;i<=10;i++)
		for(j=1;j<=j;j
		fac=fac*i;
	printf("%d",fac);
	return 0;}
	*/

/*#include <stdio.h>
int main1() {  }
int main2() { int an1,an2,an3;
	int gu1,gu2,gu3;
	int sum1=0,sum2=0;
	scanf("%d %d %d",&an1,&an2,&an3);
	scanf("%d %d %d",&gu1,&gu2,&gu3);
	if(an1==gu1)
		sum1=sum1+1;
	if(an2==gu2)
		sum1=sum1+1;
	if(an3==gu3)
		sum1=sum1+1;
	if(an1==gu2||an1==gu3)
		sum2=sum2+1;
	if(an2==gu1||an2==gu3)
		sum2=sum2+1;
	if(an3==gu1||an3==gu2)
		sum2=sum2+1;
	printf("%dS%dB",sum1,sum2);
	
	return 0; }
int main3() { int num1,num3;
	char num2;
	int sum;
	scanf("%d %c %d",&num1,&num2,&num3);
	if(num2=='+')
	{	sum=num1+num3;
	printf("%d",sum);}
	else if(num2=='-')
	{	sum=num1-num3;
	printf("%d",sum);}
	return 0;} 
int main() { int pro_num=0;
scanf("%d\n",&pro_num);
switch(pro_num)
{ case 1: main1(); break;
case 2: main2(); break; 
case 3: main3(); break; }
return 0;
}*/
/*{
	int i,j;
	int fac;
	fac=1;
	for (i=2;i<=10;i++){
		printf("%d!=",i);
		for(j=1;j<=i;j++){
		if(j!=i)
			printf("%d*",j);
		else
			printf("%d",i);
		fac=fac*j;
		}
			printf("=%d\n",fac);
	
	fac=1;
	}
	return 0;
}*/




	




		


