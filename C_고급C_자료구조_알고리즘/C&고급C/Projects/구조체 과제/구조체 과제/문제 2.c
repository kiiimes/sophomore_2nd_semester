#include <stdio.h>
struct student{
	char name[10];
	int sc;
};
struct student select_N(struct student *na,int m){
	int i,j,a;

	for(i=0;i<5;i++){
		a=1;
		for(j=0;j<5;j++){
			if((na+i)->sc<(na+j)->sc){
				a++;
				
			}

		}
		if(a==m){
			return *(na+i);
		}

	}

}



int main(){
	struct student st[5],s;
	int num,i;

	for(i=0;i<5;i++){
		scanf("%s %d",st[i].name,&st[i].sc);

	}

	scanf("%d",&num);

	s=select_N(st,num);

	printf("%s %d",s.name,s.sc);



	return 0;
}