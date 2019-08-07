#include <stdio.h>
#include <stdlib.h>

void main() {
	int n, i;
	float *p,max;

	scanf("%d", &n);

	p = (float*)malloc(n * sizeof(float));

	for (i = 0; i < n; i++) {
		scanf("%f", p + i);
		//printf("%f", p[i]);
	}

	max = p[0];

	for (i = 0; i < n; i++) {
		if (max < p[i]) {
			max = p[i];
		}
	}
	printf("%.2f", max);

	free(p);

}