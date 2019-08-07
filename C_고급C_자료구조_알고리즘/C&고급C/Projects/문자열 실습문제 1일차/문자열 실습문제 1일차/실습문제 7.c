#include <stdio.h>
#include <string.h>

int main(){
	int n,i,len,len1;
	char str[100]={NULL},sav1[100]={NULL};
	scanf("%d",&n);
	getchar();
	scanf("%[^\n]s",str);
	len1=strlen(str);
	strcpy(sav1,str);
	for(i=1;i<n;i++){
		getchar();
		scanf("%[^\n]s",str);
		len=strlen(str);
		if(len1>len){
			len1=len;
			strcpy(sav1,str);

		}

		
	}
	printf("%s",sav1);
	



	return 0;
}
