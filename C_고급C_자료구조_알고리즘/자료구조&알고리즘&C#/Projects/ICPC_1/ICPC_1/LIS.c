#include <stdio.h>

int n;
int arr[501];
int sarr[501] = { 0 };

int sav;
int s;

int calc(int ind) {

	if (ind >= n) return 0;

	int cnt = 0;

	for (int i = ind; i < n; i++) {
		if (arr[ind] < arr[i]) {
			cnt++;
			calc(ind+1);
		}
	}

	sarr[ind] = cnt;
	calc(ind + 1);

	return 0;
}

int main() {
	int c;

	scanf("%d", &c);

	for (int i = 0; i < c; i++) {
		scanf("%d", &n);

		for (int j = 0; j < n; j++) {
			scanf("%d", arr + j);
		}
		for (int j = 0; j < n; j++) {
			cnt = 0;
			calc(j);
			if(j==0) s = cnt;
			else {
				if (s < cnt)s = cnt;
			}
		}
		printf("%d\n", s);
	}
}