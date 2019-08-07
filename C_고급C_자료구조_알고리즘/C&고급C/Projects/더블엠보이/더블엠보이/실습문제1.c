#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
	int n,*p,i,sum=0;

	scanf("%d",&n);

	p=(int*)malloc(n*sizeof(int));

	for(i=0;i<n;i++){
		scanf("%d",p+i);
		sum+=p[i];	

}
	printf("%d",sum);
}