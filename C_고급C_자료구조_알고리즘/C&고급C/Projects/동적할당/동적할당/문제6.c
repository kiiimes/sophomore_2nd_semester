#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
	char name[8];
	int kor,eng,math;
	float ave;
}student;

void main(){
	student *p;
	int n,i,j;
	scanf("%d",&n);

	p=(student*)malloc(n*sizeof(student));

	for(i=0;i<n;i++){
		scanf("%s %d %d %d",p[i].name,&(p[i].kor),&(p[i].eng),&(p[i].math));
		p[i].ave=(p[i].kor+p[i].eng+p[i].math)/3.0;
	}

	for(i=0;i<n;i++){
		printf("%s %.1f ",p[i].name,p[i].ave);
		if(p[i].kor>=90||p[i].eng>=90||p[i].math>=90){
			printf("GREAT ");
			for(j=0;j<n;j++){
				if(p[i].kor<70||p[i].eng<70||p[i].math<70){

				}
				else
					printf("\n");
			}
			

		}
		if(p[i].kor<70||p[i].eng<70||p[i].math<70){
			printf("BAD\n");

		}
		else if(p[i].kor<90||p[i].eng<90||p[i].math<90){
			printf("\n");
		}
	
	}


	
}