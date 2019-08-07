#include <stdio.h>
int main(){
	int n,i,m,arr[100];
	int *pn=&n,*pi=&i,*pm=&m;

	scanf("%d",pn);

	for(*pi=0;*pi<*pn;(*pi)++){
		scanf("%d",arr+*pi);

	}

	scanf("%d",pm);

	printf("%d",*(arr+(*pm)));

	


	return 0;
}