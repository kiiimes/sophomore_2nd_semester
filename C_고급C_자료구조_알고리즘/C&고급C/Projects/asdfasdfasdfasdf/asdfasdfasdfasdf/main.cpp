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
			//대문자가 시작하는 번호 저장
			cCnt[j++] = i;
			//대문자의 갯수 count
			n++;
		} 
	}

	//2차원 배열의 가로 -> 대문자의 수만큼 동적할당
	tstr = (char **) malloc(sizeof(char *)*n);


	for(i=0;i<n;i++)
	{
		j=0;
		//2차원 배열의 세로 -> 대문자로 시작하는 한 단어의 크기만큼 동적할당
		tstr[i] = (char *)malloc(sizeof(char)*cCnt[i]+1); 

		if( i != n-1 )  //마지막 단어가 아닌 경우
		{
			start = cCnt[i]; //대문자로 시작하는 한 단어의 시작점
			end = cCnt[i+1]-1; //대문자로 시작하는 한 단어의 끝

			//2차원 배열에 한 단어씩 복사
			while( start <= end )
				tstr[i][j++] = str[start++];
		}
		else //마지막 단어의 경우
		{
			start = cCnt[n-1], end = strlen(str)-1;

			while( start <= end )
				tstr[i][j++] = str[start++];
		}

		tstr[i][j] = '\0'; //마지막 NULL문자
	}

	//사전 순 가장 빠른 단어 찾기
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

	for(i=0;i<n;i++) // 메모리반환
		free(tstr[i]);
	free(tstr);

	return 0;
}