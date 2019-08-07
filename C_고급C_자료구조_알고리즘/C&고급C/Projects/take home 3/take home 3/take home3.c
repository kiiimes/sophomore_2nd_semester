/*#include <stdio.h>
int main()*/
/*{
	int num1,num2,i,j;
	scanf("%d %d",&num1,&num2);
	if(num1>num2){
		for (i=num2;i<=num1;i++){
			for(j=9;j>=1;j--){
				printf(" %d",i*j);
			}
			printf("\n");
		}
	}
	else if(num2>num1)
	{
		for(i=num1;i<=num2;i++){
			for(j=9;j>=1;j--){
				printf(" %d",i*j);
			}
			printf("\n");
		}
	}
	return 0;
}*///4번 문제 클리어!





#include < stdio.h> 
int main1() {
	char num1,num2;
	int i;
	scanf("%c%c",&num1,&num2);
	if(num1<=num2){
		for(i=num1;i<=num2;i++){
			printf("%c",i);
		}
	}
	if(num1>=num2){
		for(i=num1;i>=num2;i--){
			printf("%c",i);
		}
	}
return 0;
}
int main2() {
	int n,i,j,mok=0,namo=0;
	scanf("%d",&n);
	mok=n/10;
	namo=n%10;
	if(n<65||n>90){
		printf("none");}
	else if(n==70||n==80||n==90)
		for(i=1;i<=10;i++){
			for(j=1;j<=mok;j++){
				printf("%c",(char)n);
			}
			printf("\n");
		}
	else if(n>=65&&n<=90){
		for(i=1;i<=namo;i++){
			for(j=1;j<=mok;j++){
				printf("%c",(char)n);
			}
			printf("\n");
		}
		
	}
	return 0;
}

int main3() { 
	int i,n;
	scanf("%d",&n);
	for(i=2;n!=1;i++){
		if(n%i==0){
			printf(" %d",i);
			n=n/i;
			i=1;
		}
	}
	return 0;
		
}
int main4() { 	
	int num1,num2,i,j;
	scanf("%d %d",&num1,&num2);
	if(num1>=num2){
		for (i=num2;i<=num1;i++){
			for(j=9;j>=1;j--){
				printf(" %d",i*j);
			}
			printf("\n");
		}
	}
	else if(num2>=num1)
	{
		for(i=num1;i<=num2;i++){
			for(j=9;j>=1;j--){
				printf(" %d",i*j);
			}
			printf("\n");
		}
	}
	return 0;
} 
int main5() { 
int n,i,j,k,sum=0;
	scanf("%d",&n);
	for(i=1;i<=6;i++){
		for(j=i;j<=6;j++){
			for(k=j;k<=6;k++){
				sum=i+j+k;
				if(sum==n){
					printf("%d %d %d\n",i,j,k);
				}
			}
		}
	}
	return 0;}
int main() { 
	int pro_num=0;
scanf("%d\n",&pro_num);
switch(pro_num){
case 1: main1(); break; 
case 2: main2(); break; 
case 3: main3(); break; 
case 4: main4(); break; 
case 5: main5(); break; 
}
return 0;
}
/*{
	int n,i,j,k,sum=0;
	scanf("%d",&n);
	for(i=1;i<=6;i++){
		for(j=i;j<=6;j++){
			for(k=j;k<=6;k++){
				sum=i+j+k;
				if(sum==n){
					printf("%d %d %d\n",i,j,k);
				}
			}
		}
	}
	return 0;
}*///5번 클리어!








