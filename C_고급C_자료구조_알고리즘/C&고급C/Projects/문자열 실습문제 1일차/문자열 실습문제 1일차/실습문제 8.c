#include <stdio.h>
#include <string.h>
int main(){
	char str1[60]={NULL},str2[20]={NULL};
   int n,i,len1,j,len2;
   
   scanf("%s",str1);
   
   scanf("%s",str2);
      
   scanf("%d",&n);
   len1=strlen(str1);
   len2=strlen(str2);
   if(len1!=n){
   for(i=0;;i++){
      
   if(i==n){
	   for(j=0;j<len2;j++){
      str1[41+j]=str1[n+j];
     str1[n+j]=str2[j];
	str1[n+len2+j-2]=str1[41+j];
	   }
	   
	
	   
	   printf("%s",str1);
	   break;
	   
	   
   }
   
  
   

   }
   }
      else if(len1==n){
      printf("%s",strcat(str1,str2));
   

   }
   return 0;
}