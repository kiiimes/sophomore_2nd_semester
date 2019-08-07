#include <stdio.h>

int main(){
	char str1[100],str2[100];
	int i,count1=0,count2=0,a=0;
	scanf("%s %s",str1,str2);
	for(i=0;str1[i]!=0;i++){
		count1++;
		if(str1[i]==str2[i]){
			count2++;
		}
		
	}
	printf("%d ",count1);
	if(count2==count1){
		a=1;
		
	}
	printf("%d",a);


	return 0;
}