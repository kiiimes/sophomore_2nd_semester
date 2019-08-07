#include <stdio.h>
void sum(int *ps,int a,int b){
	*ps=a+b;
}




int main(){
	int num1,num2,suum;
	int *pnum1=&num1,*pnum2=&num2,*psum=&suum;
	scanf("%d %d",pnum1,pnum2);
	sum(psum,*pnum1,*pnum2);
	printf("%d",*psum);

	return 0;
}