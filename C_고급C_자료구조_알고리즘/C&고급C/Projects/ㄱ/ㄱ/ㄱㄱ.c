#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct food
{
   int main;
      int sidedish[3];
   int beverage;
};
/*void main()
{
  struct food box;
  int i;
  scanf("%d %d",&box.main,&box.beverage);
  for(i=0;i<3;i++){
	  scanf("%d",box.sidedish+i);

  }
  printf("main : %d\nbeverage: %d\n",box.main,box.beverage);
    for(i=0;i<3;i++){
	  printf("side dish%d: %d\n",i+1,box.sidedish[i]);

  }
	

}*/
void main(){
	struct food boxa,boxb;
	 int i;
  scanf("%d",&boxa.main);
  for(i=0;i<3;i++){
	  scanf("%d",boxa.sidedish+i);
  }
	   scanf("%d",&boxa.beverage);

  boxb=boxa;
  scanf("%d",&boxb.main);
  
    printf("main : %d\nbeverage: %d\n",boxa.main,boxa.beverage);
    for(i=0;i<3;i++){
	  printf("side dish%d: %d\n",i+1,boxa.sidedish[i]);

  }
	   printf("main : %d\nbeverage: %d\n",boxb.main,boxb.beverage);
    for(i=0;i<3;i++){
	  printf("side dish%d: %d\n",i+1,boxb.sidedish[i]);

  }


}
