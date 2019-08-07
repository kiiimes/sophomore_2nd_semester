#include <string.h>

#define JAEM 19

const char *GetInitialSound(const char *han_src)
{
	
	const char *isarr[JAEM] =
	{ "ㄱ", "ㄲ", "ㄴ", "ㄷ", "ㄸ","ㄹ", "ㅁ", "ㅂ","ㅃ", "ㅅ","ㅆ",
	"ㅇ", "ㅈ","ㅉ", "ㅊ", "ㅋ", "ㅌ", "ㅍ", "ㅎ" };
	const char *isarr2[JAEM] =
	{ "가", "까", "나", "다","따", "라", "마", "바","빠", "사", "싸","아", "자", "짜","차", "카", "타", "파", "하" };

	char name[100] = { '\0' };

	int index = 0, i;
	int len = strlen(han_src) / 2;
	for (i = 0; i < len; i++)      //글자 수만큼 반복
	{
		for (index = 0; index < JAEM-1; index++)      // 초성 맞는지 비교
		{
			if ((strcmp(isarr2[index], han_src + 2 * i) <= 0) && (strcmp(isarr2[index + 1], han_src + 2 * i) > 0))
			{
				strcat(name, isarr[index]);
				break;
			}
		}
		if (index == JAEM-1 && (strcmp(isarr2[index], han_src + (2 * i)) <= 0) && (strcmp("힝", han_src + (2 * i)) >= 0))
		{
			strcat(name, isarr[index]);
		}
	}
	return name;
}


#include <stdio.h>
int main()
{ 
	char name[100];

	while (1)
	{
		printf("이름 : ");
		scanf("%s", name);
		if (strcmp(name, "break") == 0)
			break;
		printf("초성 : %s\n", GetInitialSound(name));
	}
	return 0;

}