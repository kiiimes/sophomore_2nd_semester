#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
	int n,i,cnt=0;
	char *p;

	scanf("%d", &n);
	getchar();

	p = (char*)malloc((n + 1) * sizeof(char));

	scanf("%s", p);

	for (i = 0; i < n-2; i++) {
		if (p[i] == 'c'&&p[i + 1] == 'a'&&p[i + 2] == 't') {
			cnt++;
		}
	}
	printf("%d", cnt);

}