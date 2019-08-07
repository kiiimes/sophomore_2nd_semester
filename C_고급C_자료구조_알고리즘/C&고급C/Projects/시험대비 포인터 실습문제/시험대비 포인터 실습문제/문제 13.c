#include <stdio.h>
void strcopy(char *str11,char *str22){
	int i;
	
	for(i=0;i<6;i++)
	*(str22+i)=*(str11+i);
}


int main(){
	char str1[7]={NULL},str2[7]={NULL};
	int i;

	scanf("%s",str1);

	strcopy(str1,str2);

	printf("%s",str2);


	return 0;
}