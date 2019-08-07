#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
	char str1[100], str2[100], sav[100] = { NULL };
	int i,j,cnt=0,k,z;

	gets(str1);
	scanf("%s",str2);

	for (i = 0;; i++) {
		if (str1[i] == ' ') {
			for (z = 0; sav[z] != '\0'; z++) {
				sav[z] = '\0';
			}
			for (j = 0; j < i; j++) {
				sav[j] = str1[j];
			}
			if (strcmp(sav, str2) == 0) {
				cnt++;
			}
			for (k = 0; str1[k] != '\0'; k++) {
				str1[k] = str1[i+1+k];
			}
			printf("%s\n", sav);
			i = -1;
		}
		else if (str1[i] == '\0') {
			for (z = 0; sav[z] != '\0'; z++) {
				sav[z] = '\0';
			}
			for (j = 0; j < i; j++) {
				sav[j] = str1[j];
			}
			if (strcmp(sav, str2) == 0) {
				cnt++;
			}
		
			printf("%s\n", sav);
			break;
		}
		}
	
	printf("%d", cnt);



}