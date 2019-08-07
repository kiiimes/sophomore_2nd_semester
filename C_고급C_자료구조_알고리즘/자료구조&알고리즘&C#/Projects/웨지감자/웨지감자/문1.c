#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)

typedef struct Quick // ��Ƽ�ǿ��Լ� �ߺ����� ó���� �� ��ġ�� �ޱ����� ����ü
{
	int a, b; // �ߺ����Ұ� ���ִ� ���� ù�� ������ ��ġ��
}quick;

void inPlaceQuickSort(int * L, int l, int r);
/*
function name : inPlaceQuickSort
pre condition(���� ����) : �Լ��� ȣ���ϸ鼭 ����Ʈ�� ó��, �� �ε������� ����Ʈ�� ���޹޴´�
function(���) : ���ڸ� �������� �����Ѵ�
*/
quick inPlacePartition(int *A, int l, int r, int k);
/*
function name : inPlacePartition
pre condition(���� ����) : �Լ��� ȣ���ϸ鼭 ����Ʈ�� ó��, �� �ε������� ����Ʈ�� ������ �� ���� ��ġ�� ���޹޴´�
function(���) : ���ذ��� �������� ��Ƽ�� �۾� ���� -> ������
*/
void arraySwap(int *A, int n1, int n2);
/*
function name : arraySwap
pre condition(���� ����) : ����Ʈ�� �ٲٰ��� �ϴ� �� ���� ��ġ ��
function(���) :  A[n1]�� A[n2]�� ���� �ٲ��ش�
*/

int findPivotIndex(int * A);
/*
function name : findPivotIndex
pre condition : ����Ʈ��
*/


int main() {
	int n, num, i;
	int * p;

	scanf("%d", &n);
	p = (int *)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++) {
		scanf("%d", p + i);
	}
	inPlaceQuickSort(p, 0, n - 1);
	for (i = 0; i < n; i++)
		printf(" %d", p[i]);
	printf("\n");
}


void inPlaceQuickSort(int * L, int l, int r) {
	int k;
	quick q;

	if (l >= r)//l�� r���� Ŀ���� �������
		return;

	k = r; // ������ �������̱� ������ ���ؿ��Ҵ� ���� �������� ��ġ�� ���̴�

	q = inPlacePartition(L, l, r, k); // �ߺ����� ������ ��Ƽ�� ȣ��

	inPlaceQuickSort(L, l, (q.a) - 1); // ���ذ� �������� ���� ���� ������
	inPlaceQuickSort(L, (q.b) + 1, r); // ���ذ� �������� ������ ���� ������
}
quick inPlacePartition(int *A, int l, int r, int k) {
	quick q;
	int i, j;
	int a, b;
	int temp_loc;
	int p;

	p = A[k]; // k�� ��ġ�� �ִ� ���� ���ذ�

	i = l; // i�� l�� ���������� �Ѵ�
	j = r - 1; // j�� r-1�� ���������� �Ѵ�

	a = l; // �ߺ��� ���Ҹ� �迭 ���� �պ��� ��Ƶд�
	b = r; // �ߺ��� ���Ҹ� �迭 ���� �ں��� ��Ƶд�

	while (i <= j) {
		while (i <= j && A[i] <= p) { // i�� l�� ���������� p���� �۰ų� �������� ã��//������
			if (A[i] == p) { // �������� ã�� ���, �ش������ �迭 ���ʿ� ��Ƶ�
				arraySwap(A, a, i); // ���� i�� ���� a�� ���� �ٲ۴�
				a++; // a�� ���� �ε��������� �̵��Ѵ�
			}
			i++;
		}

		while (i <= j && A[j] >= p) { // j�� r-1�� ���������� p���� ũ�ų� �������� ã��//ū��
			if (A[j] == p) { // �������� ã�� ���, �ش������ �迭 �����ʿ� ��Ƶ�
				b--;
				arraySwap(A, j, b);
			}
			j--;
		}
		if (i < j) {
			arraySwap(A, i, j); // i < j�� ��� i�� j�� ���� �ٲ�
		}
	}
	//�ᱹ i�� j���� �ϳ�ū����?


	// �ش� �������� �迭�� ���ʰ� �����ʿ� ��Ƶ� p�� �ߺ��Ǵ� ���� �迭 �߾����� ������
	temp_loc = i - 1; // a���� i-1�� ��ġ�� �����ϱ� ���� �ӽ÷� ����//�ߺ���
	while (a > i) {
		arraySwap(A, a, temp_loc);
		a--;
		temp_loc--;
	} // a�� i���� Ŭ �� �ߺ��� ���� �ϳ��� �߾����� �̵��Ѵ�
	a = temp_loc + 1; // a�� ���� �ߺ��� ���� ��Ƴ��� �� �� ���� ù��° ��ġ�� ������

	temp_loc = i; // a���� i�� ��ġ�� �����ϱ� ���� �ӽ÷� ����
	while (b < r + 1) {
		arraySwap(A, b, temp_loc);
		b++;
		temp_loc++;
	} // b�� r+1���� ���� �� �ߺ��� ���� �ϳ��� �߾����� �̵��Ѵ�
	b = temp_loc - 1; // b�� ���� �ߺ��� ���� ��Ƴ��� �� �� ���� ������ ��ġ�� ������

	q.a = a;
	q.b = b; // ����ü �̿��ؼ� a,b�� ���� 

	return q;
}
void arraySwap(int * A, int n1, int n2) {
	int temp; // �ӽ÷� ���� ������ ����

	temp = A[n1];
	A[n1] = A[n2];
	A[n2] = temp;
	// A[n1]�� ���� A[n2]�� ���� swap�Ѵ�
}