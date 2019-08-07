#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
	int n,*p,i,m,j;
	scanf("%d",&n);
	p=(int*)malloc(n*sizeof(int));
	m=n-1;
	for(i=0;i<n;i++){
		p[i]=i;
	}
	for(i=0;i<n;i++){
		if(p[i]==n/2){
			for(j=i;j<n-1;j++){
				p[j]=p[j+1];

			}
			p=(int*)realloc(p,m*sizeof(int));
			break;
		}
	}

	for(i=0;i<m;i++){
		printf(" %d",p[i]);
	}
	free(p);
}