#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
	int *p,a=5,i;

	p=(int*)malloc(a*sizeof(int));

	for(i=0;;i++){
		
		scanf(" %d",p+i);
		if(p[i]==-1){
			break;
		}
		if(i%3==1){
			a+=3;
			p=(int*)realloc(p,a*sizeof(int));
		}
	}
	for(i=0;;i++){
		printf(" %d",p[i]);
		if(p[i]==-1){
			break;
		}
	}

	free(p);
	


}