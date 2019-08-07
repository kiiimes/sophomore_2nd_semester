#include <stdio.h>
#include <string.h>

enum day_type {sun,mon,the,wed,thu,fri,sat};
void main(){
	enum day_type day;
	day=mon;
	printf("%d",day);//1·Î Ãâ·ÂµÊ ¿Í¿õ~~
	if(day==1)
		printf("monday");

}