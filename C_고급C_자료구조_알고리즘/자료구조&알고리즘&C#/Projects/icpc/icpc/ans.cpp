#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
int russia[101] = { 0 };
int korea[101] = { 0 };
int cnt = 0;

int calc() {
	int s=0;
	for (int i = 0; i < n; i++) {
		for (int j = s; j < n; j++) {
			if (korea[j] >= russia[i]) {
				cnt++;
				s = j+1; 
				break;
			}
		}
	}
	return cnt;	
}


int main() {
	int c;
	
	scanf("%d", &c);

	for (int i = 0; i < c; i++) {
		scanf("%d", &n);
		for (int j = 0; j < n; j++) {
			scanf("%d", russia + j);
		}
		for (int j = 0; j < n; j++) {
			scanf("%d", korea + j);
		}

		sort(russia, russia + n);
		sort(korea, korea + n);

		printf("%d\n", calc());
		cnt = 0;;
	}
}