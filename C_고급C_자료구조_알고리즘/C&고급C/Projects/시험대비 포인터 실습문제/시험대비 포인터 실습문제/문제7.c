#include <stdio.h>
int main(){
	int arr[3],*p,*q,temp,*ptemp=&temp,a,*pa=&a;

	for(p=arr;p<arr+3;p++){
		scanf("%d",p);
	}

	
		for(p=arr;p<arr+3;p++){
			*pa=1;
			for(q=arr;q<arr+3;q++){
				if(*p>*q){
					(*pa)++;
				}
			}
			if(*pa==2){
				printf("%d",*p);
				break;
			}
		}
	


	return 0;
}