#include <stdio.h>
#include <string.h>

int main(){
	char str1[90]={NULL},str2[20]={NULL};
	int st,st1,i,j,a=0,count=0;

	scanf("%s %s",str1,str2);

	st=strlen(str1);
	st1=strlen(str2);

	for(i=0;i<=st-st1;i++){
		count=0;
		for(j=0;str2[j]!='\0';j++){
			if(str1[i+j]==str2[j]){
				count++;
				if(count==st1){
					a=1;
					break;
				}
			}
		}
		
	}
	printf("%d %d",st,a);


	return 0;}
