#include <stdio.h>
#include <string.h>

int gumsaek(char str[101], char mun,int num,int cnt) {
	
	if (num == 0) {
		if (str[num] == mun) {
			cnt++;
		}
		return cnt;
	}
	else {
		if (str[num] == mun) {
			cnt++;
		}
		return gumsaek(str, mun, num - 1, cnt);
	}

}

void main() {
	char str[101],mun;
	int cnt = 0;

	scanf("%s", str);
	getchar();

	scanf("%c",&mun);

	printf("%d",gumsaek(str, mun,strlen(str)-1,cnt));



}