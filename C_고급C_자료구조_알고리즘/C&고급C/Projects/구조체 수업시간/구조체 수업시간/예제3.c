#include <stdio.h>
#include <string.h>

struct student{
	int id; 
	char name[8]; 
	double grade;

};

void main(){
	struct student st1={10,"Tom",3.2};
	struct student *pst=&st1;

	pst->id +=20;
	strcpy(pst->name,"alice");
	pst->name[0]='A';

	printf("id %d\n",pst->id);
	printf("name %s\n",pst->name);
	printf("grade %.2lf\n",pst->grade);






}