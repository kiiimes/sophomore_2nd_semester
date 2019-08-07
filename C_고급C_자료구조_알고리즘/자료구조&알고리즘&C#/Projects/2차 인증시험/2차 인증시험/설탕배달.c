#include <stdio.h>

int ucl(int p1, int p2) {
	int sav;
	if (p1/p2 == 0) {
		sav = p2;
	}
	else {
		ucl(p2,(int)p1%p2);
	}
	return sav;
	
}


void main() {
	int a, b,i;
	
	scanf("%d %d", &a, &b);

	printf("%d",ucl(a, b));

}