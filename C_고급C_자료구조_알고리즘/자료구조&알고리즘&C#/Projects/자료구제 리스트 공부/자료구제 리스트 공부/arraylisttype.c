#include <stdio.h>
#define SIZE 100
typedef int element;

typedef struct ArrayListType{
	element list[SIZE];
	int length;
}ArrayListType;//배열과 길이 선언

void init(ArrayListType *L) {
	L->length = 0;
}

int is_empty(ArrayListType *L) {
	if (L->length == 0) {
		return 1;
	}
	return 0;
}

int is_full(ArrayListType *L) {
	if (L->length == SIZE - 1) {
		return 1;
	}
	return 0;
}

void add(ArrayListType *L, int position, element item) {
	if (is_full(L)==0&&position>=0&&position<=L->length) {
		int i;
		
				for (i = L->length -1; i >position; i--) {
					L->list[i+1] = L->list[i];
				}
				L->list[i] = item;
			}
	L->length++;
}

element delete(ArrayListType *L, int position) {
	//해당되는 값 삭제
	//그 다음 값을 다 앞으로 당김
	element p;
	int i;

	if (position > L->length - 1 || position < 0) {
		printf("위치오류");
	}
	else {
		p = L->list[position];
		for (i = position; i < L->length - 1; i++) {
			L->list[i] = L->list[i + 1];
		}
		L->length--;
	}
}






void main() {



}