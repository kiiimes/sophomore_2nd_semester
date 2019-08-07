#include <stdio.h>
#include <string.h>

void main() {
	char ch[21];
	int i,j;


	scanf("%s", ch);

	for (i = 0; *(ch+i) != '#'; i++) {
		
	}

	for (j = i - 1; j >= 0; j--) {
		printf("%c", *(ch + j));
	}
		
}