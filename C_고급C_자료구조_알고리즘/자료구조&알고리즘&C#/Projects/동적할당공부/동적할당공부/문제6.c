#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
	char name[9];
	int kor, eng, mat;
	double ave;
}student;


void main() {
	student *p;
	int n,i;

	scanf("%d", &n);
	getchar();

	p = (student*)malloc(n * sizeof(student));

	for (i = 0; i < n; i++) {
		scanf("%s %d %d %d", p[i].name,&p[i].kor, &p[i].eng, &p[i].mat);
	}

	for (i = 0; i < n; i++) {
		p[i].ave = (p[i].kor + p[i].eng + p[i].mat) / 3.0;
		printf("%s %.1f ", p[i].name, p[i].ave);
		if (p[i].kor >= 90 || p[i].eng >= 90 || p[i].mat >= 90) {
			printf("GREAT");
			if (p[i].kor < 70 || p[i].eng < 70 || p[i].mat < 70) {
				printf(" BAD");
			}
		}
		else if (p[i].kor < 70 || p[i].eng < 70 || p[i].mat < 70) {
			printf("BAD");
		}
		printf("\n");
	}


}