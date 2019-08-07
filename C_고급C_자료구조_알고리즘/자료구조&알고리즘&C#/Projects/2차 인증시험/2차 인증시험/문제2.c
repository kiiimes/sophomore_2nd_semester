#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
	char sav[30],**p;
	int i, j, sum = 0, dae, so, etc;
	int n=1;

	p = (char**)malloc(n * sizeof(char*));

	for (i = 0;; i++) {
		gets(sav);
		p[i] = (char*)malloc((strlen(sav) + 1) * sizeof(char));
		strcpy(p[i], sav);
		sum = 0, dae = 0, so = 0, etc = 0;
		if (strlen(p[i]) != 1) {
			for (j = 0; p[i][j] != '\0'; j++) {
				if (p[i][j] >= '0'&&p[i][j] <= '9') {
					sum = sum+(p[i][j] - '0') + 0;

				}
				else if (p[i][j] >= 'A'&&p[i][j] <= 'Z') {
					dae++;
				}
				else if (p[i][j] >= 'a'&&p[i][j] <= 'z') {
					so++;
				}
				else {
					etc++;
				}
			}
			printf("%d %d %d %d\n", sum, dae, so, etc);
			n++;
			p = (char**)realloc(p,n* sizeof(char*));
		}

		if (strlen(p[i]) == 1) {
			break;
		}
	}

}