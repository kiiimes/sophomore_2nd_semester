#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_struct.h"
#include "my_define.h"
#define JA 19


void show(tel **plist,int *cnt){
	int i;
	for(i=0;i<(*cnt);i++){
		printf("%s %s %s\n",plist[i]->name,plist[i]->phone,plist[i]->birth);//��ϵ� ����ó ���

	}
}//����ó �����ִ� �Լ�
void find(tel **plist,int *cnt){
	int i,st,a=0;

	char n[3]={'\0'};


	printf("Birth:");
	scanf("%s",n);//�¾ �� �Է�

	st=strlen(n);//�¾ ���� �ڸ���
	for(i=0;i<(*cnt);i++){

		if(st==1){//�¾ ���� 1~9��
			if(plist[i]->birth[5]==n[0]){
				printf("%s %s %s\n",plist[i]->name,plist[i]->phone,plist[i]->birth);

			}

		}
		if(st==2){//�¾ ���� 10~12��
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
		plist[*cnt] = (tel*)malloc(sizeof(tel));//����ó �߰��Ҷ����� �ڸ� ����
		plist[*cnt]->name=(char*)malloc((strlen(a)+1)*sizeof(char));//�̸� ũ�� ��ŭ �����Ҵ�
		strcpy(plist[*cnt]->name,a);//a�� �Է��� ������ ����
		plist[*cnt]->phone=(char*)malloc((strlen(b)+1)*sizeof(char));
		strcpy(plist[*cnt]->phone,b);
		plist[*cnt]->birth=(char*)malloc((strlen(c)+1)*sizeof(char));
		strcpy(plist[*cnt]->birth,c);


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

		(*cnt)++;//����ó ����


	}//�̸� �� ����
	fclose(fp);
}
void chofind(tel **plist,int *cnt){
	char chon[210]={'\0'};
	char sav[210]={'\0'};
	const char *isarr[JA] =
	{ "��", "��", "��", "��", "��","��", "��", "��","��", "��","��",
	"��", "��","��", "��", "��", "��", "��", "��" };
	const char *isarr2[JA] =
	{ "��", "��", "��", "��","��", "��", "��", "��","��", "��", "��","��", "��", "¥","��", "ī", "Ÿ", "��", "��" };

	int index = 0, i,j,d,k,count=0;
	int len ;
	printf("���� �Է�:");
	scanf("%s",chon);//�ʼ� �Է�
	for(i=0;i<*cnt;i++){
		if(i!=0){
		for(d=0;d<len;d++){
			sav[d]=NULL;
		}

	}
		count=0;
	len=strlen(plist[i]->name)/2;
	for(j=0;j<len;j++){
		for (index = 0; index < JA-1; index++)      // �ʼ� �´��� ��
		{
			if ((strcmp(isarr2[index], plist[i]->name+2*j) <= 0) && (strcmp(isarr2[index + 1],plist[i]->name+2*j) > 0))
			{
				strcat(sav, isarr[index]);
				break;
			}
		}
		if (index == JA-1 && (strcmp(isarr2[index],plist[i]->name+2*j) <= 0) && (strcmp("��", plist[i]->name+2*j) >= 0))
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
}//�ʼ� �Է� ������ �̸� ã�� �Լ�




void end(tel **plist,int *cnt){
	int i;
	FILE *fp=fopen("PHONE_BOOK.txt","w");
	for(i=0;i<*cnt;i++){
		fprintf(fp,"%s %s %s\n",plist[i]->name,plist[i]->phone,plist[i]->birth);
	}
	fclose(fp);
	for(i=0;i<*cnt;i++){
		free(plist[i]->name);//����ü ����� �޸� ����
		free(plist[i]->phone);
		free(plist[i]->birth);
		free(plist[i]);//����ü �޸� ����
	}
	free(plist);//��ü �޸� ����



}//������ �Լ���
