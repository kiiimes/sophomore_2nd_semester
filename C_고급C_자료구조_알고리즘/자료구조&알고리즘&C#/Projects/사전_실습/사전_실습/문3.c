#include <stdio.h>
#include <stdlib.h>

int rFindElement(int a, int b, char *str, int count) {
	int mid;

	if (a == b) {
		return a;
	}

	mid = (a + b) / 2;

	//크거나 작거나와 n과 y둘다 고려해야됨
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

	//a와 b와 범위num
	scanf("%d %d %d", &a, &b,&num);

	str = (char*)malloc(sizeof(char)*(num+1));
	
	getchar();
	//NY로 구성된 문자열 입력
	scanf("%s", str);

	sav = findElement(a, b, str);

	printf("%d", sav);

	free(str);
}