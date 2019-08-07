#include <stdio.h>
#include <string.h>

int main(){
	char str1[50]={NULL},str2[50]={NULL};
	int a;

	scanf("%s %s",str1,str2);

	a=strcmp(str1,str2);


	return 0;
}