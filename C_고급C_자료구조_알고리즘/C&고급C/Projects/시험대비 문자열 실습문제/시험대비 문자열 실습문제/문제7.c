#include <stdio.h>
#include <string.h>

int main(){
	int n,i,st,min,j;
	char str[200]={NULL},a[200]={NULL};

	scanf("%d",&n);
	getchar();
	gets(str);
		min=strlen(str);
		
	for(i=0;i<n-1;i++){
	gets(str);
	st=strlen(str);
	if(min>st){
		min=st;
		for(j=0;j<st;j++){
		a[j]=str[j];
		}
		a[st]='\0';
	}

	}
		for(i=0;i<min;i++){
		printf("%c",a[i]);
		}
	

	return 0;
}