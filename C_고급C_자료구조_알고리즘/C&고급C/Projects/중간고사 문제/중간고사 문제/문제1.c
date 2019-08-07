#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int add_to_k(int *pa,int *pb){
	int *p,sum,*psum=&sum;

	for(p=pa;p<=pb;p++){
		(*psum)+=(*p);
	}
	return *psum;
}


void main(){
	int n,d[100],i;
	scanf("%d",&n);

	for(i=0;i<n;i++){
		scanf("%d",d+i);
	}

	for(i=0;i<n;i++){
		add_to_k(d,d+i);
	}

	

}