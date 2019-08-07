#include <stdio.h>

int n;
int cnt=0;
int sav[101] = { 0 };

int calc(int num,int sum,int cnt) {
	
	if (sum == 0) return sav[n - 1] = 1;
	if (sav[cnt] != 0) sum -= sav[cnt];
	return calc(1, sum-1)+calc(2, sum - 2);

}

int main() {
	int c;

	scanf("%d", &c);

	for (int i = 0; i < c; i++) {
		
		scanf("%d", &n); 

		printf("%d", (calc(0, 0)%1000000007));

	}
}