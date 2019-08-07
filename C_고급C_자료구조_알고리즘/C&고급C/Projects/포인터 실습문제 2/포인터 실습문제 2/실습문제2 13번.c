#include <stdio.h>
void strcopy(char *parr1,char *parr2){
	int j,*pj=&j;
	for(*pj=0;*pj<6;(*pj)++){
		*(parr2+*pj)=*(parr1+*pj);

	}


}



int main(){
	char ar1[6],ar2[6],i;
	char *par1=ar1,*par2=ar2,*pi=&i;
	for(*pi=0;*pi<6;(*pi)++){
		scanf("%c",par1+*pi);

	}
	strcopy(par1,par2);
	for(*pi=0;*pi<6;(*pi)++){
		printf("%c",*(par2+*pi));

	}




	return 0;
}
