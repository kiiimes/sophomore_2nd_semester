#include <stdio.h>
#include <stdlib.h>
int main(){
	float *p,max;
	int i,n;
	scanf("%d",&n);
	p=(float*)malloc(n*sizeof(float));
	for(i=0;i<n;i++){
		scanf("%f",p+i);
	}
	max=*p;
		for(i=0;i<n;i++){
		if(max<*(p+i)){
			max=*(p+i);
		}
	}
		printf("%.2f",max);
	
		free(p);

	return 0;
}
