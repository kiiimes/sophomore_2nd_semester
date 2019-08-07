#include <stdio.h>
#include <stdlib.h>

int M;
int N;

typedef struct Node {
	int key;
	int tag;
}Node;

void init(Node *arr) {
	int i;

	for (i = 0; i < M; i++) {
		arr[i].key = NULL;
		arr[i].tag= 0;
	}
}

int getNextBucket(int v,int i) {
	return (v + i) % M;
}

void insertItem(Node *arr,int num) {
	int sav = num%M;
	int i=0;

	while (i<M) {
		sav = getNextBucket(num%M,i);
		if (arr[sav].tag == 0) {
			arr[sav].key = num;
			arr[sav].tag = 1;
			printf("%d\n", sav);
			return;
		}
		else {
			printf("C");
			i++;
		}
	}
}

//search
int findElement(Node *arr, int num) {
	int sav = num%M;
	int i = 0;

	while (i < M) {
		sav = getNextBucket(num%M, i);
		if (arr[sav].tag==0) return -1;
		else if (num == arr[sav].key) {
			printf("%d ", sav);
			return arr[sav].key;
		}
		else i++;
	}
	return -1;

}

void main() {
	Node *arr;
	char type;
	int num,i;

	scanf("%d %d", &M,&N);

	arr = (Node*)malloc(sizeof(Node)*M);

	init(arr);

	while (1) {
		getchar();
		scanf("%c", &type);
		switch (type) {
		case 'i':scanf("%d", &num); insertItem(arr, num); break;
		case 's':scanf("%d", &num); printf("%d\n",findElement(arr, num)); break;
		default:break;
		}
		if (type == 'e') break;
	}
	free(arr);
}