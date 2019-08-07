#include <stdio.h>
void abc(int *parr,int pk){
	int i,temp,max;
	max=parr[pk];
	for(i=pk;i<10;i++){
		if(parr[pk]<parr[i]){
		max=parr[pk];
		parr[pk]=parr[i];
		parr[i]=max;
		}
	}
	
}

int main(){
	int arr[10]={0},k=0,i;

	for(i=0;i<10;i++){
		scanf("%d",arr+i);
	}

	for(i=0;i<10;i++){
		abc(arr,k);
		k++;
		printf(" %d",arr[i]);
	
	}
	


	return 0;
}