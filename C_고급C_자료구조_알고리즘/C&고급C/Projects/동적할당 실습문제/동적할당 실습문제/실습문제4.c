#include <stdio.h>
#include <stdlib.h>
int main(){
	int hang,yeol,**p,i,j;
	scanf("%d %d",&yeol,&hang);
	p=(int**)malloc(hang*sizeof(int*));
	for(i=0;i<hang;i++){
		p[i]=(int*)malloc(yeol*sizeof(int));
	}
	p[0][0]='a';
	for(i=0;i<hang;i++){
		for(j=0;j<yeol;j++){
			p[i][j]=p[i][j-1]+1;
		}
		p[i]

	}

	return 0;
}