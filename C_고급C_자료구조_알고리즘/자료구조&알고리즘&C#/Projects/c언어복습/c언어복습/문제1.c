#include <stdio.h>
void main() {
	char str[101],sav;
	int i,j;
	
	scanf("%s", str);

	for (i = 0; i < strlen(str); i++) {
		printf("%s\n", str);
		sav = str[0];
		for (j = 0; j < strlen(str) - 1; j++) {
			str[j] = str[j + 1];
		}
		str[strlen(str) - 1] = sav;
	}

}
//¹®Á¦4