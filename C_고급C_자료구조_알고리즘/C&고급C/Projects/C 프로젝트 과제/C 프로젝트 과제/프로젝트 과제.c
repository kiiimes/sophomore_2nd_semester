#include <stdio.h>
#include <string.h>
#define max_num 100
struct tel{
	char name[21];
	char phone[16];
	char birth[9];
};//�Է� ���� ����
void insert(struct tel *plist,int *cnt){
	char a[21]={'NULL'};
	int i,j;
	if((*cnt)>=max_num){
		printf("OVERFLOW\n");
	}//����ó ���� 100�� ������ ���
	if(*cnt<max_num){//����ó 100�� ������
	printf("Name:");
	scanf("%s",plist[*cnt].name);//�̸��Է�
	printf("Phone_number:");
	scanf("%s",plist[*cnt].phone);//��ȣ�Է�
	printf("Birth:");
	scanf("%s",plist[*cnt].birth);//�����Է�

	if((*cnt)!=0){
	for(i=0;i<=(*cnt);i++){
		for(j=0;j<(*cnt);j++){
			if(strcmp(plist[j].name,plist[j+1].name)>0){
				strcpy(a,plist[j].name);
				strcpy(plist[j].name,plist[j+1].name);
				strcpy(plist[j+1].name,a);//�̸��ٲٱ�
				strcpy(a,plist[j].phone);
				strcpy(plist[j].phone,plist[j+1].phone);
				strcpy(plist[j+1].phone,a);//��ȣ �ٲٱ�
				strcpy(a,plist[j].birth);
				strcpy(plist[j].birth,plist[j+1].birth);
				strcpy(plist[j+1].birth,a);//���� �ٲٱ�

				
			}
		}

	}
	}
	(*cnt)++;//����ó ����
	printf("<<%d>>\n",*cnt);//���� ����� ����ó ���� ���
	
	}//�̸� �� ����

	

}//��� �Լ�

void show(struct tel *plist,int *cnt){
	int i;
	for(i=0;i<(*cnt);i++){
		printf("%s %s %s\n",plist[i].name,plist[i].phone,plist[i].birth);//��ϵ� ����ó ���

	}
}//����ó �����ִ� �Լ�
void del(struct tel *plist,int *cnt){
	int i,j;
	char a[21]={'NULL'};

	if(*cnt==0){
		printf("NO MEMBER\n");//��ϵ� ����ó ������ ���
	}

	if(*cnt!=0){
		printf("Name:");
		scanf("%s",a);//������ ����ó �̸� �Է�
	for(i=0;i<=(*cnt);i++){
		if(strcmp(a,plist[i].name)==0){
			for(j=i;j<(*cnt);j++){
				strcpy(plist[j].name,plist[j+1].name);
				strcpy(plist[j].phone,plist[j+1].phone);
				strcpy(plist[j].birth,plist[j+1].birth);
				
			}
			
			(*cnt)--;//����ó ���� ����
			break;
		}//�����׿���ó�̵�
		
	}
	
	}
	
}
void find(struct tel *plist,int *cnt){
	int i,st,a=0;

	char n[3]={'\0'};


	printf("Birth:");
	scanf("%s",n);//�¾ �� �Է�

	st=strlen(n);//�¾ ���� �ڸ���
	for(i=0;i<(*cnt);i++){
		
		if(st==1){//�¾ ���� 1~9��
			if(plist[i].birth[5]==n[0]){
		printf("%s %s %s\n",plist[i].name,plist[i].phone,plist[i].birth);
			
			}
			
	}
		if(st==2){//�¾ ���� 10~12��
			if(plist[i].birth[4]==n[0]&&plist[i].birth[5]==n[1]){
				printf("%s %s %s\n",plist[i].name,plist[i].phone,plist[i].birth);
			}

		}
	}


}


int main(){
	int n;
	struct tel list[max_num]={"NULL"}; // �ִ�100������
    int count=0 ;
	while(1){
	printf("*****Menu*****\n");
	printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");//����ȭ��
	printf("Enter_the_menu_number:");
	scanf("%d",&n);//��ȣ �Է�
	switch(n){
	case 1:insert(list,&count);break;//1�� ������ ��� �Լ� ����
	case 2:show(list,&count);break;//2�� ������ �����ִ� �Լ� ����
	case 3:del(list,&count);break;//3�� ������ ���� �Լ� ����
	case 4:find(list,&count);break;//4�� ������ ������ �˻� �Լ� ����
	case 5:return 0;//5�� ������ ������
	}
	
	}
	
	

}