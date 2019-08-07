
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#define N 1000 // ����Ʈ�� ũ��
#define Limit 50 // ���� ���ĵ�, ���� �����ĵ� ����Ʈ�� ���� ������ ����

typedef struct Arrays // ����Ʈ 6���� �����ϱ� ���� ����ü ����
{
	int *A, *B, *C, *A1, *B1, *C1; // �� 6���� ����Ʈ
}arrays;
typedef struct Quick // ��Ƽ�ǿ��Լ� �ߺ����� ó���� �� ��ġ�� �ޱ����� ����ü
{
	int a, b; // �ߺ����Ұ� ���ִ� ���� ù�� ������ ��ġ��
}quick;

void mergeSort(int * A, int l, int r);
/*
function name : mergeSort
pre condition(���� ����) : �Լ��� ȣ���ϸ鼭 ����Ʈ�� ó��, �� �ε������� ����Ʈ�� ���޹޴´�
function(���) : �պ� ������ �����Ѵ�
*/
void merge(int * A, int l, int m, int r);
/*
function name : merge
pre condition(���� ����) : �Լ��� ȣ���ϸ鼭 ����Ʈ�� ó��, �߰�, �� �ε������� ����Ʈ�� ���޹޴´�
function(���) : ���ĵ��ִ� ���� �����Ѵ�
*/
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
arrays createArrays();
/*
function name : createArrays
pre condition(���� ����) : none
function(���) : 6���� ����Ʈ�� �����ϰ�, ����
*/
void a_s_inPlaceQuickSort(int * L, int l, int r);
/*
function name : a_s_inPlaceQuickSort
pre condition(���� ����) : �Լ��� ȣ���ϸ鼭 ����Ʈ�� ó��, �� �ε������� ����Ʈ�� ���޹޴´�
function(���) : ����Ʈ�� ���� �����Ѵ�
*/
void a_i_s_inPlaceQuickSort(int * L, int l, int r);
/*
function name : a_i_s_inPlaceQuickSort
pre condition(���� ����) : �Լ��� ȣ���ϸ鼭 ����Ʈ�� ó��, �� �ε������� ����Ʈ�� ���޹޴´�
function(���) : ����Ʈ�� ���� �������Ѵ�
*/
quick inverse_inPlacePartition(int *A, int l, int r, int k);
/*
function name : inverse_inPlaceParition
pre condition(���� ����) : �Լ��� ȣ���ϸ鼭 ����Ʈ�� ó��, �� �ε������� ����Ʈ�� ������ �� ���� ��ġ�� ���޹޴´�
function(���) : ���ذ��� �������� ��Ƽ�� �۾� ���� -> ������
*/

int main()
{
	arrays L; // ����Ʈ 6���� �޴� ����ü arrays ����
	LARGE_INTEGER Start, End, Freq; // ����ð��� ��� ������. 
	double runtime; // ����ð��� �����ϴ� ����

	L = createArrays(); // ����Ʈ 6���� ����� ����ü�� �Ѱܹ޴´�

	QueryPerformanceFrequency(&Freq);
	QueryPerformanceCounter(&Start);  // ����ð� ���۽ð�
	inPlaceQuickSort(L.A, 0, N - 1); // {deterministic version} ���ڸ� ������ �� ���� ����
	QueryPerformanceCounter(&End); // ����ð� ����ð�
	runtime = (double)(End.QuadPart - Start.QuadPart) / (double)Freq.QuadPart; // ����ð� ���
	printf("������(����) CPU time = %0.10lf\n", runtime); // ����ð� ���

	QueryPerformanceFrequency(&Freq);
	QueryPerformanceCounter(&Start);  // ����ð� ���۽ð�
	mergeSort(L.A1, 0, N - 1);// �պ����� ����
	QueryPerformanceCounter(&End); // ����ð� ����ð�
	runtime = (double)(End.QuadPart - Start.QuadPart) / (double)Freq.QuadPart; // ����ð� ���
	printf("�պ�����(����) CPU time = %0.10lf\n", runtime); // ����ð� ���
	printf("\n");
	// ���� ����Ʈ
	QueryPerformanceFrequency(&Freq);
	QueryPerformanceCounter(&Start);  // ����ð� ���۽ð�
	inPlaceQuickSort(L.B, 0, N - 1); // {deterministic version} ���ڸ� ������ �� ���� ����
	QueryPerformanceCounter(&End); // ����ð� ����ð�
	runtime = (double)(End.QuadPart - Start.QuadPart) / (double)Freq.QuadPart; // ����ð� ���
	printf("������(���� ���ĵ�) CPU time = %0.10lf\n", runtime); // ����ð� ���

	QueryPerformanceFrequency(&Freq);
	QueryPerformanceCounter(&Start);  // ����ð� ���۽ð�
	mergeSort(L.B1, 0, N - 1);// �պ����� ����
	QueryPerformanceCounter(&End); // ����ð� ����ð�
	runtime = (double)(End.QuadPart - Start.QuadPart) / (double)Freq.QuadPart; // ����ð� ���
	printf("�պ�����(���� ���ĵ�) CPU time = %0.10lf\n", runtime); // ����ð� ���
	printf("\n");
	// ���� ���ĵ� ����Ʈ
	QueryPerformanceFrequency(&Freq);
	QueryPerformanceCounter(&Start);  // ����ð� ���۽ð�
	inPlaceQuickSort(L.C, 0, N - 1);// {deterministic version} ���ڸ� ������ �� ���� ����
	QueryPerformanceCounter(&End); // ����ð� ����ð�
	runtime = (double)(End.QuadPart - Start.QuadPart) / (double)Freq.QuadPart; // ����ð� ���
	printf("������(���� �����ĵ�) CPU time = %0.10lf\n", runtime); // ����ð� ���

	QueryPerformanceFrequency(&Freq);
	QueryPerformanceCounter(&Start);  // ����ð� ���۽ð�
	mergeSort(L.C1, 0, N - 1); // �պ����� ����
	QueryPerformanceCounter(&End); // ����ð� ����ð�
	runtime = (double)(End.QuadPart - Start.QuadPart) / (double)Freq.QuadPart; // ����ð� ���
	printf("�պ�����(���� �����ĵ�) CPU time = %0.10lf\n", runtime); // ����ð� ���
														   // ���� �����ĵ� ����Ʈ

	return 0;
}

void mergeSort(int * A, int l, int r) {
	int m;

	if (l < r) {
		m = (l + r) / 2; // ����Ʈ ������ ����

		mergeSort(A, l, m);      //���� ��� ����
		mergeSort(A, m + 1, r);  //������ ��� ����
		merge(A, l, m, r);   //���ҵ� ��� ����
	}
}
void merge(int * A, int l, int m, int r) {
	int i, j, k;
	int B[N]; // Nũ���� �迭 ����

	i = l;
	j = m + 1;
	k = l;    //��� �迭�� �ε���

			  //i���� m ������ ��ϰ� j���� r������ ����� ���� ���ϴ� �κ�
	while (i <= m && j <= r) {
		if (A[i] <= A[j])  //i ���� j ������ �۰ų� ������ i ���� ��� ����
			B[k++] = A[i++];
		else      //�ƴ϶�� j ����  ����
			B[k++] = A[j++];
	}

	while (i <= m)
		B[k++] = A[i++];

	while (j <= r)
		B[k++] = A[j++];

	for (k = l; k <= r; k++)
		A[k] = B[k]; // �����ߴ� �� ������
}
void inPlaceQuickSort(int * L, int l, int r) {
	int k;
	quick q;

	if (l >= r)
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
		while (i <= j && A[i] <= p) { // i�� l�� ���������� p���� �۰ų� �������� ã��
			if (A[i] == p) { // �������� ã�� ���, �ش������ �迭 ���ʿ� ��Ƶ�
				arraySwap(A, a, i); // ���� i�� ���� a�� ���� �ٲ۴�
				a++; // a�� ���� �ε��������� �̵��Ѵ�
			}
			i++;
		}

		while (i <= j && A[j] >= p) { // j�� r-1�� ���������� p���� ũ�ų� �������� ã��
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

	// �ش� �������� �迭�� ���ʰ� �����ʿ� ��Ƶ� p�� �ߺ��Ǵ� ���� �迭 �߾����� ������
	temp_loc = i - 1; // a���� i-1�� ��ġ�� �����ϱ� ���� �ӽ÷� ����
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
arrays createArrays() {
	arrays L;
	int i;

	L.A = (int*)malloc(sizeof(int) * N);
	L.B = (int*)malloc(sizeof(int) * N);
	L.C = (int*)malloc(sizeof(int) * N);
	L.A1 = (int*)malloc(sizeof(int) * N);
	L.B1 = (int*)malloc(sizeof(int) * N);
	L.C1 = (int*)malloc(sizeof(int) * N);
	// N�� ũ�⸦ ���� ����Ʈ�� 6�� �����Ѵ�

	srand((unsigned)time(NULL));

	for (i = 0; i<N; i++) {
		L.A[i] = rand() % N + 1;
	} // 1~N������ ������ �̷���� L.A ����Ʈ

	for (i = 0; i<N; i++) {
		L.B[i] = L.A[i];
		L.C[i] = L.A[i];
	} // copyArray ����, B�� C�� A�� ������ ����Ʈ�� ����

	a_s_inPlaceQuickSort(L.B, 0, N - 1);
	a_i_s_inPlaceQuickSort(L.C, 0, N - 1);

	for (i = 0; i<N; i++) {
		L.A1[i] = L.A[i]; // A1�� A�� ������ ����Ʈ�� ����
		L.B1[i] = L.B[i]; // B1�� B�� ������ ����Ʈ�� ����
		L.C1[i] = L.C[i]; // C1�� C�� ������ ����Ʈ�� ����
	} // copyArray ����

	return L;
}
void a_s_inPlaceQuickSort(int * A, int l, int r) {
	quick q;

	if ((r - l) > Limit) { // �������� ��� ������ ���������� ����
		q = inPlacePartition(A, l, r, 0);
		a_s_inPlaceQuickSort(A, l, q.a - 1);
		a_s_inPlaceQuickSort(A, q.b + 1, r);
	}
	// ���� ���ĵ� ����Ʈ�� �ȴ�
}
void a_i_s_inPlaceQuickSort(int * A, int l, int r) {
	quick q;

	if ((r - l) > Limit) { // ������(��)�� ��� ������ ���������� ����
		q = inverse_inPlacePartition(A, l, r, 0);
		a_i_s_inPlaceQuickSort(A, l, q.a - 1);
		a_i_s_inPlaceQuickSort(A, q.b + 1, r);
	}
	// ���� �����ĵ� ����Ʈ�� �ȴ�
}
quick inverse_inPlacePartition(int *A, int l, int r, int k) {
	quick q;
	int i, j;
	int a, b;
	int temp_loc;
	int p;

	p = A[k];

	i = l;
	j = r - 1;

	a = l;
	b = r;
	// �ּ� �޸� �κ� �����ϰ� inPlacePartition�� ����
	while (i <= j) {
		while (i <= j && A[i] >= p) {   // �������� ���� inPlacePartition���� �ٸ��� i�� l�� ���������� p���� ũ�ų� �������� ã��
			if (A[i] == p) {
				arraySwap(A, a, i);
				a++;
			}
			i++;
		}
		while (i <= j && A[j] <= p) {   // �������� ���� inPlacePartition���� �ٸ��� j�� r-1�� ���������� p���� �۰ų� �������� ã��
			if (A[j] == p) {
				b--;
				arraySwap(A, j, b);
			}
			j--;
		}
		if (i < j) {
			arraySwap(A, i, j);
		}
	}
	temp_loc = i - 1;
	while (a > i) {
		arraySwap(A, a, temp_loc);
		a--;
		temp_loc--;
	}
	a = temp_loc + 1;

	temp_loc = i;
	while (b < r + 1) {
		arraySwap(A, b, temp_loc);
		b++;
		temp_loc++;
	}
	b = temp_loc - 1;

	q.a = a;
	q.b = b;

	return q;
}

