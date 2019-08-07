#include <stdio.h>
#include <string.h>
int main(){
	char str[30]={NULL};
	
	int a,i,j,k,len,count=0;

	scanf("%s",str);

	len=strlen(str);

	for(i=0;str[i]!=0;i++){
		count=0;
		for(k=0;k<i;k++){
			

			if(str[k]==str[i]){
				
				i=i+1;
				continue;
			}
		
		}
		
		if(i==len){

			break;
		}
		
		for(j=0;str[j]!=0;j++){
			
			if(str[i]==str[j]){
			
			a=str[i];
			count++;
			
			
			}
				if(j==len-1){

					printf(" %c: %d",a,count);
					
			}

		
		}
			


	}



	return 0;
}