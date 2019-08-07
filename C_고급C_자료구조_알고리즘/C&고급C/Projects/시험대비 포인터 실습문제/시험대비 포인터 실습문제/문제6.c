#include <stdio.h>
int main(){
	char arr[11],*p,*q,cmax,*pcmax=&cmax;
	int sav[10]={0},count=0,*z,*k,max,*pmax=&max;
	int *pcount=&count;

	scanf("%s",arr);

	for(p=arr;p<arr+10;p++){

		
		for(q=arr;q<arr+10;q++){
			if(*p==*q){
				*(sav+*pcount)+=1;
			}
			
		}
		
				
		(*pcount)++;
	
	}
	for(z=sav;z<sav+9;z++){
		for(k=sav;k<sav+9;k++){
		if(*z<*k){
			*pmax=*k;
			
		}
		}
	}
	
	*pcount=0;
	for(z=sav;;z++){
		
		if(*z==*pmax){
			printf("%c %d",*(arr+*pcount),*z);
			break;
		}
		(*pcount)++;
	}


	return 0;
}