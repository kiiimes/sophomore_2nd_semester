#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main(){
	int n,i,j;
	char **p,a[101];
	scanf("%d",&n);
	getchar();
	p=(char**)malloc(n*sizeof(char*));
	for(i=0;i<n;i++){
		gets(a);
		p[i]=(char*)malloc((strlen(a)+1)*sizeof(char));
		strcpy(p[i],a);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n-1;j++){
			if(p[j]<p[j+1]){
				strcpy(a,p[j]);
				p[j]=(char*)realloc(p,(strlen(p[j+1])+1)*sizeof(char));
				strcpy(p[j],p[j+1]);
				p[j+1]=(char*)realloc(p,(strlen(a)+1)*sizeof(char));
				strcpy(p[j+1],a);
			}

		}


	}
	for(i=0;i<n;i++){
		printf("%s",p[i]);
		free(p[i]);

	}
	free(p);
	




}