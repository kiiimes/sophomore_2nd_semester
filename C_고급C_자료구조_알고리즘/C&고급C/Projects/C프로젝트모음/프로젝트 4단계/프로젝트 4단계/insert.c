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
	}//����ó �ִ� ���� ������ ���
	if(*cnt<max_n){//����ó �ִ� ���� ������
		plist[*cnt] = (tel*)malloc(sizeof(tel));//����ó �߰��Ҷ����� �ڸ� ����
		printf("Name:");
		scanf("%s",a);//�̸��Է�
		plist[*cnt]->name=(char*)malloc((strlen(a)+1)*sizeof(char));//�̸� ũ�� ��ŭ �����Ҵ�
		strcpy(plist[*cnt]->name,a);//a�� �Է��� ������ ����
		printf("Phone_number:");
		scanf("%s",a);//��ȣ�Է�
		plist[*cnt]->phone=(char*)malloc((strlen(a)+1)*sizeof(char));
		strcpy(plist[*cnt]->phone,a);
		printf("Birth:");
		scanf("%s",a);//�����Է�
		plist[*cnt]->birth=(char*)malloc((strlen(a)+1)*sizeof(char));
		strcpy(plist[*cnt]->birth,a);

		if((*cnt)!=0){
			for(i=0;i<=(*cnt);i++){
				for(j=0;j<(*cnt);j++){
					if(strcmp(plist[j]->name,plist[j+1]->name)>0){
						temp=plist[j]->name;
						plist[j]->name=plist[j+1]->name;
						plist[j+1]->name=temp;//�̸� �ٲٱ�
						temp=plist[j]->phone;
						plist[j]->phone=plist[j+1]->phone;
						plist[j+1]->phone=temp;//�ڵ��� ��ȣ �ٲٱ�
						temp=plist[j]->birth;
						plist[j]->birth=plist[j+1]->birth;
						plist[j+1]->birth=temp;//���Ϲٲٱ�

					}
				}

			}
		}
		(*cnt)++;//����ó ����
		printf("<<%d>>\n",*cnt);//���� ����� ����ó ���� ���

	}//�̸� �� ����

}//��� �Լ�

