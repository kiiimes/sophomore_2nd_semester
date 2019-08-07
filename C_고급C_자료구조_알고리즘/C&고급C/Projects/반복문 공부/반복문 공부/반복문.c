#include <stdio.h>
int main()
	/*{
	int count;
	for( count=0;count<5;count++){
	if(count==3)
	break;
	}
	printf("%d",count);
	return 0;}*/
	/*{
	int num1,num2;
	int sum=0;
	scanf("%d",&num1);
	for(num2=1;num2<=num1;num2++){
	sum+=num2;
	if(sum>100)
	break;
	}
	printf("%d",sum);
	return 0;}*/
	/*{
	int i,j;
	int count1;
	int count2=0;
	for(i=2;i<=50;i++)
	{	

	count1=0;
	for(j=2;j<=i;j++)
	{	if(i%j==0)
	count1++;
	}
	if(count1==1){
	printf("%d ",i);
	count2++;}
	if(count2%5==0)
	printf("\n");

	}
	return 0;}*///중첩 반복문 소수
	/*{
	int i,j,k,s;
	scanf("%d",&i);

	for(j=1;j<=i;j++){
	for(k=1;k<=i-j;k++)
	printf(" ");
	for(s=1;s<=j;s++)
	printf("* ");
	printf("\n");
	}
	return 0;
	}*/
	/*{
	int i,j,k,s,z;
	scanf("%d",&i);

	for(j=1;j<=i;j++){
	for(k=1;k<=i-j;k++)
	printf(" ");
	for(s=1;s<=2*j-1;s++)
	printf("*");
	for(z=1;z<=i-j;z++)
	printf(" ");
	printf("|\n");
	}
	return 0;}*/
	/*{
	int i,j,k,z;
	int s;
	for(i=1;i<=9;i++){
	for(j=1;j<=9-i;j++)
	printf(" ");
	s=9;
	for(k=1;k<=i;k++){
	z=10-i;			
	printf("%d",s);
	s=z+1;}//실습문제 6*/
	/*{
	int num1,num2;
	int i,j,z;
	scanf("%d %d",&num1,&num2);
	if(num1>num2)
	i=num2;
	else
	i=num1;
	for(j=1;j<=i;j++){
	if(num1%j==0&&num2%j==0){
	z=j;
	}
	}
	printf("%d",z);
	return 0;
	}*/
	/*
	{
	int i,j,z=1;
	for(i = 1; i <= 10; i++)
	{
	for (j = i; j <= i+9 ; j++)
	{
	printf(" %d",j%10);
	}
	printf("\n");
	}
	return 0;
	}
	*/

	/*{
	int n,i,j,a=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
	for(j=1;j<=i;j++){
	a++;
	printf(" %d",a%10);}
	printf("\n");
	}
	return 0;}*/
	/*{
	int i,j,k,n,sum=0;
	scanf("%d",&n);
	for( i=1;i<=6;i++){
	for(j=1;j<=6;j++){
	for(k=1;k<=6;k++){
	sum=i+j+k;
	if(sum==n)
	{
	printf("%d %d %d\n",i,j,k);
	}
	}
	}
	}
	return 0;
	}*/
	/*{
	int n,i,j,sum=0;
	scanf("%d",&n);
	for(i=1;;i++){
	sum+=i;
	if(i==n)

	break;}
	printf("%d",sum);
	return 0;}*/
{
	int i;
	for(i=1;i<=10;i++){
		if(i%2!=0)
			continue;
		printf("\n%d",i);
	}
}


















