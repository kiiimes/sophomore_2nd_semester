#include <stdio.h>
#include <stdlib.h>
/*typedef struct _subject
{
	int mat,kor,eng;
	
}subject;
int main(){
	subject s[3];
	int i;
	for(i=0;i<3;i++){
		scanf("%d %d %d",&(s[i].kor),&(s[i].mat),&(s[i].eng));
	}
	for(i=0;i<3;i++){
	printf("%d %d %d\n",s[i].kor,s[i].mat,s[i].eng);
	}

	return;
}*/
/*int main(){
	int arr[3]={0,1,2};
	int *p=arr;
	printf("%d %d %d %d",arr[1],*(arr+1),*(p+1),p[1]);
	return 0;
}*/
int main(){
	int *p,i;
	p=(int*)malloc(sizeof(int)*5);
	for(i=0;i<5;i++){
		scanf("%d",p[i]);}
	for(i=0;i<5;i++){
		printf("%d",p[i]);}
	free(p);
	return 0;
}






