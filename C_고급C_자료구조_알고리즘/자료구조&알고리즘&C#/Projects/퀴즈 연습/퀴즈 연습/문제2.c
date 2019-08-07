#include <stdio.h>

int jari(int n) {

	if (0 < n&&n < 10) {
		return n;
	}
	else {
		return jari(n / 10) ;
	}
}

void main() {
	
	int n;

	scanf("%d", &n);

	printf("%d", jari(n));




}