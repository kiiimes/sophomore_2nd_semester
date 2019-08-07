#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_struct.h"
#include "my_define.h"


void del(tel **plist,int *cnt){
	int i,j;
	char a[210]={'\0'};

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