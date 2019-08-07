#include <stdio.h>
int main(){
	int n,max,min,i,j,arr[100],a;
	int *pn=&n,*pj=&j,*pmax=&max,*pmin=&min,*pi=&i,*pa=&a;

	scanf("%d",pn);

	for(*pi=0;*pi<*pn;(*pi)++){

		scanf("%d",arr+*pi);

	}
	for(*pi=0;*pi<*pn;(*pi)++){
		*pa=1;
		for(*pj=0;*pj<*pn;(*pj)++){
			if(*(arr+*pi)>*(arr+*pj)){
				(*pa)++;

			}

		}
		if(*pa==*pn){
			*pmax=*(arr+*pi);
		}
		else if(*pa==1){
			*pmin=*(arr+*pi);
		}

		

	}
	printf("%d %d",*pmax,*pmin);
	






	return 0;
}