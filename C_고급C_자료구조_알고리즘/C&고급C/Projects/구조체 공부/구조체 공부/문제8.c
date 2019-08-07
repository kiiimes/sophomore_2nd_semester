#include <stdio.h>
#include <string.h>
typedef struct student{
	char name[9];
	int kor,eng,math;
	float ave;
	char grad;

}student;
void main(){
	student p[50];
	int n,i;
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++){
		scanf("%s %d %d %d",p[i].name,&((p+i)->kor),&((p+i)->eng),&((p+i)->math));
	}
	for(i=0;i<n;i++){
		(p+i)->ave=((p+i)->kor+(p+i)->eng+(p+i)->math)/3.0;
	}
	for(i=0;i<n;i++){
		if((p+i)->ave>=90&&(p+i)->ave<=100){
			(p+i)->grad='A';
		}
		else if((p+i)->ave>=80){
			(p+i)->grad='B';
		}
		else if((p+i)->ave>=70){
			(p+i)->grad='C';
		}
		else
			(p+i)->grad='D';
	}

	for(i=0;i<n;i++){
		printf("%s %.1f %c\n",(p+i)->name,(p+i)->ave,(p+i)->grad);
	}


}