#include <stdio.h>
#include <stdlib.h>

int findElement(int *arr, int k, int l,int r) {
	int mid;
	//ó���ؾߵǴ°� ���� ��� ������ �߿� k���� �����鼭 ���� ū ��ġ ���
	
	if (arr[l] > k) {
		return l;
	}
	else if (arr[r] < k) {
		return r+1;
	}

	while (l < r) {
		mid = (r + l) / 2;
		if (k == arr[mid]) {
			return mid;
		}
		else if (k < arr[mid]) {
			if (k > arr[mid - 1]) return mid;
			r = mid - 1;
		}
		else {
			if (k < arr[mid + 1]) return mid+1;
			l = mid + 1;
		}
	}
	
}

void main() {
	int n, k, i, sav;
	int *arr;

	scanf("%d %d", &n, &k);

	arr = (int*)malloc(sizeof(int)*n);

	for (i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}

	sav=findElement(arr, k, 0, n - 1);

	printf(" %d", sav);

	free(arr);
}