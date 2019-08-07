#include <stdio.h>
#include <stdlib.h>


void fun(int *p){//int *p대신 int p[]를 써줘도 됨 앵간 해서는 걍 *p쓰셈


	int i;
	for(i=0;i<5;i++){
		printf("%d",p[i]);
	}

}

int main(){
	int arr[5]={0,1,2,3,4};
	fun(arr);//이렇게 되면 int *p=arr이 된거임



	return 0;
}
