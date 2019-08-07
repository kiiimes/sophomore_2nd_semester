#include <stdio.h>

int c, n, m;
int scnt = 0;
int sav[10];

typedef struct stu {
	int a, b;
}stu;

int isExist(int a,int b) {
	int i;

	for (i = 0; i < scnt; i++) {
		if (sav[i] == a || sav[i] == b) return 1;
	}
	return 0;
}

int main() {
	int i,j,k,t;
	int cnt=0;
	stu arr[50];

	scanf("%d", &c);

	for (i = 0; i < c; i++) {
		cnt = 0;
		scanf("%d %d", &n, &m);

		for (j = 0; j < m; j++) {
			scanf("%d %d", &(arr[j].a), &(arr[j].b));
		}

		for (j = 0; j < m; j++) {
			sav[scnt++] = arr[j].a;
			sav[scnt++] = arr[j].b;

			for (k = j; k < m; k++) {
				if (!isExist(arr[k].a, arr[k].b)) {
					sav[scnt++] = arr[k].a;
					sav[scnt++] = arr[k].b;
				}
				if (scnt == n) {
					cnt++;
					break;
				}
			}

			scnt = 0;
		}
		printf("%d\n", cnt);
	}


}