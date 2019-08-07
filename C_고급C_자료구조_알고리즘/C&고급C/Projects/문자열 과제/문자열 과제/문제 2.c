#include <stdio.h>
#include <string.h>
int main(){
	char ara[20]={NULL},arb[20]={NULL};
	char chara[20]={NULL},charb[20]={NULL};

	int lena,lenb,i;

	scanf("%s",ara);
	scanf("%s",arb);

	lena=strlen(ara);
	lenb=strlen(arb);

	for(i=0;i<lena;i++){
		chara[i]=ara[lena-1-i];
	}
	for(i=0;i<lenb;i++){
		charb[i]=arb[lenb-1-i];
	}

	printf("%d %d %s %s",lena,lenb,chara,charb);





	return 0;
}