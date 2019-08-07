#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	int arr[10];
	int max,min;

	for (int i = 0; i < 10; i++) {
		scanf("%d", arr+i);
	}
	

	max = arr[0];
	min = arr[0];
	for (int i = 0; i < 10; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
		if (min > arr[i]) {
			min = arr[i];
		}
	}

	for (int i = max; i >= min; i--) {
		printf("  %d", i);
		for (int j = 0; j < 10; j++) {
			if (arr[j] >= i) {
				printf("#");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}

}
	