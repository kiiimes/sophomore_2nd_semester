#include <stdio.h>
struct lunch{
	int main;
	int side[3];
	int bev;
	
};
int main(){
	struct lunch box;
	struct lunch *pbox=&box;
	int i;

	scanf("%d",&(pbox->main));

	for(i=0;i<3;i++){
		scanf("%d",&(pbox->side[i]));
	}

	scanf("%d",&(pbox->bev));
	
	printf("%d\n",pbox->main);

	for(i=0;i<3;i++){
		printf("%d ",pbox->side[i]);
	}

	printf("\n%d",pbox->bev);


	return 0;
}