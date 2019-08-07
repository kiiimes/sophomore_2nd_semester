#include <stdio.h>
#include <stdlib.h>

int rFindElement(int *arr, int k, int l,int r) {
	int mid;
	//처리해야되는게 없을 경우 작은거 중에 k보다 작으면서 가장 큰 위치 출력
	if (l > r) {
		return -1;
	}

	if (arr[r] < k) {
		return r;
	}

	mid = (l+r)/2;//가운데를 뽑음


	if (k == arr[mid]) {
		return mid;
	}
	else if (k < arr[mid]) {
		if (k > arr[mid -1]) return mid-1;
		return rFindElement(arr, k, l, mid - 1);
	}//찾으려는 키가 가운데보다 작은경우
	else {
		if (k < arr[mid + 1]) return mid;
		return rFindElement(arr, k, mid+1, r);
	}//찾으려는 키가 가운데보다 큰 경우
}

int findElement(int *arr, int k,int n) {
	int sav;
	sav=rFindElement(arr,k,0,n-1);
	return sav;
}

void main() {
	int n,k,i,sav;
	int *arr;

	scanf("%d %d", &n,&k);

	arr = (int*)malloc(sizeof(int)*n);

	for (i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}
	
	sav=findElement(arr,k,n);

	printf(" %d", sav);

	free(arr);

}