/*#include <stdio.h>
int add(int num1, int num2);

int main()
{
	int nNum1, nNum2;

	printf("정수 입력 >> ");
	scanf("%d %d",&nNum1,&nNum2);

	printf("%d\n",add(nNum1,nNum2));
	return 0;
}

int add(int num1, int num2)
{
	int nResult=0;

	nResult=num1+num2;
	
	return nResult;
}//실습문제2
int sum(int n)
{
	int z;
	z=n*(n+1)/2;

	return z;}
int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	printf("%d",sum(b)-sum(a)+a);
return 0;
}
int sum2(int n)
{
	int i,z,s=0;
	for(i=1;i<=n;i++){
		
		z=i*(i+1)/2;
		s=s+z;
		
	}
	return s;
}

int main()
{
	int num1;
	scanf("%d",&num1);
	printf("%d",sum2(num1));
	return 0;
}
void print_row1(int x)
{
	int i;
	for(i=1;i<=x;i++){
		printf("%d",x);
	}
}
void print_row2(int x)
{
	int i;
	printf("%d",x);
	for(i=1;i<=(x-2);i++){
		printf(" ");
	}
	printf("%d",x);
}
int main()
{
	int a,i;
	scanf("%d",&a);
	print_row1(a);
	for(i=1;i<=(a-2);i++){
		printf("\n");
		print_row2(a);
	}
	printf("\n");
	print_row1(a);
	return 0;
}
void print_triangle(int x)
{
	int i,j;
	for(i=1;i<=x;i++){
		for(j=1;j<=i;j++){
			printf("*");
		}
		printf("\n");
	}
}
int main()
{
	int a,i;
	for(i=1;;i++)
	{
		scanf("%d",&a);
		if(a<=0){
			break;}
		else if(a>0){
			print_triangle(a);}
	}
	
	return 0;
}
int func1(int x)
{
	int z;
	z=2*x*x-5*x+1;
	return z;
}
int main()
{
	int a;
	scanf("%d",&a);
	printf("%d",func1(a));
	return 0;
}
int func2(int x,int a,int b,int c)
{
	int z;
	z=a*x*x+b*x+c;
	return z;
}
int main()
{
	int num1,num2,num3,num4;
	scanf("%d %d %d %d",&num1,&num2,&num3,&num4);
	printf("%d",func2(num1,num2,num3,num4));
	return 0;
}
int main()
{
	int n1,n2,n3,n4,n5,n6,n7,z;
	scanf("%d %d %d %d %d %d %d",&n1,&n2,&n3,&n4,&n5,&n6,&n7);
	z=func2(n1,n2,n3,n4);
	printf("%d",func2(z,n5,n6,n7));
	return 0;
}*/

#include <stdio.h>

int add(int x, int y)
{
	int nResult=0;

	nResult=x+y;
	
	return nResult;
}
int main1() { 
	int n,i,s=0;
	for(i=1;i<=n;i++)
	{
		s=add(s,i);
	}
	printf("%d",s);

}
int sum(int n)
{
	int z;
	z=n*(n+1)/2;

	return z;}
int main2() { 
		int a,b;
	scanf("%d %d",&a,&b);
	printf("%d",sum(b)-sum(a)+a);
return 0;
}

int sum2(int n)
{
	int i,z,s=0;
	for(i=1;i<=n;i++){
		
		z=i*(i+1)/2;
		s=s+z;
		
	}
	return s;
}
int main3() { 

	int num1;
	scanf("%d",&num1);
	printf("%d",sum2(num1));
	return 0;
}

void print_row1(int x)
{
	int i;
	for(i=1;i<=x;i++){
		printf("%d",x);
	}
}
void print_row2(int x)
{
	int i;
	printf("%d",x);
	for(i=1;i<=(x-2);i++){
		printf(" ");
	}
	printf("%d",x);
}
int main4(){
	int a,i;
	scanf("%d",&a);
	print_row1(a);
	for(i=1;i<=(a-2);i++){
		printf("\n");
		print_row2(a);
	}
	printf("\n");
	print_row1(a);
	return 0;
}

	void print_triangle(int x)
{
	int i,j;
	for(i=1;i<=x;i++){
		for(j=1;j<=i;j++){
			printf("*");
		}
		printf("\n");
	}
}
int main5(){
	
	int a,i;
	for(i=1;;i++)
	{
		scanf("%d",&a);
		if(a<=0){
			break;}
		else if(a>0){
			print_triangle(a);}
	}
	
	return 0;
}

int func1(int x)
{
	int z;
	z=2*x*x-5*x+1;
	return z;
}
int main6(){
	
	int a;
	scanf("%d",&a);
	printf("%d",func1(a));
	return 0;
}

int func2(int x,int a,int b,int c)
{
	int z;
	z=a*x*x+b*x+c;
	return z;
}
int main7(){

	int num1,num2,num3,num4;
	scanf("%d %d %d %d",&num1,&num2,&num3,&num4);
	printf("%d",func2(num1,num2,num3,num4));
	return 0;
}

int main8()
{
	int n1,n2,n3,n4,n5,n6,n7,z;
	scanf("%d %d %d %d %d %d %d",&n1,&n2,&n3,&n4,&n5,&n6,&n7);
	z=func2(n1,n2,n3,n4);
	printf("%d",func2(z,n5,n6,n7));
	return 0;
}







	int main() {
		int pro_num=0;
scanf("%d\n",&pro_num);
switch(pro_num){ 
case 1: main1(); break; 
case 2: main2(); break; 
case 3: main3(); break; 
case 4: main4(); break; 
case 5: main5(); break; 
case 6: main6(); break; 
case 7: main7(); break; 
case 8: main8(); break; 
}
return 0;
}











