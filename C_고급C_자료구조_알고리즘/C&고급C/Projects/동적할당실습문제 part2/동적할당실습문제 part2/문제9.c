#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
	int n,i,min=0;
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

	min=strlen(p[0]);
	strcpy(a,p[0]);

	for(i=0;i<n;i++){
		if(min>strlen(p[i])){
			min=strlen(p[i]);
			strcpy(a,p[i]);
		}
	}
	
	printf("%s",a);






}
