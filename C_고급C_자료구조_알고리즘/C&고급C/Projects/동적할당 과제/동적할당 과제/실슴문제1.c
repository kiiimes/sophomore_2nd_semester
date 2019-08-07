#include <stdio.h>
#include <stdlib.h>
int main(){
	int m,n,*pa,*pb,i;
	scanf("%d %d",&m,&n);

	pa=(int *)calloc(m,sizeof(int));
	pb=(int *)calloc(n,sizeof(int));

	for(i=0;i<m;i++){
		scanf("%d",pa+i);
	}

	for(i=0;i<n;i++){
		scanf("%d",pb+i);
	}

	if(m>=n){
	for(i=0;i<n;i++){

			pa[i]+=pb[i];
		
	}
	for(i=0;i<m;i++){
		printf(" %d",pa[i]);
	}
	}
	if(m<n){
		for(i=0;i<m;i++){
			pb[i]+=pa[i];
		}
		for(i=0;i<n;i++){
			printf(" %d",pb[i]);
		}

	}
	
	free(pa);
	free(pb);



	

	return 0;
}