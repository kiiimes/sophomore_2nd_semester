#include <stdio.h>
int arrsum(int *par,int *pnn){
	int j,*pj=&j,sum=0,*psum=&sum;
	for(*pj=0;*pj<*pnn;(*pj)++){
		*psum+=*(par+*pj);
	}
	return *psum;
}



int main(){
	int n,arr[100],i;
	int *pn=&n,*parr=arr,*pi=&i;
	scanf("%d",pn);
	for(*pi=0;*pi<*pn;(*pi)++){
		scanf("%d",parr+*pi);

	}
	printf("%d",arrsum(parr,pn));



	return 0;
}