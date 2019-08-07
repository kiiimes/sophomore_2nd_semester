#include <stdio.h>

int fib(int n) {
	
	if (n == 0) return 0;
	if (n == 1) return 1;
	else return fib(n - 2) + fib(n - 1);


}

void main() {
	int n;

	scanf("%d", &n);

	printf("%d", fib(n));


}