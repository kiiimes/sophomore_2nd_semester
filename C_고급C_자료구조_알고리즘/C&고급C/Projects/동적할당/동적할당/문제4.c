#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
	int n1,n2,i,j;
	char sav='a'-1,**p;
	scanf("%d %d",&n1,&n2);
	p=(char**)malloc(n2*sizeof(char*));

	for(i=0;i<n2;i++){
	p[i]=(char*)malloc(n1*sizeof(char));
	}

	for(i=0;i<n2;i++){
		for(j=0;j<n1;j++){
			sav++;
			if(sav=='z'){
				p[i][j]=sav;
				sav='A'-1;
			}
			else if(sav=='Z'){
				p[i][j]=sav;
				sav='a'-1;
			}
			else{
				p[i][j]=sav;
			}
			
		}
	}
	for(i=0;i<n2;i++){
		for(j=0;j<n1;j++){
		printf("%c ",p[i][j]);
	}
		printf("\n");
	}



}