#include <stdio.h>
#include <string.h>

typedef struct student {
	char name[10];
	int grad;
}student;

void main() {
	student st[5];
	int i,sum=0;

	for (i = 0; i < 5; i++) {
		scanf("%s %d", st[i].name, &st[i].grad);
	}

	for (i = 0; i < 5; i++) {
		sum += st[i].grad;
	}

	sum =sum/5;

	for (i = 0; i < 5; i++) {
		if (st[i].grad <= sum) {
			printf("%s\n", st[i].name);
		}
	}

}