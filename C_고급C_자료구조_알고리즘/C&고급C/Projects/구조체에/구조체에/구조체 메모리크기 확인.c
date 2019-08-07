#include <stdio.h>
struct student1{
   char grade;char gr;char g;
};
struct student2{
   int id; double grade; char name[3];  
};
struct student3{
   double grade; char name[3]; 
};


void main(){
   
   printf("%d ",sizeof( struct student1 ));
   printf("%d ", sizeof( struct student2 ) );
   printf("%d ",sizeof( struct student3 ));


   
}