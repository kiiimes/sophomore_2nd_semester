#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
	int m,n,*psum,*pa,i;
	scanf("%d %d",&m,&n);
	if(m>n){
		psum=(int*)calloc(m,sizeof(int));
	}
	else
		psum=(int*)calloc(n,sizeof(int));
	pa=(int*)calloc(m,sizeof(int));
	
	for(i=0;i<m;i++){
		scanf("%d",pa+i);
		psum[i]=pa[i];
	}
	pa=(int*)calloc(n,sizeof(int));
	for(i=0;i<n;i++){
		scanf("%d",pa+i);
		psum[i]+=pa[i];
	}
	if(m>n){
		for(i=0;i<m;i++){
			printf(" %d",psum[i]);
		}
	}
	else{
		for(i=0;i<n;i++){
			printf(" %d",psum[i]);
		}
	}

	free(psum);
	free(pa);
	

}