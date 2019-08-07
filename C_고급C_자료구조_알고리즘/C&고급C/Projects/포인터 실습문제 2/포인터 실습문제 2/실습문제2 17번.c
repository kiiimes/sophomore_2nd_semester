#include <stdio.h>
void addArray(int *aln1,int *aln2,int *aOut,int num){
	int *pi,*pj,*pk;
	int count1=0;
	for(pi=aOut;pi<aOut+num;pi++){
		*pi=*(aln1+(pi-aOut))+*(aln2+num-pi+aOut-1);
	
	}

}




int main(){
	int num,ar1[20],ar2[20],sum[20]={0},i;
	int *pnum=&num,*par1,*par2,*pi=&i;
	scanf("%d",pnum);
	for(par1=ar1;par1<ar1+(*pnum);par1++){
		scanf("%d",par1);

	}
	for(par2=ar2;par2<ar2+(*pnum);par2++){
		scanf("%d",par2);
		}
	addArray(ar1,ar2,sum,*pnum);

		for(par1=sum;par1<sum+(*pnum);par1++){
		printf(" %d",*par1);

	}

	return 0;
}