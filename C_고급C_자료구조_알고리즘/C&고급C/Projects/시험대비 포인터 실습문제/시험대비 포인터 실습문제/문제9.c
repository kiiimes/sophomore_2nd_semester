#include <stdio.h>
int main(){
	int arr[50],i,n,count=0;
	int *pn=&n,*pi=&i,*p,*pcount=&count;

	scanf("%d",pn);

	for(p=arr;p<arr+*pn;p++){
		scanf("%d",p);

	}

	for(p=arr;;p++){
		(*pcount)++;
		if(*p==0)
		break;			
	}

	printf("%d",(*pcount)-1);

	return 0;
}