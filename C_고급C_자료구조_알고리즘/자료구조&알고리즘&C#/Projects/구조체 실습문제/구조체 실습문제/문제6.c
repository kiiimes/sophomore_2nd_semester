#include <stdio.h>
#include <string.h>

typedef struct student {
	char name[20];
	double grad1,grad2,grad3;
}student;

void main() {
	student st[20];
	int n, i;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%s %lf %lf %lf", st[i].name, &st[i].grad1,&st[i].grad2,&st[i].grad3);

	for (i = 0; i < n; i++) {
		if ((st[i].grad1 + st[i].grad2 + st[i].grad3) / 3 >= 90) {
			printf("%s %.1f A\n", st[i].name, (st[i].grad1 + st[i].grad2 + st[i].grad3) / 3);
		}
		else if ((st[i].grad1 + st[i].grad2 + st[i].grad3) / 3 >= 80){
			printf("%s %.1f B\n", st[i].name, (st[i].grad1 + st[i].grad2 + st[i].grad3) / 3);
		}
		else if ((st[i].grad1 + st[i].grad2 + st[i].grad3) / 3 >= 70) {
			printf("%s %.1f C\n", st[i].name, (st[i].grad1 + st[i].grad2 + st[i].grad3) / 3);
		}
		else
			printf("%s %f F\n", st[i].name, (st[i].grad1 + st[i].grad2 + st[i].grad3) / 3);
	}





}