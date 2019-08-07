#include <stdio.h>

int max(int a,int b)
{
	if(a>b)
	{
		return a;
	}
	else{
		return b;
	}
	
	}

void print_characters(char c,int n)
{
	int i;
	for(i=1;i<=n;i++){
		printf("%c",c);
	}
}
double divide(int a,int b)
{
	 double z;
	 z=(double)a/b;
	 return z;

	 //return (double)a/b;
}
float add3(float a,float b, float c)
{
	return a+b+c;
}
char atoA(char ch)
{
	char z;
	if(ch>='a'&&ch<='z'){
		z= 'A'+(ch-'a');
	}
	else if(ch>='A'&&ch<='Z'){
		z=ch;
	}
	return z;
}
/*int main()
{
	int i,a,b;
	for(i=1;i<=26;i++){
		a='a',b=1;
		print_characters(a,b);
		a++;
		b++;
		printf("\n");
	}
	return 0;
}*/
int add(int su,int min);//헤더만 앞에다가 쫙 써놓으면 쓰기가 편함
/*int main(){
	int c;
	c=add(3,4);
	printf("%d",c);
}*/
int add(int x,int y){
	int z;
	z=x+y;
	return z;
}
/*int atoA(char ch);
int main()
{
	int i;
	char a;
	for(i=1;i<=10;i++){
		scanf("%c",&a);
		printf("%c",atoA(a));
	
}
	return 0;
}*/




























