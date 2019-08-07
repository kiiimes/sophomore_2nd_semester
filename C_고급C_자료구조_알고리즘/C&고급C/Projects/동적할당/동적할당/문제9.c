#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
	int n,i,st,cnt,j;
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
		cnt=1;
		for(j=0;j<n;j++){
			
			if(strlen(p[i])>strlen(p[j]))cnt++;
		}
		if(cnt==1){

			printf("%s",p[i]);
			break;
			
		}
	}
	
	for(i=0;i<n;i++){
		free(p[i]);
	}
	free(p);

}