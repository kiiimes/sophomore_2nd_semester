#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#define N 30 //리스트의 크기
#define Limit 10//거의 정렬된

typedef struct Arrays {
}Arrays;

typedef struct quick {
	int *A, *B, *C, *A1, *B1, *C1;
	int a, b;
}quick;

void swap(int *a, int *b) {
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;

}

int* merge(int* A, int l, int m, int r) {
	int i = l, k = l;
	int j = m + 1;
	int *B = (int*)malloc(sizeof(int)*N);

	while (i <= m&&j <= r) {
		if (A[i] <= A[j]) {
			B[k++] = A[i++];
		}
		else {
			B[k++] = A[j++];
		}
	}
	while (i <= m) {
		B[k++] = A[i++];
	}

	while (j <= r) {
		B[k++] = A[j++];
	}

	for (k = l; k <= r; k++) {
		A[k] = B[k];
	}//그냥 리턴해주려고 하는거 같음
	return A;
}

int* rMergeSort(int* A, int l, int r) {
	int m;

	if (l < r) {
		m = (l + r) / 2;
		rMergeSort(A, l, m);
		rMergeSort(A, m + 1, r);
		merge(A, l, m, r);
	}
	return A;
}

int* mergeSort(int* A) {
	rMergeSort(A, 0, N - 1);
	return A;
}

quick inPlacePartition(int *A, int l, int r, int k) {
	int p, i, j, tmp;
	int a, b;
	int sav;
	quick q;

	p = A[k];//기준원소 pivot을 저장한다. 

	i = l;
	j = r - 1;

	a = l;
	b = r;


	while (i <= j) {
		while (i <= j&&A[i] <= p) {
			if (A[i] == p) {
				swap(A + a, A + i);
				a++;
			}
			i = i + 1;
		}
		while (j <= i&&A[j] >= p) {
			if (A[j] == p) {
				b--;
				swap(A + i, A + b);
			}
			j = j - 1;
		}
		if (i < j) {
			swap(A + i, A + j);
		}
	}

	a = i - 1;
	while (a > i) {
		swap(A + a, A + sav);
		a--;
		sav--;
	}
	a = sav + 1;

	sav = i;
	while (b < r + l) {
		swap(A + b, A + sav);
		b++;
		sav++;
	}

	b = sav - 1;

	q.a = a;
	q.b = b;

	return q;
}

void inPlaceQuickSort(int *A, int l, int r) {
	quick q;
	int k;

	if (l >= r) {
		return;
	}

	k = r;//마지막 원소를 기준으로 잡음

	q = inPlacePartition(A, l, r, k);
	inPlaceQuickSort(A, l, q.a - 1);
	inPlaceQuickSort(A, q.b + 1, r);

}

//거의 정렬된 리스트 만드는 함수
void almostInPlaceQuickSort(int *A, int l, int r) {
	quick q;

	if ((r - l) > Limit) {
		q = inPlacePartition(A, l, r, 0);
		almostInPlaceQuickSort(A, l, q.a - 1);
		almostInPlaceQuickSort(A, q.b + 1, r);
	}
}

quick inverseInPlacePartition(int *A, int l, int r, int k) {
	int p, i, j, tmp;
	int a, b;
	int sav;
	quick q;

	p = A[k];//기준원소 pivot을 저장한다. 

	i = l;
	j = r - 1;

	a = l;
	b = r;


	while (i <= j) {
		while (i <= j&&A[i] >= p) {
			if (A[i] == p) {
				swap(A + a, A + i);
				a++;
			}
			i = i + 1;
		}
		while (j >= i&&A[j] <= p) {
			if (A[j] == p) {
				b--;
				swap(A + i, A + b);
			}
			j = j - 1;
		}
		if (i < j) {
			swap(A + i, A + j);
		}
	}

	a = i - 1;
	while (a > i) {
		swap(A + a, A + sav);
		a--;
		sav--;
	}
	a = sav + 1;

	sav = i;
	while (b < r + l) {
		swap(A + b, A + sav);
		b++;
		sav++;
	}

	b = sav - 1;

	q.a = a;
	q.b = b;

	return q;
}

void inverseInPlaceQuickSort(int *A, int l, int r) {
	quick q;

	if ((r - l) > Limit) {
		q = inverseInPlacePartition(A, l, r, 0);
		inverseInPlaceQuickSort(A, l, q.a - 1);
		inverseInPlaceQuickSort(A, q.b + 1, r);
	}
}

Arrays createArrays() {
	Arrays arr;
	int i;

	arr.A = (int*)malloc(sizeof(int)*10);
	arr.B = (int*)malloc(sizeof(int)*10);
	arr.C = (int*)malloc(sizeof(int)*10);
	arr.A1 = (int*)malloc(sizeof(int)*10);
	arr.B1 = (int*)malloc(sizeof(int)*10);
	arr.C1 = (int*)malloc(sizeof(int)*10);

	srand((unsigned)time(NULL));

	for (i = 0; i < 10; i++) {
		arr.A[i] = rand() % 10 + 1;
	}

	for (i = 0; i < 10; i++) {
		arr.B[i] = arr.A[i];
		arr.C[i] = arr.A[i];
	}

	almostInPlaceQuickSort(arr.B, 0, 10 - 1);
	inverseInPlaceQuickSort(arr.C, 0, 10 - 1);

	for (i = 0; i < 10; i++) {
		arr.A1[i] = arr.A[i];
		arr.B1[i] = arr.B[i];
		arr.C1[i] = arr.C[i];
	}

	return arr;

}



void main() {
	Arrays arr;
	LARGE_INTEGER Start, End, Freq;//실행시간 재는 변수
	double run;//실행시간을 재는 변수

	arr = createArrays();

	//무작위한 리스트
	QueryPerformanceFrequency(&Freq);
	QueryPerformanceCounter(&Start);
	inPlaceQuickSort(arr.A, 0, N - 1);
	QueryPerformanceCounter(&End);
	run = (double)(End.QuadPart - Start.QuadPart) / (double)Freq.QuadPart;//실행 시간 계산
	printf("제자리퀵정렬(무작위)의 CPU time = %0.10lf\n", run);//실행시간 출력


	QueryPerformanceFrequency(&Freq);
	QueryPerformanceCounter(&Start);
	mergeSort(arr.A1);
	QueryPerformanceCounter(&End);
	run = (double)(End.QuadPart - Start.QuadPart) / (double)Freq.QuadPart;
	printf("합병정렬(무작위)의 CPI time = %0.10lf\n", run);//실행시간 출력

												   //거의 정렬된 리스트
	QueryPerformanceFrequency(&Freq);
	QueryPerformanceCounter(&Start);
	inPlaceQuickSort(arr.B, 0, N - 1);
	QueryPerformanceCounter(&End);
	run = (double)(End.QuadPart - Start.QuadPart) / (double)Freq.QuadPart;//실행 시간 계산
	printf("제자리퀵정렬(거의정렬)의 CPU time = %0.10lf\n", run);//실행시간 출력


	QueryPerformanceFrequency(&Freq);
	QueryPerformanceCounter(&Start);
	mergeSort(arr.B1);
	QueryPerformanceCounter(&End);
	run = (double)(End.QuadPart - Start.QuadPart) / (double)Freq.QuadPart;
	printf("합병정렬(거의정렬)의 CPI time = %0.10lf\n", run);//실행시간 출력

													//거의 역정렬된 리스트
	QueryPerformanceFrequency(&Freq);
	QueryPerformanceCounter(&Start);
	inPlaceQuickSort(arr.C, 0, N - 1);
	QueryPerformanceCounter(&End);
	run = (double)(End.QuadPart - Start.QuadPart) / (double)Freq.QuadPart;//실행 시간 계산
	printf("제자리퀵정렬(거의 역정렬)의 CPU time = %0.10lf\n", run);//실행시간 출력


	QueryPerformanceFrequency(&Freq);
	QueryPerformanceCounter(&Start);
	mergeSort(arr.C1);
	QueryPerformanceCounter(&End);
	run = (double)(End.QuadPart - Start.QuadPart) / (double)Freq.QuadPart;
	printf("합병정렬(거의 역정렬)의 CPI time = %0.10lf\n", run);//실행시간 출력


}