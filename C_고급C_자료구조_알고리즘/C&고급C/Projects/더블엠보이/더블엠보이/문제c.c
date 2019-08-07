#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student{
	int num;
	char name[10];
	int age;

}student;
void swap(student *p1,student *p2){
	char temp[10]={'NULL'};
	int tem;
	strcpy(temp,p1->name);
	strcpy(p1->name,p2->name);
	strcpy(p2->name,temp);

	tem=p1->age;
	p1->age=p2->age;
	p2->age=tem;
}


void main(){
	student n1[2]={'NULL'};
	int i;

	for(i=0;i<2;i++){
		scanf("%d %s %d\n",&(n1[i].num),n1[i].name,&(n1[i].age));
	}

	swap(n1+0,n1+1);

	for(i=0;i<2;i++){
		printf("%d %s %d",(n1+i)->num,(n1+i)->name,(n1+i)->age);
	}

}