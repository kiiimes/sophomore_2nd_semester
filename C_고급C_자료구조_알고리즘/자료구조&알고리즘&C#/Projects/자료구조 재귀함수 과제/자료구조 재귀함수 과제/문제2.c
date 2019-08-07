#include <stdio.h>

int jari(int n) {
	
	if (n / 10 == 0) { 
		printf("%d", n);
		return ; }
	else {
		jari(n / 10);
		printf(" %d", n%10);
		
	}
}

void main() {
	int n;

	scanf("%d", &n);

	jari(n);


}