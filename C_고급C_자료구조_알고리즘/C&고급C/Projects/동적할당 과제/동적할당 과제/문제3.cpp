#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 void main(){
	 char a[101],sav[101]={'NULL'},**p;
	 int i,j,st,k,cnt=0,x,y=0,rank;
	 scanf("%s",a);

	 for(i=0;a[i]!='\0';i++){
		 if(a[i]>='A'&&a[i]<='Z')
		 cnt++;
	 }
	 p=(char**)malloc((cnt)*sizeof(char*));

	 for(i=0;a[i]!='\0';i++){
		k=0;
		 for(j=i+1;;j++){
			 sav[k]=a[j-1];
			 k++;
			 if(a[j]>='A'&&a[j]<='Z'){
				 st=strlen(sav);
				 p[y]=(char*)malloc((st+1)*sizeof(char));
				 strcpy(p[y],sav);
				 y++;
				 for(x=0;sav[x]!='\0';x++){
					 sav[x]='\0';
				 }
				 break;
			 }
			 if(a[j]=='\0'){
				 st=strlen(sav);
				 p[y]=(char*)malloc((st+1)*sizeof(char));
				 strcpy(p[y],sav);
				 break;
			 }
		 }
		 i=j-1;
	 }



	 for(i=0;i<cnt;i++){
		 rank=1;
		 for(j=0;j<cnt;j++){
			 if(strcmp(p[i],p[j])>0)rank++;
		 }
		 if(rank==1){
			 printf("%s!",p[i]);
		 }
		 else
			 printf("%s",p[i]);

		 if(i!=cnt-1){
			 printf("\n");
		 }
	 }
	 for(i=0;i<cnt;i++){
		 free(p[i]);
	 }
	 free(p);
 }