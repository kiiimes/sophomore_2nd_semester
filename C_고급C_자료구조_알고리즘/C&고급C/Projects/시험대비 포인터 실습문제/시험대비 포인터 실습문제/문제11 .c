#include <stdio.h>
int a,b;
void sum(int *p,int na,int nb){
	*p=na+nb;
}

int main(){
	int tsum;

	
	scanf("%d %d",&a,&b);
	sum(&tsum,a,b);
	printf("%d",tsum);


	return 0;
}