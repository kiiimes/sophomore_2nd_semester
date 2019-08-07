#include <stdio.h>
int swap(int *a,int *b){
	int t;
	t=*a;
	*a=*b;
	*b=t;


}
/*int main(){
	int num1,num2;
	scanf("%d %d",&num1,&num2);
	printf("%d %d\n",num1,num2);
	swap(&num1,&num2);
	printf("%d %d",num1,num2);



	return 0;
}*/
int kim(int *p){
	
	//int man;
	//man=*p;
	printf("%d",*p);
}
/*int main(){
	int a=5;
	kim(&a);
	//printf("%d",a);
	
	return 0;
}*/
void add(int *sum){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	*sum=a+b+c;


}
/*int main(){
	int sum;
	add(&sum);
	printf("%d",sum);
	



	return 0;
}*/
/*int main(){
	int arr[10];
	printf("%d\n",arr);
	printf("%d",&arr[0]);


	return 0;
}*/
void eun(int (*p)){
	int i,max;
	max=*p;
	for(i=1;i<=4;i++){
		
		if(max<*(p+i)){
			max=*(p+i);
		}
		

}
	printf("%d",max);
}


int main(){
	int arr[5]; 
	int i;
	for(i=0;i<5;i++){
		scanf("%d",&arr[i]);
	}

	eun(arr);
}





