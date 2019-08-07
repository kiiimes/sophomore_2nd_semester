#include <stdio.h>
#include <stdlib.h>

int rFindElement(int a, int b, char *str, int count) {
	int mid;

	if (a == b) {
		return a;
	}

	mid = (a + b) / 2;

	//ũ�ų� �۰ų��� n�� y�Ѵ� ����ؾߵ�
	count++;
	if (str[count] == 'N') {
		return rFindElement(a, mid, str, count);
	}
	if (str[count] == 'Y') {
		return rFindElement(mid + 1, b, str, count);
	}

}

int findElement(int a, int b, char *str) {
	int sav;
	sav = rFindElement(a, b, str,-1);
	return sav;
}

void main() {
	int a, b,num,i,sav;
	char *str;

	//a�� b�� ����num
	scanf("%d %d %d", &a, &b,&num);

	str = (char*)malloc(sizeof(char)*(num+1));
	
	getchar();
	//NY�� ������ ���ڿ� �Է�
	scanf("%s", str);

	sav = findElement(a, b, str);

	printf("%d", sav);

	free(str);
}