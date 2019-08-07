#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
	char str[30],sav[30];
	int i,j,n=0,cnt=0;

	scanf("%s", str);

	for (i = 0; i < strlen(str); i++) {
		if (i != 0) {
			for (j = 0; j < i; j++) {
				if (str[i] == str[j]) {
					break;
				}
				else {
					cnt++;
				}
			}
			if (cnt == i + 1) {
				sav[n] = str[i];
				n = n + 1;
			}
		}
		
		else if(i==0) {
			sav[n] = str[i];
			n = n + 1;
		}
	}
	//b0a0n
	printf("%s", sav);

}//strlen 사용, 반복문 사용 없이 문자열 출력