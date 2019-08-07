#include <stdio.h>
#include <string.h>
int main(){
	char str1[80],str2[10];
	int i,j,count1=0,len,a=0;
	scanf("%s %s",str1,str2);
	printf("%d",strlen(str1));
	len=strlen(str2);
	for(i=0;str1[i]!=0;i++){
		count1=0;
		for(j=0;str2[j]!=0;j++){
			if(str2[j]==str1[i+j]){
				count1++;
			}
			if(count1==len){
			break;
		}
		}
		if(count1==len){
			break;
		}
	}
	if(count1==len){
			a=1;
			
		}
	printf(" %d",a);
	



	return 0;
}