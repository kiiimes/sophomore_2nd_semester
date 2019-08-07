#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void order(int *p1, int *p2, int *p3) {
	int i, p[3], tmp;
	p[0] = *p1;
	p[1] = *p2;
	p[2] = *p3;


	for (i = 0; i < 3; i++) {
		for (i = 0; i < 2; i++) {
			if (p[i] < p[i + 1]) {

				tmp = p[i];
				p[i] = p[i + 1];
				p[i + 1] = tmp;
			}
		}
	}

	*p1 = p[2];
	*p2 = p[1];
	*p3 = p[0];
}


void main() {
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	order(&a, &b, &c);

	printf("%d %d %d", a, b, c);
}