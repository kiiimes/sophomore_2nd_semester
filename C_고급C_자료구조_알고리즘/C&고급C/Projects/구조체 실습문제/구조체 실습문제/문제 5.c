#include <stdio.h>
struct student{
	int score;
	char name[10];

};

int main(){
	struct student a[5];
	int i,ave=0;

	for(i=0;i<5;i++){
		scanf("%s %d",a[i].name,&a[i].score);
		ave=ave+a[i].score;
		
	}
	ave=ave/5;

	for(i=0;i<5;i++){
		if(ave>=(a[i].score)){
			printf("%s\n",a[i].name);
		}

	}




	return 0;
}