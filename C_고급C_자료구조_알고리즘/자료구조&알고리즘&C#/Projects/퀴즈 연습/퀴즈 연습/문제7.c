#include <stdio.h>
#include <string.h>

int count(char arr[20], char s,int i) {

	printf("%d", i);
	if (i==0) {
		if (arr[i] == s) {
			return 1;
		}
		else return 0;
	}
	else  if(arr[i]==s){
		return 1 + count(arr[i], s, i - 1);
	}
	else if(arr[i]!=s){
		return count(arr[i], s, i - 1);
	}
}

void main() {
	char arr[101] = { '\0' },s;
	int i = 0;


	scanf("%s", arr);

	getchar();

	scanf("%c", &s);

	printf("%d",count(arr, s, strlen(arr) - 1));



	//s�� ���� ù��°�� s������ 2��°
	//���� ��Ÿ���� s�� ���� �̿�


}