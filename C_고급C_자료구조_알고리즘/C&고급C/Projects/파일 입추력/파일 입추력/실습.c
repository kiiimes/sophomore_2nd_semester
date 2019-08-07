#include <stdio.h>
#define SIZE 3
int main()
{
double weight;
int age, i;
FILE *fp;
fp= fopen("..\\..\\data1.txt", "w");
if(fp==NULL){
	printf("실패");
	return -1;
}

fclose(fp);
printf("성공");
return 0;
}