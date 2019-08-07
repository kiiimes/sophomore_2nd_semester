#include <stdio.h>
int main(){
	int i;
	char c,big,small;
	for(i=1;;i++){
		scanf("%c",&c);
		if(c>='0'&&c<='9'){
			break;
		}
		else if(c>='A'&&c<='Z'){
			small='a'+(c-'A');
			printf("%c",small);
		}
		else if(c>='a'&&c<='z'){
			big='A'+(c-'a');
			printf("%c",big);
		}
		else {
			
		}

		
	}
	return 0;
}
