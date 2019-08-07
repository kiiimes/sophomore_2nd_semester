#include <stdio.h>
struct lunch{
	int main;
	int side[3];
	int bev;
	
};

int main(){
	struct lunch box[2];
	int i,sum,j;
	for(j=0;j<2;j++){
	scanf("%d",&box[j].main);
	
	for(i=0;i<3;i++){

		scanf("%d",&box[j].side[i]);
		
	}

	scanf("%d",&box[j].bev);
}
	for(j=0;j<2;j++){
		printf("main dish : %d\n",box[j].main);
	
	for(i=0;i<3;i++){

		printf("side dish %d : %d\n",i,box[j].side[i]);
		
	}

	printf("Beverage : %d",box[j].bev);
	}
	



	return 0;
}
