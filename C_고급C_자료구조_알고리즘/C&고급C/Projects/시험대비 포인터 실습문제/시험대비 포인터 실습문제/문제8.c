#include <stdio.h>

int main(){
	int arr[5],rank[5],a;
	int *pa=&a,*p,*q,count=0,*pcount=&count;

	for(p=arr;p<arr+5;p++){
		scanf("%d",p);
	}

	for(p=arr;p<arr+5;p++){
		*pa=1;
		for(q=arr;q<arr+5;q++){
			if(*p<*q){
				(*pa)++;
			}
		}
		*(rank+*pcount)=*pa;
		(*pcount)++;
		
	}
	(*pcount)=0;
	for(p=arr;p<arr+5;p++){
		
		printf("%d=r%d ",*p,*(rank+*pcount));
		(*pcount)++;

	}


	return 0;
}