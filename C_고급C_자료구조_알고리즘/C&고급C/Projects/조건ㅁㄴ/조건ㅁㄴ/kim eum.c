#include <stdio.h>
int main()
/*{
	int a;
	scanf("%d",&a);
	if(a%4!=0)
	printf("평년");
	else {if(a%100!=0)
		printf("윤년");
	else{ if(a%400!=0)
	printf("평년");
	else
	printf("윤년");}

	return 0;}
}
{
	int a,b;
	scanf("%d",&a);
	scanf("%d",&b);
	if(a==b){
		printf("맞음");
	}
	else if(a>b){
		printf("up");
		scanf("%d",&b);
		if(a==b){
			printf("맞음");
		}
		else if(a>b){
			printf("up");
		}
		else if(a<b){
			printf("down");
		}
	}
	else if(a<b){
		printf("down");
		scanf("%d",&b);
		if(a==b){
			printf("맞음");
		}
		else if(a>b){
			printf("up");
		}
		else if(a<b){
			printf("down");
		}
	}
	return 0;
}*/
{
	char a;
	char b;
	scanf("%c",&a);
	if(a>='A'&&a<='Z')
	printf("%c",b='a'+(a-'A'));
	else if(a>='a'&&a<='z')
	printf("%c",b='A'+(a-'a'));
	else
	printf("none");
	return 0;}








