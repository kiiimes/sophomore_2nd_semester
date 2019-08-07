#include <stdio.h>
int main(){
	int num1,num2,i,j,ar1;
	scanf("%d %d",&num1,&num2);
	for(i=0;i<num1;i++){
		ar1=i;
		for(j=1;j<=num2;j++){
			printf("%d",ar1);
			ar1++;
		}
		printf("\n");
	}



	return 0;
}