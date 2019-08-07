#include <stdio.h>

int main(){
	int i,lena,lenb,a;
	char ara[20],arb[20];

	scanf("%s",ara);
	scanf("%s",arb);

	for(i=0;ara[i]!=0;i++){

	}
	lena=i;

	for(i=0;arb[i]!=0;i++){
	}
	lenb=i;

	if(lena>=lenb){
		for(i=0;arb[i]!=0;i++){
			printf("%c%c",ara[i],arb[i]);

		}

		a=i;

		for(i=a;ara[i]!=0;i++){
			printf("%c",ara[i]);

		}

	}

	else if(lena<lenb){
		for(i=0;ara[i]!=0;i++){
			printf("%c%c",ara[i],arb[i]);

		}

		a=i;

		for(i=a;arb[i]!=0;i++){
			printf("%c",arb[i]);

		}

	}
	


	return 0;
}