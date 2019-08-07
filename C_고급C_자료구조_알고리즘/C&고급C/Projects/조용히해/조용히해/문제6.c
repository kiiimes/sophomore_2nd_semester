#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student{
	char *num,*name,*grad;


}student;


void main(){
	student *st;
	int n,i;
	char a[21];
	scanf("%d",&n);
	st=(student*)malloc(n*sizeof(student));
	for(i=0;i<n;i++){
		scanf("%s",a);
		st[i].num=(char*)malloc((strlen(a)+1)*sizeof(char));
		strcpy(st[i].num,a);
		scanf("%s",a);
		st[i].name=(char*)malloc((strlen(a)+1)*sizeof(char));
		strcpy(st[i].name,a);
		scanf("%s",a);
		st[i].grad=(char*)malloc((strlen(a)+1)*sizeof(char));
		strcpy(st[i].grad,a);
	}

	for(i=0;i<n;i++){

		if(st[i].grad,){


		}

	}


}