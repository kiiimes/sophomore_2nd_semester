#include <stdio.h>
int main(){
	char ch[20];
	int i;
	scanf("%s",ch);
	for(i=0;ch[i]!=0;i++){
		if(ch[i]>='a'&&ch[i]<='z'){
			printf("%c",ch[i]);

		}

	}



	return 0;
}