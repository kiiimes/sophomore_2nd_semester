#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#define N 10000 //����Ʈ�� ũ��
#define Limit 8000//���� ���ĵ�

//����Ʈ�� ��� ����ü
typedef struct Arrays {
	int *A, *B, *C, *A1, *B1, *C1;
}Arrays;

//���� ������ ��ȯ ����ü
typedef struct quick {
	int a, b;
}quick;

//�ڸ� �ٲٴ� �Լ�
void swap(int *a, int *b) {
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

//�����ϴ� �Լ�
void merge(int* A, int l, int m, int r) {
	int i = l, k = l;
	int j = m + 1;
	int *B = (int*)malloc(sizeof(int)*N);//Nũ���� �迭 �����Ҵ�

	//�ΰ��� ����Ʈ���� ���ҵ� �� ���� ���Һ��� �ܺ� �迭�� ������ ��ġ�� �ݺ������� ����
	while (i <= m&&j <= r) {
		if (A[i] <= A[j]) {
			B[k++] = A[i++];
		}
		else {
			B[k++] = A[j++];
		}
	}
	// ����� �ݺ� �������� ó������ ���� ���ҵ��� �ܺ� �迭�� �ݺ������� ����
	while (i <= m) {
		B[k++] = A[i++];
	}

	while (j <= r) {
		B[k++] = A[j++];
	}
	//������ �迭�� �ܺι迭�� ���ҵ���	��������
	for (k = l; k <= r; k++) {
		A[k] = B[k];
	}
}

void rMergeSort(int* A, int l, int r) {
	int m;

	if (l < r) {
		//����Ʈ�� ������ �����Ѵ�.
		m = (l + r) / 2;
		//��͸� ���� ��� ���ʰ� �������� ��� ������ �����Ѵ�. 
		rMergeSort(A, l, m);
		rMergeSort(A, m + 1, r);
		//�����Ѵ�. 
		merge(A, l, m, r);
	}
}

//��ͷ� �ϴ� mergesort�� �θ��� �Լ�
void mergeSort(int* A) {
	rMergeSort(A, 0, N - 1);
}

//���ڸ� ���� �Լ�
quick inPlacePartition(int *A, int l, int r, int k) {
	int p, i, j;
	int a, b;
	int sav;
	quick q;

	p = A[k];//���ؿ��� pivot�� �����Ѵ�. 

	i = l;
	j = r - 1;


	//�ߺ��� ���Ҹ� ���ʰ� ���������� ���� ���� ���� 
	a = l;
	b = r;


	//i�� j�� ���� �ʴ� ���� ���� ����
	while (i <= j) {
		//���������� �۰ų� ���� ���� ã��
		while (i <= j&&A[i] <= p) {
			//������ swap
			if (A[i] == p) {
				swap(&(A[a]), &(A[i]));
				a++;
			}
			i = i + 1;
		}

		//���������� ũ�ų� ���� ���� ã��
		while (j >= i&&A[j] >= p) {
			//�������̶� ���� ���̸� �迭 �����ʿ� ��
			if (A[j] == p) { 
				b--;
				swap(A + j, A + b);
			}
			j = j - 1;
		}
		//i�� j���� ������ swap
		if (i < j) {
			swap(A + i, A + j);
		}
	}

	//���� ���� �ߺ� ���ҵ��� �迭 �߾����� ������.
	sav = i - 1;
	//a��i���� ū ���� �ߺ��� ���� �߾����� �ű��. 
	while (a > i) {
		swap(A + a, A + sav);
		a--;
		sav--;
	}
	a = sav + 1;

	sav = i;
	//b�� r+1���� ���� ���� �ߺ��� ���� �߾����� �ű��. 
	while (b < r + 1) {
		swap(A + b, A + sav);
		b++;
		sav++;
	}

	b = sav - 1;

	q.a = a;
	q.b = b;

	return q;
}

//���ڸ� ���� �Լ�
void inPlaceQuickSort(int *A, int l, int r) {
	quick q;
	int k;

	//���� ��谡 ������ ��躸�� ������ ����
	if (l >= r) {
		return;
	}

	k = r;//������ ���Ҹ� �������� ����

	//���ڸ� ���� �Լ� ȣ���Ͽ� ����� ��ȯ
	q = inPlacePartition(A, l, r, k);
	//��͸� ���� ��������
	inPlaceQuickSort(A, l, q.a - 1);
	inPlaceQuickSort(A, q.b + 1, r);

}

//���� �����ĵ� ����Ʈ ����� �Լ�
void almostInPlaceQuickSort(int *A, int l, int r) {
	quick q;

	//limit���� �������� ���� �����ĵ� ����Ʈ�� �����. 
	if ((r - l) > Limit) {
		q = inPlacePartition(A, l, r, 0);
		almostInPlaceQuickSort(A, l, q.a - 1);
		almostInPlaceQuickSort(A, q.b + 1, r);
	}
}

//���� ������ ���ڸ� ����
quick inverseInPlacePartition(int *A, int l, int r, int k) {
	int p, i, j;
	int a, b;
	int sav;
	quick q;

	p = A[k];//���ؿ��� pivot�� �����Ѵ�. 

	i = l;
	j = r - 1;

	a = l;
	b = r;

	//�������� ���� i�� j�� �Ѿ�� �ʴ� ���ȸ� swap�ϴ� ����
	while (i <= j) {
		while (i <= j&&A[i] >= p) {//���ؿ��Һ��� ũ�ų� ���� ���� ����
			if (A[i] == p) {//���ؿ��Ҷ� ������ swap
				swap(A + a, A + i);
				a++;
			}
			i = i + 1;
		}
		//���ؿ��Һ��� �۰ų� �������� ����
		while (j >= i&&A[j] <= p) {
			//���ؿ��Ҷ� ������ swap
			if (A[j] == p) {
				b--;
				swap(A + j, A + b);
			}
			j = j - 1;
		}
		//i�� j���� ������ swap
		if (i < j) {
			swap(A + i, A + j);
		}
	}


	//�Ʒ��� inplacesort�� ����. 
	//�ߺ��Ǵ� ������ �ڸ��� ã���ִ� �۾�
	sav=i-1;
	while (a > i) {
		swap(A + a, A + sav);
		a--;
		sav--;
	}
	a = sav + 1;

	sav = i;
	while (b < r + 1) {
		swap(A + b, A + sav);
		b++;
		sav++;
	}

	b = sav - 1;

	q.a = a;
	q.b = b;

	return q;
}

//���� ������ ����Ʈ�� ����� �Լ�
void inverseInPlaceQuickSort(int *A, int l, int r) {
	quick q;

	//limit�� �ξ� ������������� �������� �����.
	if ((r - l) > Limit) {
		q = inverseInPlacePartition(A, l, r, 0);
		inverseInPlaceQuickSort(A, l, q.a - 1);
		inverseInPlaceQuickSort(A, q.b + 1, r);
	}

}

//�迭�� ����Ʈ�� ����� �Լ�
Arrays createArrays() {
	Arrays arr;
	int i;

	//Nũ��� �����Ҵ�
	arr.A = (int*)malloc(sizeof(int)*N);
	arr.B = (int*)malloc(sizeof(int)*N);
	arr.C = (int*)malloc(sizeof(int)*N);
	arr.A1 = (int*)malloc(sizeof(int)*N);
	arr.B1 = (int*)malloc(sizeof(int)*N);
	arr.C1 = (int*)malloc(sizeof(int)*N);

	//A����Ʈ�� ������ �� ����
	srand((unsigned)time(NULL));

	for (i = 0; i < N; i++) {
		arr.A[i] = rand() % N + 1;
	}

	//B�� C���� A�� ������ �� ����
	for (i = 0; i < N; i++) {
		arr.B[i] = arr.A[i];
		arr.C[i] = arr.A[i];
	}

	//���� ���ĵ� ����Ʈ ����
	almostInPlaceQuickSort(arr.B, 0, N - 1);
	//���� �����ĵ� ����Ʈ ����
	inverseInPlaceQuickSort(arr.C, 0, N - 1);

	//A1, B1, C1�� ���� ����
	for (i = 0; i < N; i++) {
		arr.A1[i] = arr.A[i];
		arr.B1[i] = arr.B[i];
		arr.C1[i] = arr.C[i];
	}

	//����ü ��ȯ
	return arr;

}

void main() {
	Arrays arr;//�迭����ü ����
	LARGE_INTEGER Start, End, Freq;//����ð� ��� ����
	double run;//����ð��� ��� ����

	//�迭�� ����ü�� ����Ʈ�� ����
	arr = createArrays();

	//�������� ����Ʈ
	QueryPerformanceFrequency(&Freq);
	QueryPerformanceCounter(&Start);
	inPlaceQuickSort(arr.A, 0, N - 1);
	QueryPerformanceCounter(&End);
	run = (double)(End.QuadPart - Start.QuadPart) / (double)Freq.QuadPart;//���� �ð� ���
	printf("���ڸ�������(������)�� CPU time = %0.10lf\n", run);//����ð� ���


	QueryPerformanceFrequency(&Freq);
	QueryPerformanceCounter(&Start);
	mergeSort(arr.A1);
	QueryPerformanceCounter(&End);
	run = (double)(End.QuadPart - Start.QuadPart) / (double)Freq.QuadPart;//����ð� ���
	printf("�պ�����(������)�� CPI time = %0.10lf\n", run);//����ð� ���

	//���� ���ĵ� ����Ʈ
	QueryPerformanceFrequency(&Freq);
	QueryPerformanceCounter(&Start);
	inPlaceQuickSort(arr.B, 0, N - 1);
	QueryPerformanceCounter(&End);
	run = (double)(End.QuadPart - Start.QuadPart) / (double)Freq.QuadPart;//���� �ð� ���
	printf("���ڸ�������(��������)�� CPU time = %0.10lf\n", run);//����ð� ���

	
	QueryPerformanceFrequency(&Freq);
	QueryPerformanceCounter(&Start);
	mergeSort(arr.B1);
	QueryPerformanceCounter(&End);
	run = (double)(End.QuadPart - Start.QuadPart) / (double)Freq.QuadPart;//����ð� ���
	printf("�պ�����(��������)�� CPI time = %0.10lf\n", run);//����ð� ���

	//���� �����ĵ� ����Ʈ
	QueryPerformanceFrequency(&Freq);
	QueryPerformanceCounter(&Start);
	inPlaceQuickSort(arr.C, 0, N - 1);
	QueryPerformanceCounter(&End);
	run = (double)(End.QuadPart - Start.QuadPart) / (double)Freq.QuadPart;//���� �ð� ���
	printf("���ڸ�������(���� ������)�� CPU time = %0.10lf\n", run);//����ð� ���


	QueryPerformanceFrequency(&Freq);
	QueryPerformanceCounter(&Start);
	mergeSort(arr.C1);
	QueryPerformanceCounter(&End);
	run = (double)(End.QuadPart - Start.QuadPart) / (double)Freq.QuadPart;//����ð� ���
	printf("�պ�����(���� ������)�� CPI time = %0.10lf\n", run);//����ð� ���

}