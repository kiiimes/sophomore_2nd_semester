#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
	int n,i;
	char **p, sav[101], min[101] = { NULL };

	scanf("%d", &n);
	getchar();

	p = (char**)malloc(n * sizeof(char*));

	for (i = 0; i < n; i++) {
		gets(sav);
		p[i] = (char*)malloc((strlen(sav) + 1) * sizeof(char));
		strcpy(p[i], sav);
	}

	strcpy(min,p[0]);

	for (i = 0; i < n; i++) {
		if (strlen(min) > strlen(p[i])) {
			strcpy(min, p[i]);
		}
	}

	printf("%s", min);

	for (i = 0; i < n; i++) {
		free(p[i]);
	}
	free(p);

}