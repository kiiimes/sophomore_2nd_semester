#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
	int n,i,cnt1=0,cnt2=0;
	char *p,a,b;

	scanf("%d", &n);

	p = (char*)malloc((n+1) * sizeof(char));

	getchar();

	gets(p);

	scanf("%c %c", &a, &b);

	for (i = 0; i < n; i++) {
		if (p[i] == a) {
			cnt1++;
		}
		if (p[i] == b) {
			cnt2++;
		}
	}

	printf("%d %d", cnt1, cnt2);

	free(p);
}