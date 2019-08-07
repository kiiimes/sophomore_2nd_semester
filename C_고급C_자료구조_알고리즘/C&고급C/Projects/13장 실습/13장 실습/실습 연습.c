#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define JAEM 19
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
void Regfromfile(int *cnt,tel **plist){
	char a[210]={NULL},b[101],c[101],*temp;
	FILE *fp;
	int i,j;
	fp=fopen("PHONE_BOOK.txt","r");
	if(fp == NULL){
		return ;
	}
	while((fscanf(fp,"%s %s %s",a,b,c) != EOF))
	{
		plist[*cnt] = (tel*)malloc(sizeof(tel));//연락처 추가할때마다 자리 생성
		plist[*cnt]->name=(char*)malloc((strlen(a)+1)*sizeof(char));//이름 크기 만큼 동적할당
		strcpy(plist[*cnt]->name,a);//a에 입력한 내용을 복사
		plist[*cnt]->phone=(char*)malloc((strlen(b)+1)*sizeof(char));
		strcpy(plist[*cnt]->phone,b);
		plist[*cnt]->birth=(char*)malloc((strlen(c)+1)*sizeof(char));
		strcpy(plist[*cnt]->birth,c);


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

		(*cnt)++;//연락처 개수


	}//이름 순 정렬
	fclose(fp);
}
void chofind(tel **plist,int *cnt){
	char chon[210]={'\0'};
	char sav[210]={'\0'};
	const char *isarr[JAEM] =
	{ "ㄱ", "ㄲ", "ㄴ", "ㄷ", "ㄸ","ㄹ", "ㅁ", "ㅂ","ㅃ", "ㅅ","ㅆ",
	"ㅇ", "ㅈ","ㅉ", "ㅊ", "ㅋ", "ㅌ", "ㅍ", "ㅎ" };
	const char *isarr2[JAEM] =
	{ "가", "까", "나", "다","따", "라", "마", "바","빠", "사", "싸","아", "자", "짜","차", "카", "타", "파", "하" };

	int index = 0, i,j,d,k,count=0;
	int len ;
	printf("자음 입력:");
	scanf("%s",chon);//초성 입력
	for(i=0;i<*cnt;i++){
		if(i!=0){
		for(d=0;d<len;d++){
			sav[d]=NULL;
		}

	}
		count=0;
	len=strlen(plist[i]->name)/2;
	for(j=0;j<len;j++){
		for (index = 0; index < JAEM-1; index++)      // 초성 맞는지 비교
		{
			if ((strcmp(isarr2[index], plist[i]->name+2*j) <= 0) && (strcmp(isarr2[index + 1],plist[i]->name+2*j) > 0))
			{
				strcat(sav, isarr[index]);
				break;
			}
		}
		if (index == JAEM-1 && (strcmp(isarr2[index],plist[i]->name+2*j) <= 0) && (strcmp("힞", plist[i]->name+2*j) >= 0))
		{
			strcat(sav, isarr[index]);
		}
		if(j==len-1){
			for(k=0;k<strlen(chon);k++){
				if(chon[k]==sav[k]){
					count++;
				}

			}
			if(count==strlen(chon)){
				printf("%s %s %s\n",plist[i]->name,plist[i]->phone,plist[i]->birth);
				 
				
			}
		}

	}


	}
}//초성 입력 받으면 이름 찾는 함수

void end(tel **plist,int *cnt){
	int i;
	FILE *fp=fopen("PHONE_BOOK.txt","w");
	for(i=0;i<*cnt;i++){
		fprintf(fp,"%s %s %s\n",plist[i]->name,plist[i]->phone,plist[i]->birth);
	}
	fclose(fp);
	for(i=0;i<*cnt;i++){
		free(plist[i]->name);//구조체 멤버들 메모리 해제
		free(plist[i]->phone);
		free(plist[i]->birth);
		free(plist[i]);//구조체 메모리 해제
	}
	free(plist);//전체 메모리 해제



}//끝내는 함수둥



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
		printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.RegFromFile><6.FindName><7.Exit>\n");//시작화면
		printf("Enter_the_menu_number:");
		scanf("%d",&n);//번호 입력
		switch(n){
		case 1:insert(list,&count,max_num);break;//1번 누를시 등록 함수 시작
		case 2:show(list,&count);break;//2번 누를시 보여주는 함수 시작
		case 3:del(list,&count);break;//3번 누를시 삭제 함수 시작
		case 4:find(list,&count);break;//4번 누를시 생일자 검색 함수 시작
		case 5:Regfromfile(&count,list);break;//5번 누를시 파일 불러오기 시작
		case 6:chofind(list,&count);break;//6번 누를 시 초성으로 이름 찾는 함수 시작
		case 7:end(list,&count);break;//6번 누를시 파일 저장하고 끝내는 함수 시작
		}
		if(n==7){

			break;
		}	

	}
}