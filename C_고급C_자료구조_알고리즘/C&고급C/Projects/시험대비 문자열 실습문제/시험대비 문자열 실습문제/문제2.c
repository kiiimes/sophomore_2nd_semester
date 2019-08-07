#include <stdio.h>
int main(){
	int a,i;
	char st[10]={NULL};

	scanf("%d",&a);

	for(i=0;;i++){
		st[i]='0'+a%10;
		a=a/10;
		if(a==0){
			break;
		}
	}
	printf("%s",st);


	return 0;
}