#include <stdio.h>

typedef struct complex {
	double real, imag;
}complex;

complex add(complex n1, complex n2) {
	complex sav;
	
	sav.real = n1.real + n2.real;
	sav.imag = n1.imag + n2.imag;

	return sav;
}

void main() {
	complex c1, c2,sv;
	int i;

	scanf("%lf %lf %lf %lf", &c1.real, &c1.imag, &c2.real, &c2.imag);

	sv=add(c1, c2);

	printf("%.1f + %.1fi", sv.real, sv.imag);
}