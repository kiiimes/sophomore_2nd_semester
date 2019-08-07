#include <string.h>

#define JAEM 19

const char *GetInitialSound(const char *han_src)
{
	
	const char *isarr[JAEM] =
	{ "��", "��", "��", "��", "��","��", "��", "��","��", "��","��",
	"��", "��","��", "��", "��", "��", "��", "��" };
	const char *isarr2[JAEM] =
	{ "��", "��", "��", "��","��", "��", "��", "��","��", "��", "��","��", "��", "¥","��", "ī", "Ÿ", "��", "��" };

	char name[100] = { '\0' };

	int index = 0, i;
	int len = strlen(han_src) / 2;
	for (i = 0; i < len; i++)      //���� ����ŭ �ݺ�
	{
		for (index = 0; index < JAEM-1; index++)      // �ʼ� �´��� ��
		{
			if ((strcmp(isarr2[index], han_src + 2 * i) <= 0) && (strcmp(isarr2[index + 1], han_src + 2 * i) > 0))
			{
				strcat(name, isarr[index]);
				break;
			}
		}
		if (index == JAEM-1 && (strcmp(isarr2[index], han_src + (2 * i)) <= 0) && (strcmp("��", han_src + (2 * i)) >= 0))
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
		printf("�̸� : ");
		scanf("%s", name);
		if (strcmp(name, "break") == 0)
			break;
		printf("�ʼ� : %s\n", GetInitialSound(name));
	}
	return 0;

}