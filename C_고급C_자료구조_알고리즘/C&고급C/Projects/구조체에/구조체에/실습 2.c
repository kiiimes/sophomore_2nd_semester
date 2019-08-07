#include <stdio.h>
struct lunch{
	int main;
	int side[3];
	int bev;
	
};

int main(){
	struct lunch box,box2;
	int i,sum;
	scanf("%d",&box.main);
	
	for(i=0;i<3;i++){

		scanf("%d",&box.side[i]);
		
	}

	scanf("%d",&box.bev);

	box2=box;
	
	scanf("%d",&box2.main);


		printf("main dish : %d \n",box.main);
	
	for(i=0;i<3;i++){

		printf("side dish %d : %d\n",i,box.side[i]);
		
	}

	printf("Beverage : %d",box.bev);

	printf("main dish : %d \n",box2.main);
	
	for(i=0;i<3;i++){

		printf("side dish %d : %d\n",i,box2.side[i]);
		
	}

	printf("Beverage : %d",box2.bev);



	return 0;
}
