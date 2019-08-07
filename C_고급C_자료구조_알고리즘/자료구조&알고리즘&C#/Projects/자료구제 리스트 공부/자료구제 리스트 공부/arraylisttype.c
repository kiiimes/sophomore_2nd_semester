#include <stdio.h>
#define SIZE 100
typedef int element;

typedef struct ArrayListType{
	element list[SIZE];
	int length;
}ArrayListType;//�迭�� ���� ����

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
	//�ش�Ǵ� �� ����
	//�� ���� ���� �� ������ ���
	element p;
	int i;

	if (position > L->length - 1 || position < 0) {
		printf("��ġ����");
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