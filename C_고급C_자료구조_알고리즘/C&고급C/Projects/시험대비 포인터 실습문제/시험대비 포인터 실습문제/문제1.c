#include <stdio.h>
int main(){
	int x,*p=&x;


	scanf("%d",&x);

	scanf("%d",p);

	printf("%d",*p);




	return 0;
}