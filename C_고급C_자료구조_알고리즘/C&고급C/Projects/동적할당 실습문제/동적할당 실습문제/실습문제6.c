#include <stdio.h>
#include <stdlib.h>
struct student{
	char name[8];
	int kor,eng,math;
	double ave;
};


int main(){
	struct student *st;
	int n,i;
	scanf("%d",&n);
	st=(struct student*)malloc(n*sizeof(struct student));
	for(i=0;i<n;i++){
		scanf("%s %d %d %d",st[i].name,&st[i].kor,&st[i].eng,&st[i].math);
	st[i].ave=(st[i].kor+st[i].eng+st[i].math)/3.0;
	}
	for(i=0;i<n;i++){
		printf("%s %.1lf",st[i].name,st[i].ave);
		if(st[i].kor>=90||st[i].eng>=90||st[i].math>=90){
			printf(" GREAT");
		}
		if(st[i].kor<70||st[i].eng<70||st[i].math<70){
			printf(" BAD");
		}
		printf("\n");
	}

	return 0;
}