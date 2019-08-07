#include <stdio.h>
int main(){
	char st[21];
	int i;
	
	scanf("%s",st);

	for(i=0;st[i]!='\0';i++){
		if(st[i]>='a'&&st[i]<'=z'){
			printf("%c",st[i]);
		}
	}

	return 0;
}