/*#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
int main1() { 
	int n;
	int ans,num,min=1,max=50,count=0,m;
		printf("up down ����!");
		srand((unsigned)time(NULL));
		ans=rand()%50+1;
		
		while(1){

			printf("\n���ڸ� ���纸���� (%d~%d������ ����)\n",min,max);
			scanf("%d",&num);
		
			if(num==ans){
				count++;
				printf("����!! %d������ ����!!",count);
				break;
			}
			else if(num>ans&&num<=50){
				count++;
				if(num>max){
					printf("�߸��Է¤�");}
				else {
				
				printf(" down!\n");
				
				max=num-1;}
			}
			else if(num<ans&&num>=1){
				count++;
				if(num<min){
					printf("\n�߸��Է¤�");}
				else {
			
				printf(" up!\n");
				min=num+1;
				}
			}
			else if(num<1||num>50)
			
			{
				count++;
				printf("�߸� �Է¤�\n");
			}

			
			if(count>=8){
				printf("\n\n��������..�� �� ������..\n\n");
				break;
			}
		}
		Sleep(3000);
		system("cls");
	return 0;
	
	}
	int main2(){
		






		return 0;
	}

	int main() { 
				int pro_num=0;
								
				while(1){
					printf("������ �������ּ���\n");
				printf("1. up down ���� \t 2. �߱�����\n �Է� : ");
					scanf("%d",&pro_num);
					if(pro_num==0){
						break;
					}
					system("cls");
				switch(pro_num){ 
				case 1: main1(); break; 
				case 2: main2(); break;
				
				}
				}
				return 0;
			}*/
#include <stdio.h>
int main(){
	int *p=NULL;
	char *pi=NULL;

	printf("%d %d",sizeof(int*),sizeof(char));




	return 0;
}

