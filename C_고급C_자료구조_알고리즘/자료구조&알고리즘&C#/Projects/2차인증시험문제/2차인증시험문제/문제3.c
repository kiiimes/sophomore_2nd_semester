#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char str1[101], str2[101], sav[101] = { NULL };
	int i, cnt = 0, j, k, fcnt = 0;

	gets(str1);
	scanf("%s", str2);// ют╥б

	for (i = 0; i < strlen(str1); i++) {
		if (str1[i] == ' ') {
			cnt = 0;
			for (j = 0; j < i; j++) {
				sav[j] = str1[j];
				if (sav[j] == str2[j]) {
					cnt++;
				}

			}
			if (cnt == strlen(str2)) {
				fcnt++;
			}
			for (k = 0; str1[i + 1 + k] != '\0'; k++) {
				str1[k] = str1[i + 1 + k];
			}
			str1[i + 1 + k] = '\0';
			sav[i] = '\0';
			printf("%s\n", sav);
			i = 0;

		}


	}

	printf("%s", str1);
	cnt = 0;
	for (i = 0; i < strlen(str1); i++) {
		
		if (str1[i] == str2[i]) {
			cnt++;
		}

	}
	if (cnt == strlen(str2)) {
		fcnt++;
	}
	printf("%d", fcnt);
}