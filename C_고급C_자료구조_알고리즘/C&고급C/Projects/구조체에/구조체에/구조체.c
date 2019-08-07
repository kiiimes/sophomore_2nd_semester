#include <stdio.h>
struct lunch{
	int main;
	int side[3];
	int bev;
	
};

int main(){
	struct lunch box;
	int i,sum;
	scanf("%d",&box.main);
	
	for(i=0;i<3;i++){

		scanf("%d",&box.side[i]);
		
	}

	scanf("%d",&box.bev);
	
		printf("main dish : %d\n",box.main);
	
	for(i=0;i<3;i++){

		printf("side dish %d : %d\n",i,box.side[i]);
		
	}

	printf("Beverage : %d",box.bev);

	sum=box.main+box.side[0]+box.side[1]+box.side[2]+box.bev;

	printf("Total : %d+%d+%d+%d+%d=%d",box.main,box.side[0],box.side[1],box.side[2],box.bev,sum);




	return 0;
}
