#include <stdio.h>

typedef int INTAR[5];

void main() {

	INTAR x = { 1,4,7 };
	int i;

	for (i = 0; i < 6; i++) {
		printf(" %d", x[i]);
	}

}