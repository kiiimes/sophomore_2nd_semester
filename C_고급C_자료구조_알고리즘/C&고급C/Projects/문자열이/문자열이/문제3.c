#include <stdio.h>
#include <string.h>

int main(){
	char str[200]={NULL};
	int i,st,j,a;
	
	scanf("%s",str);

	printf("%s",str);

	st=strlen(str);
	for(i=0;i<st;i++){
		for(j=0;j<st;j++){
		a=st-j;
		str[a]=str[j];
		str[j]=str[i+j];
		}
		printf("%s\n",str);
	}

	


	return 0;
}