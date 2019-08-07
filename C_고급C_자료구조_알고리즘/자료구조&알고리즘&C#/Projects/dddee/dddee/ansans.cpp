#include <stdio.h>

int n;
unsigned long long arr[100] = { 0 };


int main() {
	int c;

	scanf("%d", &c);

	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 2;
	arr[4] = 2;


	for (int i = 0; i < c; i++) {
		scanf("%d", &n);

		for (int j = 0; j < n-5; j++) {
			arr[5 + j] = arr[j] + arr[4 + j];
		}

		printf("%lld\n", arr[n - 1]);
	}


}