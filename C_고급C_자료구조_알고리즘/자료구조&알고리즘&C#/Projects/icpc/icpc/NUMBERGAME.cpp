//¿Ï

#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
int russia[101] = { 0 };
int korea[101] = { 0 };
int cnt = 0;

int calc() {
	for (int i = 0; i < n; i++) {
		if (russia[i] < korea[i]) return n - i;
		for (int j = 0; j < n; j++) {
			if (russia[i] < korea[j]) return n - j;
		}
	}
}

int main() {
	int c;

	for (int i = 0; i < c; i++) {
		scanf("%d",&n);
		for (int j = 0; j < n; j++) {
			scanf("%d", russia +);		
		}
		for (int j = 0; j < n; j++) {
			scanf("%d", korea + j);
		}

		sort(russia, russia + n);
		sort(korea, korea + n);

		printf("%d", calc());
	}
}