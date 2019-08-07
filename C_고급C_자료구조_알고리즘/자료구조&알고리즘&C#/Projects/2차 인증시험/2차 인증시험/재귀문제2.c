#include <stdio.h>
double oil(int n,double *e) {
	double sav;

	if (n == 1) {
		*e = 1;
	}
	else {
		sav = oil(n - 1,e)*n;
		*e = *e + 1 / sav;
	}
	return sav;

}//return 할 값은 e

void main() {
	int n,s;

	scanf("%d", &n);//계산할수

	oil(n,&s);

	printf("%f", s);
}