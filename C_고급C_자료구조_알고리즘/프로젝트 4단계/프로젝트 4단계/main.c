#include <stdio.h>
#include <stdlib.h>

#include "my_struct.h"
#include "my_define.h"
#include "my_func.h"

int main(){
	int n;//함수 선택 변수
	int max_num;//최대 입력 가능한 연락처 변수
	tel **list; // 구조체 동적할당을 위한 이중 포인터
	int count=0 ;
	printf("Max_num:");
	scanf("%d",&max_num);//최대 입력가능한 연락처 수 입력
	list=(tel**)malloc(max_num*sizeof(tel*));//max_num만큼의 동적할당
	while(1){
		printf("*****Menu*****\n");
		printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.RegFromFile><6.FindName><7.Exit>\n");//시작화면
		printf("Enter_the_menu_number:");
		scanf("%d",&n);//번호 입력
		switch(n){
		case 1:insert(list,&count,max_num);break;//1번 누를시 등록 함수 시작
		case 2:show(list,&count);break;//2번 누를시 보여주는 함수 시작
		case 3:del(list,&count);break;//3번 누를시 삭제 함수 시작s
		case 4:find(list,&count);break;//4번 누를시 생일자 검색 함수 시작
		case 5:Regfromfile(&count,list);break;//5번 누를시 파일 불러오기 시작
		case 6:chofind(list,&count);break;//6번 누를시 초성으로 이름찾기 시작
		case 7:end(list,&count);break;//7번 누를시 파일 저장하고 끝내는 함수 시작
		}
		if(n==7){
			break;
		}	

	}
}