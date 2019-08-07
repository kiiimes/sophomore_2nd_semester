#include <stdio.h>
int main(){
	int n,m,i,sum=0;
	int *pn=&n,*pm=&m,*psum=&sum,*pi=&i;

	scanf("%d %d",pn,pm);

	
	for(*pi=*pn;*pi<=*pm;(*pi)++){
	
		*psum+=*pi;
	}
	printf("%d",*psum);

	



	return 0;
}