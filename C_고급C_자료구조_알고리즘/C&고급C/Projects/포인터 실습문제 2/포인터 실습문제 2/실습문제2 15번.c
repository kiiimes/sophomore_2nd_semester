#include <stdio.h>
int abc(int *par,int pkk){
	   int i,*pi=&i, temp,*ptemp=&temp;
   

  
      for (*pi = 0; *pi < 9-pkk; (*pi)++)
      {
         if (*(par+(*pi)) <*(par+(*pi)+1)){
         *ptemp = *(par+(*pi));
         *(par+(*pi)) = *(par+(*pi)+1);
         *(par+(*pi)+1) = *ptemp;
      }
   }

}



int main(){
	int data[10],k,i;
	int *pdata=data,*pk=&k,*pi=&i;
	for(*pi=0;*pi<10;(*pi)++){
		scanf("%d",pdata+(*pi));
		}
	 for (*pk = 0; *pk < 9; (*pk)++)
   {

	abc(pdata,*pk);

	 }
	 for(*pi=0;*pi<10;(*pi)++){
		 printf(" %d",*(pdata+(*pi)));

	 }

	return 0;
}