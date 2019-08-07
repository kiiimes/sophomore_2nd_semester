#include <stdio.h>
int main(){
	int a,i,s;
	char sav[100]={NULL};
	scanf("%d",&a);
	for(i=0;;i++){


		sav[i]='0'+a%10;
		a=a/10;


		if(a==0){

			break;
		}


	}
	printf("%s",sav);
	return 0;
}