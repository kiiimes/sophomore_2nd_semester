/*#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
int main1() { 
	int n;
	int ans,num,min=1,max=50,count=0,m;
		printf("up down 게임!");
		srand((unsigned)time(NULL));
		ans=rand()%50+1;
		
		while(1){

			printf("\n숫자를 맞춰보세요 (%d~%d까지의 정수)\n",min,max);
			scanf("%d",&num);
		
			if(num==ans){
				count++;
				printf("정답!! %d번만에 성공!!",count);
				break;
			}
			else if(num>ans&&num<=50){
				count++;
				if(num>max){
					printf("잘못입력ㅎ");}
				else {
				
				printf(" down!\n");
				
				max=num-1;}
			}
			else if(num<ans&&num>=1){
				count++;
				if(num<min){
					printf("\n잘못입력ㅎ");}
				else {
			
				printf(" up!\n");
				min=num+1;
				}
			}
			else if(num<1||num>50)
			
			{
				count++;
				printf("잘못 입력ㅎ\n");
			}

			
			if(count>=8){
				printf("\n\n개빠가네..걍 넌 포기해..\n\n");
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
					printf("게임을 선택해주세요\n");
				printf("1. up down 게임 \t 2. 야구게임\n 입력 : ");
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

