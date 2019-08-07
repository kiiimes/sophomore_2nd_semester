#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
	int n,i,st,j;
	char**p,a[21]={'NULL'},sav={'NULL'};
	
	scanf("%d",&n);
	getchar();

	p=(char**)malloc(n*sizeof(char*));

	for(i=0;i<n;i++){
		scanf("%s",a);
		st=strlen(a);
		p[i]=(char*)malloc((st+1)*sizeof(char));
		strcpy(p[i],a);
		
		
	}
	getchar();
	scanf("%c",&sav);
	
	
	for(i=0;i<n;i++){
		for(j=0;p[i][j]!='\0';j++){
		if(p[i][j]==sav){
			printf("%s\n",p[i]);
		break;
		}
		}
	}
	for(i=0;i<n;i++){
		free(p[i]);
	}
	free(p);

}