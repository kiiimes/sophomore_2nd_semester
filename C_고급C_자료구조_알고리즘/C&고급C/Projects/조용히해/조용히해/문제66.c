#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student{
	char *name;
	int kor,eng,math;
	float ave;

}student;
void main(){
	student *p,*temp;
	int n,i,j;
	char a[8];
	scanf("%d",&n);
	getchar();
	p=(student*)malloc(n*sizeof(student));

	for(i=0;i<n;i++){
		scanf("%s",a);
		p[i].name=(char*)malloc((strlen(a)+1)*sizeof(char));
		strcpy(p[i].name,a);
		scanf("%f %f %f",&(p[i].kor),&(p[i].eng),&(p[i].math));
		p[i].ave=(p[i].kor+p[i].eng+p[i].math)/3.0;
		
	}
	for(i=0;i<n;i++){
		for(j=0;j<n-1;j++){
			if(p[j].ave<p[j+1].ave){
			temp->name=(p+j)->name;
			(p+j)->name=(p+j+1)->name;
			(p+j+1)->name=temp->name;
		}
	}
	}

	for(i=0;i<n;i++){

		printf("%s",(p+i)->name);
		free(p[i].name);
	}
	free(p);

	


}