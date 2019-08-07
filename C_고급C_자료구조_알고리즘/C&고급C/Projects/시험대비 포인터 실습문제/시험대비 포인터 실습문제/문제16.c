#include <stdio.h>
void useralign(int *parr,int *pn,int *pa){
	int *p,*q,temp,*ptemp=&temp;

	for(p=parr;p<parr+*pn;p++){

		for(q=parr;q<parr+(*pn-1);q++){
			if(*pa==0){
				if(*(q+1)<*q){
					*ptemp=*q;
					*q=*(q+1);
					*(q+1)=*ptemp;
				}
			}
			else if(*pa==1){
				if(*(q+1)>*q){
					*ptemp=*q;
					*q=*(q+1);
					*(q+1)=*ptemp;
				}
			}
		}
	}
}
int main(){
	int arr[20],a,*p,n,k;
	int *pa=&a,*pn=&n;

	scanf("%d %d",pn,pa);

	for(p=arr;p<arr+*pn;p++){
		scanf("%d",p);
	}

	useralign(arr,pn,pa);

	for(p=arr;p<arr+*pn;p++){



	printf(" %d",*p);

	}



	return 0;
}