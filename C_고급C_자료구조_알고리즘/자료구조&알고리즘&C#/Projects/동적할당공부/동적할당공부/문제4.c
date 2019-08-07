#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
	int y, h,i,j;
	char **p, sav = 'a';


	scanf("%d %d", &y, &h);

	p = (char**)calloc(h , sizeof(char*));

	for (i = 0; i < h; i++) {
		p[i] = (char*)calloc(y , sizeof(char));
	}

	for (i = 0; i < h; i++) {
		for (j = 0; j < y; j++) {
			p[i][j] = sav;
			
			if (sav=='z') {
				sav= 'A' - 1;
			}
			if (sav=='Z') {
				sav = 'a' - 1;
			}
			sav = sav + 1;
		}
	}

	for (i = 0; i < h; i++) {
		for (j = 0; j < y; j++) {
			printf("%c ", p[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < h; i++) {
		free(p[i]);
	}


	free(p);
	

}