#include <stdio.h>
#include <string.h>
struct student{
	int id;
	char name[8];
	double grade;


};






int main(){
	struct student st[3];
	
	st[0].id=10;
	strcpy(st[0].name, "Tom");
	st[0].grade=3.2;

	st[1]=st[0];
	st[1].name[2]='p';

	printf("%d,%s,%.2f\n", st[0].id, st[0].name, st[0].grade); 
	printf("%d,%s,%.2f\n", st[1].id, st[1].name, st[1].grade);






	return 0;
}