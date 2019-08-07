#include <stdio.h>
#include <string.h>

struct student{
	char name[10];
	int sc;

};


int main(){
	struct student in[5];
	int i,a;
	char n[10];

	for(i=0;i<5;i++){
		scanf("%s %d",in[i].name,&in[i].sc);

	}
	
	scanf("%s",n);
	

	for(i=0;i<5;i++){
			a=strcmp(n,in[i].name);
		if(a==0){
			printf("%d",in[i].sc);
		}

	}

	return 0;
}