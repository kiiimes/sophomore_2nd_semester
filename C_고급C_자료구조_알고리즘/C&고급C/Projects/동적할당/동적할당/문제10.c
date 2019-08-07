#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
	int n,i,st,j;
	char **p,a[101];
	scanf("%d",&n);
	getchar();
	p=(char**)malloc(n*sizeof(char*));

	for(i=0;i<n;i++){
		gets(a);
		st=strlen(a);
		p[i]=(char*)malloc((st+1)*sizeof(char));
		strcpy(p[i],a);
	}

	for(i=0;i<n;i++){
		for(j=0;j<n-1;j++){
			if(strlen(p[j])<strlen(p[j+1])){
				strcpy(a,p[j]);
				st=strlen(p[j+1]);
				p[j]=(char*)malloc((st+1)*sizeof(char));
				strcpy(p[j],p[j+1]);
				st=strlen(a);
				p[j+1]=(char*)malloc((st+1)*sizeof(char));
				strcpy(p[j+1],a);

			}
		}

	}

	for(i=0;i<n;i++){

		printf("%s\n",p[i]);
		free(p[i]);
	}
	free(p);




}