#include <stdio.h>

void main() {
	int x[3];
	int *p,*temp;

	for (p = x; p < x + 3; p++) {
		if (*p > *(p + 1)) {
			temp = p;
			p = p + 1;
			p+1 = temp;
		}
	}
}