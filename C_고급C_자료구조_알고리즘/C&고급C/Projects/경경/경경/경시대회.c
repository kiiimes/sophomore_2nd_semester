#include <stdio.h>
int main(){
	int n,i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++){
	
		for(j=n-i;j>0;j--){
			printf("*");
		}
		printf("\n");
	}


	return 0;
}