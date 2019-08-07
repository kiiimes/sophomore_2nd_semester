#include <stdio.h>
void addArray(int *par1,int *par2,int *psav,int pn){
	int *p,*ppn=&pn,i=0,j=*ppn,*pi=&i,*pj=&j;

	for(p=psav;p<psav+*ppn;p++){
		*p=*(par1+*pi)+*(par2+(*pj-1));
			(*pi)++;
			(*pj)--;
	}
}
int main(){
	int ar1[20]={0},ar2[20]={0},n,i,sav[20]={0};
	int *pn=&n,*pi=&i,*p;

	scanf("%d",pn);

	for(p=ar1;p<ar1+*pn;p++){
		scanf("%d",p);
	}
	for(p=ar2;p<ar2+*pn;p++){
		scanf("%d",p);
	}
	addArray(ar1,ar2,sav,*pn);

	for(p=sav;p<sav+*pn;p++)
	printf(" %d",*p);






	return 0;}