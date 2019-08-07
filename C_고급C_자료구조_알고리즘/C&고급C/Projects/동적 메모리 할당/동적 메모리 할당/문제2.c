#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 typedef struct student{
	 char *num,*name,*grad;
 }student;


void main(){
	
	student *p;
	int n,i;
	char a[21];

	scanf("%d",&n)
	

	p=(student*)malloc(n*sizeof(student));

	for(i=0;i<n;i++){
		scanf("%s",a);
		p[i].num=(char*)malloc((strlen(a)+1)*sizeof(char));
		strcpy(p[i].num,a);
		scanf("%s",a);
		p[i].name=(char*)malloc((strlen(a)+1)*sizeof(char));
		strcpy(p[i].name,a);
		scanf("%s",a);
		p[i].grad=(char*)malloc((strlen(a)+1)*sizeof(char));
		strcpy(p[i].grad,a);
	}
	for(i=0;i<n;i++){
		if(p[i].grad[0]=='A'&&p[i].grad[1]=='\0'){
			printf("%s\n",p[i].name);
		}

	}



}