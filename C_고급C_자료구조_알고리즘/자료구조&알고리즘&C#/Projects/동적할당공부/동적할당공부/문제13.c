#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
	int n,i,j;
	char **p,sav[101];

	scanf("%d", &n);
	getchar();

	p = (char**)malloc(n * sizeof(char*));

	for (i = 0; i < n; i++) {
		scanf("%s", sav);
		p[i] = (char*)malloc((strlen(sav) + 1) * sizeof(char));
		strcpy(p[i], sav);
	}


	for (j = 0; j < n; j++) {
		for (i = 0; i < n - 1; i++) {
			if (strcmp(p[i], p[i + 1]) > 0) {
				strcpy(sav, p[i]);
				p[i] = (char*)realloc(p[i], (strlen(p[i + 1]) + 1) * sizeof(char));
				strcpy(p[i], p[i + 1]);
				p[i + 1] = (char*)realloc(p[i + 1], (strlen(sav) + 1) * sizeof(char));
				strcpy(p[i + 1], sav);
			}
		}

	}

	for (i = 0; i < n; i++) {
		printf("%s\n", p[i]);
		free(p[i]);
	}

	free(p);


}