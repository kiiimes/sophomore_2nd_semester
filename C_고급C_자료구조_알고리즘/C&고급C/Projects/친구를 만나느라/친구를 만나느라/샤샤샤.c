#include <stdio.h>
int max1=0;
int max2=0;
void update(int);
int main9()
{
   int N;
   while(1){
      scanf("%d",&N);
      if(N==0)
         break;
      update(N);
   }
   if(max1!=0) printf("%d",max1);
   if(max2!=0) printf(" %d",max2);
   printf("\n");
}
void update(int N)
{
   if(N>max1||max1==0){
      max2=max1;
      max1=N;
   }
   else if(N>max2||max2==0){
      max2=N;
   }
}

int n;
void die3(int x,int y,int z){
	int sum=0;
		sum=x+y+z;
		if(n==sum){
			printf("%d %d %d\n",x,y,z);
		}
	}


void die2(int x,int y){
	int k;
	for(k=1;k<=6;k++){
		die3(x,y,k);
	}
}



void die1(int x){
	int j;
	for(j=1;j<=6;j++){
		die2(x,j);
	}
}
	
int main10(){
	int i;
	scanf("%d",&n);
	for(i=1;i<=6;i++){
		die1(i);
	}
	return 0;

}


int an1,an2,an3;
int count_strike(int x,int y,int z){

	int count1=0;
	if(an1==x){
		count1++;
	}
	if(an2==y){
		count1++;
	}
	if(an3==z){
		count1++;
	}
	return count1;

}
int count_ball(int x,int y,int z){
	int count2=0;
	if(an1==y)
	{
		count2++;
	}
		if(an1==z)
	{
		count2++;
	}
		if(an2==x)
	{
		count2++;
	}
		if(an2==z)
	{
		count2++;
	}
		if(an3==y)
	{
		count2++;
	}
		if(an3==x)
	{
		count2++;
	}
		return count2;
}

int main11(){
	
	int gu1,gu2,gu3;
	int i;
	int strike;
	scanf("%d %d %d",&an1,&an2,&an3);
	for(i=1;;i++){
		scanf("%d %d %d",&gu1,&gu2,&gu3);
		strike=count_strike(gu1,gu2,gu3);
		printf("%dS%dB",strike,count_ball(gu1,gu2,gu3));
		printf("\n");
		if(strike==3){
			break;
		}
	}


}

void print_line(int x,int y,int z){
	int j,k,s;
	for(j=1;j<=x;j++){
		printf(" ");
	}
	for(k=1;k<=y;k++){
		printf("*");
	}
	for(s=1;s<=z;s++){
		printf(" ");
	}
}
int main12(){
	int i,num1;
	scanf("%d",&num1);
	for(i=1;i<=num1;i++){
		print_line(num1-i,i*2-1,num1-i);
		printf("\n");

	}
	return 0;
}
int count_3(int x)
{
	int count3 = 0;
	while (1)
	{
		if (x % 10 == 3) 
		count3++;
		x = x / 10;
		if (x == 0) break;
	}
	return count3;
}

int main13(){

	int x,i,count=0;
	scanf("%d",&x);
	for(i=1;i<=x;i++){
		count=count+count_3(i);
	}
	printf("%d",count);
	return 0;
}


int is_prime(int x);
int next_prime(int x);
int main14()
{
   int N,M,i;
   scanf("%d %d",&N,&M);
   for(i=1;i<=M;i++){
      N=next_prime(N);
      printf(" %d",N);
   }
   return 0;
}

int is_prime(int x)
{
   int i;
   for(i=2;i<x;i++){
      if(x%i==0)
         return 0;
}
   return 1;
}

int next_prime(int x)
{
   while(1){
      x++;
      if(is_prime(x))
         return x;
   }
}
int main()
{
	int pro_num=0;
	scanf("%d\n",&pro_num);
	switch(pro_num){
	case 9:main9(); break;
	case 10:main10(); break;
	case 11:main11(); break;
	case 12:main12(); break;
	case 13:main13(); break;
	case 14:main14(); break;
	
	}
}