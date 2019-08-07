#include <stdio.h>
int arrsum(int *parr,int pn){
	int i,sum=0;

	for(i=0;i<pn;i++){
		sum+=*(parr+i);
	}
	return sum;
}


int main(){
	int n,arr[100],i;

	scanf("%d",&n);

	for(i=0;i<n;i++){
		scanf("%d",arr+i);
	}

	printf("%d",arrsum(arr,n));



	return 0;
}