#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
	int n,i,j;
	char **p,a[101];

	scanf("%d",&n);
	getchar();
	p=(char**)malloc(n*sizeof(char*));

	for(i=0;i<n;i++){
		p[i]=(char*)calloc(101,sizeof(char));
	}

	for(i=0;i<n;i++){
		gets(p[i]);
	}

	for(j=0;j<n;j++){
	for(i=0;i<n-1;i++){
		if(strlen(p[i])<strlen(p[i+1])){
			strcpy(a,p[i]);
			strcpy(p[i],p[i+1]);
			strcpy(p[i+1],a);
		}
	}
	}
	
	for(i=0;i<n;i++){
		printf("%s\n",p[i]);
	}






}
