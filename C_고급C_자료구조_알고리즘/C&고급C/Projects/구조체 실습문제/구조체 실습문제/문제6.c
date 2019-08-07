#include <stdio.h>
struct student{
	char name[20],a;
	int score[3];
	double ave;

};



int main(){
	
	struct student s1[20];
	int n,i,j;


	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		s1[i].ave=0;
		scanf("%s %d %d %d",s1[i].name,&s1[i].score[0],&s1[i].score[1],&s1[i].score[2]);
		for(j=0;j<3;j++){
			s1[i].ave=s1[i].ave+s1[i].score[j];

		}
		
		s1[i].ave=s1[i].ave/3.0;

		if(s1[i].ave>=90){
			s1[i].a='A';

		}
		else if(s1[i].ave>=80){
			s1[i].a='B';

		}
		else if(s1[i].ave>=70){
			s1[i].a='C';

		}
		else if(s1[i].ave<70){
			s1[i].a='F';

		}
	
	}

	for(i=0;i<n;i++){
		printf("%s %.1lf %c\n",s1[i].name,s1[i].ave,s1[i].a);

	}



	return 0;
}