#include <stdio.h>

void main() {
	int n,*p,cnt=0;
	int arr[50];

	scanf("%d", &n);


	for (p = arr; p < arr + n; p++) {
		scanf("%d", p);
		if (*p == 0) {
			break;
		}
		cnt++;
	}

	printf("%d", cnt);

	
	
}