#include <stdio.h>
#include <string.h>

typedef struct student {
	char name[10];
	int kor, eng, mat;
	double ave;
	char grad;
}student;

void main() {
	student st[50];
	int n,i;

	scanf("%d", &n);// �л� �� �Է�

	for (i = 0; i < n; i++) {
		scanf("%s %d %d %d", (st + i)->name, (st + i)->kor, (st + i)->eng, (st + i)->mat);
		printf("%s %d %d %d",
	}


}