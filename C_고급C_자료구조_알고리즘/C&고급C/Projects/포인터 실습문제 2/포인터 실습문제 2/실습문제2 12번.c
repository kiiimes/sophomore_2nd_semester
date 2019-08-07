#include <stdio.h>
int fideven(int *par,int*pnn){
	int j,*pj=&j,count,*pcount=&count;
	*pcount=0;
	for(*pj=0;*pj<*pnn;(*pj)++){
		if(par[*pj]%2==0){
			*pcount=(*pcount)+1;
		}
	}
	return *pcount;
}



int main(){
	int n,arr[100],i;
	int *pn=&n,*parr=arr,*pi=&i;
	scanf("%d",pn);
	for(*pi=0;*pi<*pn;(*pi)++){
		scanf("%d",&parr[*pi]);
	}
	printf("%d",fideven(parr,pn));



	return 0;
}