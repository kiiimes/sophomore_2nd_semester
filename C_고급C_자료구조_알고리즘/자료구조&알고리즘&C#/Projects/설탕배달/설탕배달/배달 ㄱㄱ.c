#include <stdio.h>

int main() {
	int n, i, cnt[4] = { 0 }, min;

	scanf("%d", &n);

	if (n % 5 == 0) {
		cnt[0] = n / 5;
	}
	else if (n % 3 == 0) {
		cnt[1] = n / 3;
	}
	else if ((int)n % 5 == 3) {
		cnt[2] = n / 5 + 1;
	}
	else if (n % 3 == 5) {
		cnt[3] = n / 3 + 1;
	}
	else {
		printf("-1");
		return 0;
	}
	min = cnt[0];
	for (i = 0; i < 4; i++) {
		if (min > cnt[i]) {
			min = cnt[i];
		}
	}
	printf("%d", min);
	return 0;


}