#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main(){
	int n,i,j;
	char **p,a[101],*temp;
	scanf("%d",&n);
	getchar();
	p=(char**)malloc(n*sizeof(char*));
	for(i=0;i<n;i++){
		scanf("%s",a);
		p[i]=(char*)malloc((strlen(a)+1)*sizeof(char));
		strcpy(p[i],a);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n-1;j++){
			if(strcmp(p[j],p[j+1])>0){
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;

			}

		}
	}

	for(i=0;i<n;i++){
		printf("%s",p[i]);
		free(p[i]);

	}
	free(p);


}