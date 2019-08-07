#include <stdio.h>

int main(){
	char arr[21];
	int i,j;
	int *pi=&i,*pj=&j;

	scanf("%s",arr);

	for(*pi=0;;(*pi)++){
		if(*(arr+*pi)=='#'){
			for(*pj=*pi-1;*pj>=0;(*pj)--){
				printf("%c",*(arr+*pj));
				
			}
			break;
		}
	}




	return 0;
}