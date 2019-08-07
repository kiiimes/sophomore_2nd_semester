#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student {
	int id;
	char name[10];
	int age;

}student;

void swap(student *st1, student *st2) {
	student tmp = { NULL };

	 strcpy(tmp.name,st1->name);
	 strcpy(st1->name, st2->name);
	 strcpy(st2->name, tmp.name);


	 tmp.age = st1->age;
	 st1->age = st2->age;
	 st2->age = tmp.age;

	 
}


void main() {
	student st[2];
	int i;

	for (i = 0; i < 2; i++) {
		scanf("%d %s %d", &(st[i].id), st[i].name, &(st[i].age));
	}

	swap(st, st+1);

	for (i = 0; i < 2; i++) {
		printf("%d %s %d\n", st[i].id, st[i].name, st[i].age);
	}
	
	

}