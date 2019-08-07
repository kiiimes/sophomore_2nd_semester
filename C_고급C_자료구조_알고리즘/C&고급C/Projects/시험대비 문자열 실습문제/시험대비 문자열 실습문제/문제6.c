#include <stdio.h>
#include <string.h>

int main(){
	char str1[200]={NULL},str2[200]={NULL};
	int i,count=0,st,st1,j,a=0;

	gets(str1);
	scanf("%s",str2);

	st=strlen(str1);
	st1=strlen(str2);

	for(i=0;i<=st-st1;i++){
		count=0;
		for(j=0;str2[j]!='\0';j++){
			if(str1[i+j]==str2[j]){
				count++;
				if(count==st1){


					a++;
					i=i+st1-1;
					break;
				}
			}
		}

		
	}
	printf("%d",a);


	return 0;
}