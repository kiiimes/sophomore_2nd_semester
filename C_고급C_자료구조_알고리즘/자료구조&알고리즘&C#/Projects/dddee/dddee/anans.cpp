#include <stdio.h>

int n;
int sav[101] = { 0 };

int calc(int num,int s) {

	if (num<0||num>9) return 0;
	
	if (n-1 <= s) return 1;
	
	if(sav[num]!=0){
		return sav[num];
	}

	return calc(num + 1,s+1) + calc(num - 1,s+1);
}

int main() {
	
	int sum = 0;

	scanf("%d", &n);

	for (int i = 1; i < 10; i++) {
		sum+=calc(i, 0); //1인 경우 생각
		sav[i] = sum;
	}
	printf("%d", sum%1000000000);

}

//이거 