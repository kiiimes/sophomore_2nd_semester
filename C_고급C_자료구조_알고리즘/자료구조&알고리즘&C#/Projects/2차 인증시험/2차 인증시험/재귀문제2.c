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

}//return �� ���� e

void main() {
	int n,s;

	scanf("%d", &n);//����Ҽ�

	oil(n,&s);

	printf("%f", s);
}