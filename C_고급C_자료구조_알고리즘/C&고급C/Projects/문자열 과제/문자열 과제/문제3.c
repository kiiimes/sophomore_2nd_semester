#include <stdio.h>
int main(){
	char str[21]={NULL};
	int k,i;
	
	scanf("%s",str);
	scanf("%d",&k);

	for(i=0;str[i]!=0;i++){
		str[i]='a'+(str[i]-'a'+k)%26;
		

	}
	printf("%s",str);




	return 0;
}

