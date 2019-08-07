#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
	int n,i,j;
	char **p, sav[101] = { NULL };

	scanf("%d", &n);
	getchar();

	p = (char**)malloc(n * sizeof(char*));

	for (i = 0; i < n; i++) {
		gets_s(sav,101);
		p[i] = (char*)malloc((strlen(sav) + 1) * sizeof(char));
		strcpy(p[i], sav);
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n - 1; j++) {

			if (strlen(p[j]) < strlen(p[j + 1])) {
				strcpy(sav, p[j + 1]);
				p[j + 1] = (char*)realloc(p[j + 1], (strlen(p[j]) + 1) * sizeof(char));
				strcpy(p[j + 1], p[j]);
				p[j] = (char*)realloc(p[j], (strlen(sav) + 1) * sizeof(char));
				strcpy(p[j], sav);
			}
		}
	}
	for (i = 0; i < n; i++) {
		printf("%s\n", p[i]);
		free(p[i]);
	}
	free(p);



}