#include <stdio.h>
#include <stdlib.h>


void fun(int *p){//int *p��� int p[]�� ���൵ �� �ް� �ؼ��� �� *p����


	int i;
	for(i=0;i<5;i++){
		printf("%d",p[i]);
	}

}

int main(){
	int arr[5]={0,1,2,3,4};
	fun(arr);//�̷��� �Ǹ� int *p=arr�� �Ȱ���



	return 0;
}
