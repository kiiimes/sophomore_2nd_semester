#include <stdio.h>

struct lunch
{
   int main, side[3], bev;
};
void main()
{
   struct lunch box;
   struct lunch *pbox=&box;
   int i;


   scanf("%d ",&(*pbox).main);

   for(i=0;i<3;i++){
	   scanf("%d ",&(*pbox).side[i]);


   }
   scanf("%d ",&(*pbox).bev);

   
   printf("%d ",pbox->main);

   for(i=0;i<3;i++){
	   printf("%d ",pbox->side[i]);


   }
   printf("%d ",pbox-> bev);



  