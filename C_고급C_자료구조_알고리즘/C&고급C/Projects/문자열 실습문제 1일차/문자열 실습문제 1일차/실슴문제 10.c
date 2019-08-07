#include <stdio.h>
#include <string.h>
int main(){
	char str1[100],str2[100];
	int cmp;
	scanf("%s",str1);
	scanf("%s",str2);
	cmp=strcmp(str1,str2);
	if(cmp<0){
	strcat(str2,str1);
	printf("%s",str2);

	}
	else if(cmp>=0){
		strcat(str1,str2);
			printf("%s",str1);
	}
	


	return 0;
}