#include <stdio.h>
int main()
{
	int n,num1,num2,sum=0;
	int num3,num4=10;
	scanf("%d",&n);
	while(num4>=10){
		while(n!=0){
			num1=n%10;
			num2=n/10;
			sum+=num1;
			n=num2;}
		num3=sum/10;
		num4=sum%10;
	}

	printf("%d",num3+num4);
	return 0;
}
