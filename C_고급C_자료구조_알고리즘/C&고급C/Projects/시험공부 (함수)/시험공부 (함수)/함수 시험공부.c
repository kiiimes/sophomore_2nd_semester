#include <stdio.h>
int max(int a,int b){
	int m;
	if(a>=b)
		m=a;
	else
		m=b;
	return m;

}
void print_characters(char c,int n){
	int i;
	for(i=1;i<=n;i++){
		printf("%c",c);

	}

}
double divide(int a,int b){
	double z;
	z=(double)a/b;
	return z;

}
float add3(float a, float b, float c){
	float sum;
	sum=a+b+c;
	return sum;
}
char atoA(char ch){
	char z;
	if(ch>='a'&&ch<='z')
	z='A'+(ch-'a');
	else
		z=ch;
	return z;

}
int add(int x, int y){
	int z=-1;
	printf("add start:x=%d,y=%d,z=%d\n",x,y,z);
	z=x+y;
	printf("add end: x=%d, y=%d, z=%d\n",x,y,z);
	return z;
	}
int add1(int x,int y){
	return x+y;
}


int func(int a,int b){
	int z=add1(a,b);
	if(z>0) return 1;
	if(z<0) return -1;
	return 0;
}
int c;

int div(int a,int b){
	a/b

}




int main()
{
	

}