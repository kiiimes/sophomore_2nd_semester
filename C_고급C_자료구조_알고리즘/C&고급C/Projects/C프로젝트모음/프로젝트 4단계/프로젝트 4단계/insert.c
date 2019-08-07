#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_struct.h"
#include "my_define.h"


void insert(tel **plist,int *cnt,int max_n){
	char a[210]={'NULL'},*temp;
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

