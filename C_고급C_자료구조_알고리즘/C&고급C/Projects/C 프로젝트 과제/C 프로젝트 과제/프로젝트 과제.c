#include <stdio.h>
#include <string.h>
#define max_num 100
struct tel{
	char name[21];
	char phone[16];
	char birth[9];
};//입력 정보 형식
void insert(struct tel *plist,int *cnt){
	char a[21]={'NULL'};
	int i,j;
	if((*cnt)>=max_num){
		printf("OVERFLOW\n");
	}//연락처 개수 100개 넘을시 출력
	if(*cnt<max_num){//연락처 100개 전까지
	printf("Name:");
	scanf("%s",plist[*cnt].name);//이름입력
	printf("Phone_number:");
	scanf("%s",plist[*cnt].phone);//번호입력
	printf("Birth:");
	scanf("%s",plist[*cnt].birth);//생일입력

	if((*cnt)!=0){
	for(i=0;i<=(*cnt);i++){
		for(j=0;j<(*cnt);j++){
			if(strcmp(plist[j].name,plist[j+1].name)>0){
				strcpy(a,plist[j].name);
				strcpy(plist[j].name,plist[j+1].name);
				strcpy(plist[j+1].name,a);//이름바꾸기
				strcpy(a,plist[j].phone);
				strcpy(plist[j].phone,plist[j+1].phone);
				strcpy(plist[j+1].phone,a);//번호 바꾸기
				strcpy(a,plist[j].birth);
				strcpy(plist[j].birth,plist[j+1].birth);
				strcpy(plist[j+1].birth,a);//생일 바꾸기

				
			}
		}

	}
	}
	(*cnt)++;//연락처 개수
	printf("<<%d>>\n",*cnt);//현재 저장된 연락처 개수 출력
	
	}//이름 순 정렬

	

}//등록 함수

void show(struct tel *plist,int *cnt){
	int i;
	for(i=0;i<(*cnt);i++){
		printf("%s %s %s\n",plist[i].name,plist[i].phone,plist[i].birth);//등록된 연락처 출력

	}
}//연락처 보여주는 함수
void del(struct tel *plist,int *cnt){
	int i,j;
	char a[21]={'NULL'};

	if(*cnt==0){
		printf("NO MEMBER\n");//등록된 연락처 없으면 출력
	}

	if(*cnt!=0){
		printf("Name:");
		scanf("%s",a);//삭제할 연락처 이름 입력
	for(i=0;i<=(*cnt);i++){
		if(strcmp(a,plist[i].name)==0){
			for(j=i;j<(*cnt);j++){
				strcpy(plist[j].name,plist[j+1].name);
				strcpy(plist[j].phone,plist[j+1].phone);
				strcpy(plist[j].birth,plist[j+1].birth);
				
			}
			
			(*cnt)--;//연락처 개수 수정
			break;
		}//삭제및연락처이동
		
	}
	
	}
	
}
void find(struct tel *plist,int *cnt){
	int i,st,a=0;

	char n[3]={'\0'};


	printf("Birth:");
	scanf("%s",n);//태어난 월 입력

	st=strlen(n);//태어난 월의 자리수
	for(i=0;i<(*cnt);i++){
		
		if(st==1){//태어난 월이 1~9월
			if(plist[i].birth[5]==n[0]){
		printf("%s %s %s\n",plist[i].name,plist[i].phone,plist[i].birth);
			
			}
			
	}
		if(st==2){//태어난 월이 10~12월
			if(plist[i].birth[4]==n[0]&&plist[i].birth[5]==n[1]){
				printf("%s %s %s\n",plist[i].name,plist[i].phone,plist[i].birth);
			}

		}
	}


}


int main(){
	int n;
	struct tel list[max_num]={"NULL"}; // 최대100개가능
    int count=0 ;
	while(1){
	printf("*****Menu*****\n");
	printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");//시작화면
	printf("Enter_the_menu_number:");
	scanf("%d",&n);//번호 입력
	switch(n){
	case 1:insert(list,&count);break;//1번 누를시 등록 함수 시작
	case 2:show(list,&count);break;//2번 누를시 보여주는 함수 시작
	case 3:del(list,&count);break;//3번 누를시 삭제 함수 시작
	case 4:find(list,&count);break;//4번 누를시 생일자 검색 함수 시작
	case 5:return 0;//5번 누를시 끝내기
	}
	
	}
	
	

}