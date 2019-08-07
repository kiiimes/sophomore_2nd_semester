#include <stdio.h>

void main() {
	int x, y, z;
	int *px=&x, *py=&y, *pz=&z, *temp;

	scanf("%d", px);
	scanf("%d", py);
	scanf("%d", pz);
	
	x = *px;
	y = *py;
	z = *pz;

	temp = py;
	py = px;
	px = pz;
	pz = temp;
	

	printf("%d %d %d", *px, *py, *pz);


}