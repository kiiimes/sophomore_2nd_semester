#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct tel{
	char *name;
	char *phone;
	char *birth;
}tel;//�Է� ���� ����
void insert(tel **plist,int *cnt,int max_n){
	char a[101]={'NULL'},*temp;
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
void show(tel **plist,int *cnt){
	int i;
	for(i=0;i<(*cnt);i++){
		printf("%s %s %s\n",plist[i]->name,plist[i]->phone,plist[i]->birth);//��ϵ� ����ó ���

	}
}//����ó �����ִ� �Լ�
void del(struct tel **plist,int *cnt){
	int i,j,sav;
	char a[101]={'NULL'};

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


int main(){
	int n,i;//�Լ� ���� ����
	int max_num;//�ִ� �Է� ������ ����ó ����
	tel **list; // ����ü �����Ҵ��� ���� ���� ������
    int count=0 ;
	printf("Max_num:");
	scanf("%d",&max_num);//�ִ� �Է°����� ����ó �� �Է�
	list=(tel**)malloc(max_num*sizeof(tel*));//max_num��ŭ�� �����Ҵ�
	while(1){
	printf("*****Menu*****\n");
	printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");//����ȭ��
	printf("Enter_the_menu_number:");
	scanf("%d",&n);//��ȣ �Է�
	switch(n){
	case 1:insert(list,&count,max_num);break;//1�� ������ ��� �Լ� ����
	case 2:show(list,&count);break;//2�� ������ �����ִ� �Լ� ����
	case 3:del(list,&count);break;//3�� ������ ���� �Լ� ����
	case 4:find(list,&count);break;//4�� ������ ������ �˻� �Լ� ����
	case 5:return 0;//5�� ������ ������
	}
	
	}
	for(i=0;i<count;i++){
		free(list[i]->name);//����ü ����� �޸� ����
		free(list[i]->phone);
		free(list[i]->birth);
		free(list[i]);//����ü �޸� ����
	}
	free(list);//��ü �޸� ����
	

}