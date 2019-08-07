#include <stdio.h>

int main(){
	char str[11]={NULL};
	int i;

	scanf("%s",str);

	for(i=0;i<10;i++){
		if(str[i]>='a'&&str[i]<='z'){
			str[i]='A'+str[i]-'a';
		}
		else if(str[i]>='A'&&str[i]<='Z'){
			str[i]='a'+str[i]-'A';
		}
	}
	printf("%s",str);

	return 0;
}