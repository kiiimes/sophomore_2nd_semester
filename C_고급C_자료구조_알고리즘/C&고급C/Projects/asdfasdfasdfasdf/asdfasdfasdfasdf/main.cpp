#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()

{

	char str[100], min[100];

	char ** tstr;

	int cCnt[100];

	int start, end, i, j=0, n=0, mincnt=0;



	scanf("%s", str);



	for(i=0;i<strlen(str);i++){
		if ( 'A' <= str[i] && str[i] <= 'Z' )
		{
			//�빮�ڰ� �����ϴ� ��ȣ ����
			cCnt[j++] = i;
			//�빮���� ���� count
			n++;
		} 
	}

	//2���� �迭�� ���� -> �빮���� ����ŭ �����Ҵ�
	tstr = (char **) malloc(sizeof(char *)*n);


	for(i=0;i<n;i++)
	{
		j=0;
		//2���� �迭�� ���� -> �빮�ڷ� �����ϴ� �� �ܾ��� ũ�⸸ŭ �����Ҵ�
		tstr[i] = (char *)malloc(sizeof(char)*cCnt[i]+1); 

		if( i != n-1 )  //������ �ܾ �ƴ� ���
		{
			start = cCnt[i]; //�빮�ڷ� �����ϴ� �� �ܾ��� ������
			end = cCnt[i+1]-1; //�빮�ڷ� �����ϴ� �� �ܾ��� ��

			//2���� �迭�� �� �ܾ ����
			while( start <= end )
				tstr[i][j++] = str[start++];
		}
		else //������ �ܾ��� ���
		{
			start = cCnt[n-1], end = strlen(str)-1;

			while( start <= end )
				tstr[i][j++] = str[start++];
		}

		tstr[i][j] = '\0'; //������ NULL����
	}

	//���� �� ���� ���� �ܾ� ã��
	strcpy(min, tstr[0]);

	for(i=1;i<n;i++)
		if ( strcmp(min, tstr[i]) > 0 )
			strcpy(min, tstr[i]);

	for(i=0;i<n;i++)
	{
		printf("%s", tstr[i]);

		if ( !strcmp(min, tstr[i]) )
			printf("!");

		printf("\n");
	}

	for(i=0;i<n;i++) // �޸𸮹�ȯ
		free(tstr[i]);
	free(tstr);

	return 0;
}