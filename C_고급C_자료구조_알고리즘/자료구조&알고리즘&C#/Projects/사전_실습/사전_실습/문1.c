#include <stdio.h>
#include <stdlib.h>

int rFindElement(int *arr, int k, int l,int r) {
	int mid;
	//ó���ؾߵǴ°� ���� ��� ������ �߿� k���� �����鼭 ���� ū ��ġ ���
	if (l > r) {
		return -1;
	}

	if (arr[r] < k) {
		return r;
	}

	mid = (l+r)/2;//����� ����


	if (k == arr[mid]) {
		return mid;
	}
	else if (k < arr[mid]) {
		if (k > arr[mid -1]) return mid-1;
		return rFindElement(arr, k, l, mid - 1);
	}//ã������ Ű�� ������� �������
	else {
		if (k < arr[mid + 1]) return mid;
		return rFindElement(arr, k, mid+1, r);
	}//ã������ Ű�� ������� ū ���
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