#include <stdio.h>
#include <stdlib.h>

#include "my_struct.h"
#include "my_define.h"
#include "my_func.h"

int main(){
	int n;//�Լ� ���� ����
	int max_num;//�ִ� �Է� ������ ����ó ����
	tel **list; // ����ü �����Ҵ��� ���� ���� ������
	int count=0 ;
	printf("Max_num:");
	scanf("%d",&max_num);//�ִ� �Է°����� ����ó �� �Է�
	list=(tel**)malloc(max_num*sizeof(tel*));//max_num��ŭ�� �����Ҵ�
	while(1){
		printf("*****Menu*****\n");
		printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.RegFromFile><6.FindName><7.Exit>\n");//����ȭ��
		printf("Enter_the_menu_number:");
		scanf("%d",&n);//��ȣ �Է�
		switch(n){
		case 1:insert(list,&count,max_num);break;//1�� ������ ��� �Լ� ����
		case 2:show(list,&count);break;//2�� ������ �����ִ� �Լ� ����
		case 3:del(list,&count);break;//3�� ������ ���� �Լ� ����s
		case 4:find(list,&count);break;//4�� ������ ������ �˻� �Լ� ����
		case 5:Regfromfile(&count,list);break;//5�� ������ ���� �ҷ����� ����
		case 6:chofind(list,&count);break;//6�� ������ �ʼ����� �̸�ã�� ����
		case 7:end(list,&count);break;//7�� ������ ���� �����ϰ� ������ �Լ� ����
		}
		if(n==7){
			break;
		}	

	}
}