#include <stdio.h>
#include <string.h>
int main(){
	char str1[100],str2[100];
	int i,j,len,count1,count2=0;
	scanf("%[^\n]s",str1);
	scanf("%s",str2);
	len=strlen(str2);
		
	for(i=0;str1[i]!=0;i++){
		count1=0;
		for(j=0;str2[j]!=0;j++){
			if(str2[j]==str1[i+j]){
				count1++;

			}
			if(count1==len){
				count2++;
				i=i+(len-1);
			break;
		}
		}
		
		
	}
	printf("%d",count2);
	


	





	return 0;
}