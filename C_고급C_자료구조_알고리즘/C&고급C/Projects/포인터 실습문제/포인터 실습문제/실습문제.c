#include <stdio.h>
int main()/*{
		 int x,*p;
		 scanf("%d",&x);
		 p=&x;
		 scanf("%d",p);
		 printf("%d",*p);
		 return 0;
		 }*///巩力1
		 /*{
		 int n,m,*pm=&m,*pn=&n,i,sum=0;
		 scanf("%d %d",pn,pm);
		 for(i=*pn;i<=*pm;i++){
		 sum+=i;

		 }
		 printf("%d",sum);
		 return 0;
		 }*///巩力2
		 /*{
		 int arr[100]={0},i,n,m,*pn=&n,*pm=&m;
		 scanf("%d",pn);
		 for(i=0;i<*pn;i++){
		 scanf("%d",arr+i);
		 }
		 scanf("%d",pm);
		 printf("%d",*(arr+*pm));
		 return 0;
		 }*///巩力3
		 /*{
		 int arr[100],n,i,j,tmp;
		 scanf("%d",&n);
		 for(i=0;i<n;i++){
		 scanf("%d",&arr[i]);
		 }

		 for(j=1;j<n;j++){
		 for(i=0;i<n-j;i++){
		 if(*(arr+i)>=*(arr+i+1)){
		 tmp=*(arr+i);
		 *(arr+i)=*(arr+i+1);
		 *(arr+i+1)=tmp;
		 }
		 }
		 }
		 printf("%d %d",*(arr+(n-1)),*arr);
		 return 0;
		 }*///巩力 4
		 /*{
		 char arr[20],i,sav;
		 for(i=0;i<20;i++){
		 scanf("%c",arr+i);
		 if(*(arr+i)=='#'){
		 sav=i-1;
		 break;
		 }
		 }
		 for(i=sav;i>=0;i--){
		 printf("%c",*(arr+i));
		 }
		 return 0;
		 }*///巩力5
		 /*{
		 char arr[10],sav[10]={0},i,j,count,max,k;
		 for(i=0;i<10;i++){
		 scanf("%c",arr+i);
		 }
		 for(i=0;i<10;i++){
		 count=0;
		 for(j=i;j<10;j++){
		 if(*(arr+i)==*(arr+j)){
		 count++;
		 }

		 }
		 *(sav+i)=count;
		 }
		 max=*sav;
		 k=0;
		 for(i=1;i<10;i++){
		 if(max<=*(sav+i)){
		 max=*(sav+i);

		 }

		 }
		 for(i=0;i<10;i++){
		 if(*(sav+i)==max){
		 k=i;
		 break;
		 }

		 }
		 printf("%c %d",*(arr+k),max);
		 return 0;
		 }*///巩力 6
		 /*{
		 int arr[3],i,j,tmp;
		 for(i=0;i<3;i++){
		 scanf("%d",arr+i);
		 }

		 for(j=1;j<3;j++){
		 for(i=0;i<3-j;i++){
		 if(*(arr+i)>=*(arr+i+1)){
		 tmp=*(arr+i);
		 *(arr+i)=*(arr+i+1);
		 *(arr+i+1)=tmp;
		 }
		 }
		 }
		 printf("%d",*(arr+1));



		 return 0;
		 }*///巩力 7
{
	int arr[5],rank[5],arr1[5],i,j,*pi=&i,*pj=&j,*parr=arr,*prank=rank,*parr1=arr1,tmp;
	for(*pi=0;*pi<5;*pi+=1){
		scanf("%d",parr+*pi);

	}
	for(*pi=0;*pi<5;*pi+=1){
		*(prank+*pi)=*(parr+*pi);

	}
	for(*pj=1;*pj<5;*pj+=1){
		for(*pi=0;*pi<5-*pj;*pi+=1){
			if(*(prank+*pi)<*(prank+*pi+1)){
				tmp=*(prank+*pi);
				*(prank+*pi)=*(prank+*pi+1);
				*(prank+*pi+1)=tmp;
			}
		}
	}

	for(*pi=0;*pi<5;*pi+=1){
		printf("%d=r" , *(parr+*pi));
		for(*pj=0;*pj<5;*pj+=1){

			if(*(parr+*pi)==*(prank+*pj)){
				printf("%d ",*pj+1);
				if(*(prank+*pj)==*(prank+*pj-1)){
					*pj=*pj-1;

				}
				break;
			}

		}


	}








	return 0;
}//巩力 8
/*{
int n,arr[50],i,count,sav,*pn=&n,*pi=&i,*pcount=&count,*psav=&sav;
scanf("%d",pn);
for(*pi=0;*pi<*pn;(*pi)+=1){
scanf("%d",arr+(*pi));
if(*(arr+(*pi))==0){
*psav=*pi;
}

}
*pcount=0;
for(*pi=0;*pi<*psav;*pi+=1){
*pcount+=1;

}
printf("%d",*pcount);
return 0;
}*///巩力 9