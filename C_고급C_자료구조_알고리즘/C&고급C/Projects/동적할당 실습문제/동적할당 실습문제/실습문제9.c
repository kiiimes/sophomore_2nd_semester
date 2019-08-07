#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int n,i,j;
	char str[101],*p=str,min[101]={NULL};
	
	scanf("%d",&n);
	getchar();
	p=(char*)malloc(n*sizeof(char));

	for(i=0;i<n;i++){
		gets(p+i);
	}
	strcpy(min,p+0);

	
		for(j=0;j<n-1;j++){
			if(strlen(min)>strlen(p+j)){
				strcpy(min,p+j);
			}
	}
	printf("%s",min);
	
	


	

	
	return 0;
}