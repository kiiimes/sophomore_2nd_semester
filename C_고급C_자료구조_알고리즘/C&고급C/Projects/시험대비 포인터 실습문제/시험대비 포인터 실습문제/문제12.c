#include <stdio.h>
int findeven(int *parr,int pn){
	int count=0,i;
	for(i=0;i<pn;i++){
		if(*(parr+i)%2==0){
			count++;
		}
	}
	return count;
}


int main(){
	int n,arr[100],i;

	scanf("%d",&n);

	for(i=0;i<n;i++){
		scanf("%d",arr+i);
	}
	printf("%d",findeven(arr,n));

	return 0;
}