#include <stdio.h>
struct student{
	char name[8],g;
	int kor,eng,math;
	double ave;

	};
int main(){
	struct student st1[50];
	struct student *pst;
	int n,i,j;

	pst=st1;

	scanf("%d",&n);

	for(i=0;i<n;i++){
		
		scanf("%s %d %d %d",(pst+i)->name,&((pst+i)->kor),&((pst+i)->eng),&((pst+i)->math));
		
		(pst+i)->ave=(pst+i)->kor+(pst+i)->eng+(pst+i)->math;

		(pst+i)->ave=((pst+i)->ave)/3.0;

		
	
	if((pst+i)->ave>=90){
			(pst+i)->g='A';

		}
		else if((pst+i)->ave>=80){
			(pst+i)->g='B';

		}
		else if((pst+i)->ave>=70){
			(pst+i)->g='C';

		}
		else if((pst+i)->ave<70){
			(pst+i)->g='D';

		}
	}

	for(i=0;i<n;i++){
		printf("%s %.1lf %c\n",(pst+i)->name,(pst+i)->ave,(pst+i)->g);

	}

	return 0;
}