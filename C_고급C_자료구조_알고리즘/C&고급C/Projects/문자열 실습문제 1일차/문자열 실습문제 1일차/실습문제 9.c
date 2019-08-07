#include <stdio.h>
#include <string.h>
int main(){
	char str1[60]={NULL},str2[20]={NULL},str3[40]={NULL};
	int n,i,len1,j,len2,num;

	scanf("%s",str1);

	scanf("%s",str2);

	scanf("%d",&n);
	scanf("%d",&num);
	len1=strlen(str1);
	len2=strlen(str2);
	if(len1!=n){
		for(i=0;str1[i]!=0;i++){

			if(i==n){
				if(num==0){
					for(j=0;j<len1-i;j++){
						str1[i+len2+j]=str1[n+j];
						str1[n+j]=str2[j];
					}
					printf("%s",str1);
					break;
				}
				else if(num==1){
					for(j=0;j<len1-i;j++){
						str1[i+len2+j]=str1[n+j];
						str1[n+j]=str2[len2-1-j];
					}
					printf("%s",str1);
					break;
				}

			

		}




	}
}
   else if(len1==n){

	   for(i=0;i<len2;i++){

		   if(num==0){
			   str1[n+i]=str2[i];
		   }
		   else if(num==1){
			   str1[n+i]=str2[len2-1-i];
		   }

	   }
	   printf("%s",str1);

   }




   return 0;
}