#include <stdio.h>

typedef struct fraction{
	int ja, mo;

}frac;

void main() {
	frac a1, a2;

	scanf("%d %d", &a1.ja, &a1.mo);
	scanf("%d %d", &a2.ja, &a2.mo);

	printf("%d/%d", a1.ja*a2.ja, a1.mo*a2.mo);
	


}