#include <stdio.h>

int modulo(int a, int b) {
	
	if (a < b) return a;
	else return modulo(a - b, b);


}

void main() {

	int a, b;

	scanf("%d %d", &a, &b);

	printf("%d", modulo(a, b));
}