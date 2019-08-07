#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct tel{
	char *name;
	char *phone;
	char *birth;
}tel;//입력 정보 형식
void insert(tel **plist,int *cnt,int max_n){
	char a[101]={'NULL'},*temp;
	int i,j;
	if((*cnt)>=max_n){
		printf("OVERFLOW\n");
	}//연락처 최대 개수 넘을시 출력
	if(*cnt<max_n){//연락처 최대 개수 전까지
	plist[*cnt] = (tel*)malloc(sizeof(tel));//연락처 추가할때마다 자리 생성
	printf("Name:");
	scanf("%s",a);//이름입력
	plist[*cnt]->name=(char*)malloc((strlen(a)+1)*sizeof(char));//이름 크기 만큼 동적할당
	strcpy(plist[*cnt]->name,a);//a에 입력한 내용을 복사
	printf("Phone_number:");
	scanf("%s",a);//번호입력
	plist[*cnt]->phone=(char*)malloc((strlen(a)+1)*sizeof(char));
	strcpy(plist[*cnt]->phone,a);
	printf("Birth:");
	scanf("%s",a);//생일입력
	plist[*cnt]->birth=(char*)malloc((strlen(a)+1)*sizeof(char));
	strcpy(plist[*cnt]->birth,a);

	if((*cnt)!=0){
	for(i=0;i<=(*cnt);i++){
		for(j=0;j<(*cnt);j++){
			if(strcmp(plist[j]->name,plist[j+1]->name)>0){
				temp=plist[j]->name;
				plist[j]->name=plist[j+1]->name;
				plist[j+1]->name=temp;//이름 바꾸기
				temp=plist[j]->phone;
				plist[j]->phone=plist[j+1]->phone;
				plist[j+1]->phone=temp;//핸드폰 번호 바꾸기
				temp=plist[j]->birth;
				plist[j]->birth=plist[j+1]->birth;
				plist[j+1]->birth=temp;//생일바꾸기
				
			}
		}

	}
	}
	(*cnt)++;//연락처 개수
	printf("<<%d>>\n",*cnt);//현재 저장된 연락처 개수 출력
	
	}//이름 순 정렬

}//등록 함수
void show(tel **plist,int *cnt){
	int i;
	for(i=0;i<(*cnt);i++){
		printf("%s %s %s\n",plist[i]->name,plist[i]->phone,plist[i]->birth);//등록된 연락처 출력

	}
}//연락처 보여주는 함수
void del(struct tel **plist,int *cnt){
	int i,j,sav;
	char a[101]={'NULL'};

	if(*cnt==0){
		printf("NO MEMBER\n");//등록된 연락처 없으면 출력
	}

	if(*cnt!=0){
		printf("Name:");
		scanf("%s",a);//삭제할 연락처 이름 입력
	for(i=0;i<=(*cnt);i++){
		if(strcmp(a,plist[i]->name)==0){
			
	free(plist[i]->name);//구조체 멤버 메모리 해제
	free(plist[i]->phone);
	free(plist[i]->birth);
	free(plist[i]);//구조체 메모리 해제
			for(j=i;j<(*cnt)-1;j++){

				
				plist[j] = plist[j+1];//한칸씩뒤로 포인터 이동
			}
			plist[(*cnt)-1]=NULL;//맨 마지막열 포인터 아무데도 안가르키게 함
			
			(*cnt)--;//연락처 개수 수정
			break;
		}//삭제및연락처이동
	

	}
	
	
	}
	
}
void find(tel **plist,int *cnt){
	int i,st,a=0;

	char n[3]={'\0'};


	printf("Birth:");
	scanf("%s",n);//태어난 월 입력

	st=strlen(n);//태어난 월의 자리수
	for(i=0;i<(*cnt);i++){
		
		if(st==1){//태어난 월이 1~9월
			if(plist[i]->birth[5]==n[0]){
		printf("%s %s %s\n",plist[i]->name,plist[i]->phone,plist[i]->birth);
			
			}
			
	}
		if(st==2){//태어난 월이 10~12월
			if(plist[i]->birth[4]==n[0]&&plist[i]->birth[5]==n[1]){
				printf("%s %s %s\n",plist[i]->name,plist[i]->phone,plist[i]->birth);
			}

		}
	}


}


int main(){
	int n,i;//함수 선택 변수
	int max_num;//최대 입력 가능한 연락처 변수
	tel **list; // 구조체 동적할당을 위한 이중 포인터
    int count=0 ;
	printf("Max_num:");
	scanf("%d",&max_num);//최대 입력가능한 연락처 수 입력
	list=(tel**)malloc(max_num*sizeof(tel*));//max_num만큼의 동적할당
	while(1){
	printf("*****Menu*****\n");
	printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");//시작화면
	printf("Enter_the_menu_number:");
	scanf("%d",&n);//번호 입력
	switch(n){
	case 1:insert(list,&count,max_num);break;//1번 누를시 등록 함수 시작
	case 2:show(list,&count);break;//2번 누를시 보여주는 함수 시작
	case 3:del(list,&count);break;//3번 누를시 삭제 함수 시작
	case 4:find(list,&count);break;//4번 누를시 생일자 검색 함수 시작
	case 5:return 0;//5번 누를시 끝내기
	}
	
	}
	for(i=0;i<count;i++){
		free(list[i]->name);//구조체 멤버들 메모리 해제
		free(list[i]->phone);
		free(list[i]->birth);
		free(list[i]);//구조체 메모리 해제
	}
	free(list);//전체 메모리 해제
	

}