#include <stdio.h>
int main(){
	char str1[101],str2[100];
	int i,count=0,a;

	scanf("%s %s",str1,str2);

	for(i=0;str1[i]!='\0';i++){
		count++;
		if(str1[i]==str2[i]){
			a=1;
		}
		else
			a=0;

	}
	printf("%d %d",count,a);

	return 0;
}