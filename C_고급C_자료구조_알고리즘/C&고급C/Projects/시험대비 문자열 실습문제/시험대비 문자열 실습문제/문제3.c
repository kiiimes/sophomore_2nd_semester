#include <stdio.h>
#include <string.h>

int main(){
	char arr[101]={NULL};
	int i,st,j,k;

	scanf("%s",arr);

	st=strlen(arr);

	printf("%s\n",arr);
	for(i=0;arr[i]!='\0';i++){
		

		for(j=i+1;j<st;j++){
			sav=str[i];
			str[j-1]=str[j];
			
		}
		for(k=0;k<=i;k++){
			printf("%c",arr[k]);
		}
		printf("\n");
	}



	return 0;
}