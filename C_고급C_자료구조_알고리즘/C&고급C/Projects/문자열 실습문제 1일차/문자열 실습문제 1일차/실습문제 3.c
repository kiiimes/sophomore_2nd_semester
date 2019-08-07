#include <stdio.h>
#include <string.h>
int main(){
	char ch[100];
	int i,j,k,len;
	scanf("%s",ch);
	len=strlen(ch);
	printf("%s\n",ch);
	for(i=1;i<len;i++){
		for(j=i;j<len;j++){
			printf("%c",ch[j]);
			
		}
		for(k=0;k<i;k++){
			printf("%c",ch[k]);
		}
		
		printf("\n");

	}


	return 0;
}