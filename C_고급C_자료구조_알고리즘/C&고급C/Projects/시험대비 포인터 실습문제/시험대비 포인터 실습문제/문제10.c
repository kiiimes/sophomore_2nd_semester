#include <stdio.h>
int a,b;
void swap(int *parr,int *pn){
	int temp;

		temp=*(parr+a);
		*(parr+a)=*(parr+b);
		*(parr+b)=temp;
	}


int main(){
	int arr[50],i,n;
	
	scanf("%d",&n);

	for(i=0;i<n;i++){

		scanf("%d",arr+i);
	}

	scanf("%d %d",&a,&b);
	swap(arr,&n);
	for(i=0;i<n;i++){
		printf(" %d",*(arr+i));
	}

	return 0;
}