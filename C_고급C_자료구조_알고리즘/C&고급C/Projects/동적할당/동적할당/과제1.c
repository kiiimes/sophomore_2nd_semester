#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
	int m,n,*pa,*pb,a,i;
	scanf("%d %d",&m,&n);
	if(m>n){
		a=m;
		m=n;
		n=a;
	}
	pa=(int*)calloc(m,sizeof(int));
	pb=(int*)calloc(n,sizeof(int));
	for(i=0;i<m;i++){
		scanf("%d",pa+i);
		printf("%d",pa[i]);
	}
	for(i=0;i<n;i++){
		scanf("%d",pb+i);
		printf("%d",pb[i]);
	}
	for(i=0;i<m;i++){
		pb[i]+=pa[i];
	}
	for(i=0;i<n;i++){
		printf(" %d",pb[i]);
	}

}