#include <stdio.h>
int main(){
	int n,*p,temp;
	scanf("%d",&n);
	p=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		scanf("%d",p+i);
	}


	for(i=0;i<n-1;i++){
		if(p[i]>p[i+1]){
			temp=p[i];
			p[i]=p[i+1];
			p[i+1]=temp;
		}
	}





	return 0;
}
