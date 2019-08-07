#include <stdio.h>
#include <string.h>
typedef struct student{
	char name[10];
	int a;
}student;

void main(){
	student st[5];
	int i;
	float ave=0;

	for(i=0;i<5;i++){
		scanf("%s %d",st[i].name,&(st[i].a));
		ave+=st[i].a;
	}

	ave=ave/5;

	for(i=0;i<5;i++){
		if(st[i].a<ave){
			printf("%s\n",st[i].name);
		}
	}

}