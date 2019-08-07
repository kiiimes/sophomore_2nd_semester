#include <stdio.h>
void userAlign(int*p,int N,int reverse){
	int j,i,*pj=&j,*pi=&i,temp,*ptemp=&temp,count=1,*pcount=&count;


	if(reverse=0){
		for(pj=p+1;pj<p+N;pj++){

			for (pi=p; pi < p+N; pi++){

				if (*pi >*(pi+1)){
					*ptemp = *pi;
					*pi = *(pi+1);
					*(pi+1) = *ptemp;
				}

			}
			(*pcount)++;
		}

	}
	if(reverse=1){
		for(pj=p+1;pj<p+N;pj++){

			for (pi=p; pi < p+N; pi++){

				if (*pi <*(pi+1)){
					*ptemp = *pi;
					*pi = *(pi+1);
					*(pi+1) = *ptemp;
				}

			}
			(*pcount)++;
		}

	}



}







int main(){
	int n,arr[20],sn,i;
	int *pn=&n,*parr,*psn=&sn,*pi=&i;
	scanf("%d %d",pn,psn);
	for(parr=arr;parr<arr+(*pn);parr++){
		scanf("%d",parr);
	}


	userAlign(arr,*pn,*psn);

	for(parr=arr;parr<arr+(*pn);parr++){
		printf("%d",*parr);
	}







	return 0;
}