#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_struct.h"
#include "my_define.h"


void del(tel **plist,int *cnt){
	int i,j;
	char a[210]={'\0'};

	if(*cnt==0){
		printf("NO MEMBER\n");//��ϵ� ����ó ������ ���
	}

	if(*cnt!=0){
		printf("Name:");
		scanf("%s",a);//������ ����ó �̸� �Է�
		for(i=0;i<=(*cnt);i++){
			if(strcmp(a,plist[i]->name)==0){

				free(plist[i]->name);//����ü ��� �޸� ����
				free(plist[i]->phone);
				free(plist[i]->birth);
				free(plist[i]);//����ü �޸� ����
				for(j=i;j<(*cnt)-1;j++){


					plist[j] = plist[j+1];//��ĭ���ڷ� ������ �̵�
				}
				plist[(*cnt)-1]=NULL;//�� �������� ������ �ƹ����� �Ȱ���Ű�� ��

				(*cnt)--;//����ó ���� ����
				break;
			}//�����׿���ó�̵�


		}


	}

}