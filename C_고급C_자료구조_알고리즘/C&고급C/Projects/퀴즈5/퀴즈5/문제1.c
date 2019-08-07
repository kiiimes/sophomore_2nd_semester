#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
	char str[3][21];
	int i;
	for(i=0;i<3;i++){
		gets(str[i]);
	}
	strcat(str[0],str[1]);
	strcat(str[0],str[2]);

	printf("%s",str[0]);
	


}