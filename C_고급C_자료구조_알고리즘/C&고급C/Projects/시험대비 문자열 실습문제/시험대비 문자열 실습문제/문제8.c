#include <stdio.h>
#include <string.h>

int main(){
	char str1[43]={NULL},str2[21]={NULL};
	int n,i,st1,st2,j,k,stt,a;

	scanf("%s %s",str1,str2);
	scanf("%d",&n);

	

	st1=strlen(str1);
	st2=strlen(str2);
	for(i=0;str1[i]!=0;i++){
		if(n==st1){
			for(a=0;a<st2;a++){
			str1[st1+a]=str2[a];
			}

		}

		else if(i==n){
			for(k=st1-n-1;k>=0;k--){
				str1[n+st2+k]=str1[n+k];
			}
			for(j=0;j<st2;j++){
			
				str1[n+j]=str2[j];
			}
			
		}
		stt=strlen(str1);
			if(stt==st1+st2){
				
				break;
			}
			
			
	}
	printf("%s",str1);


	return 0;
}