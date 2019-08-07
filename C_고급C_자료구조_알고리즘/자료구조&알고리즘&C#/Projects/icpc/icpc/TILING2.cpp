//완
#include <stdio.h>
#include <string.h>

int n;
int sav[101] = { 0 };

int calc(int num) {

	if (num < 0) return 0;
	if (num == 0) return 1;// return값 생각

	if (sav[num] != 0) {
		return sav[num];
	}
	return sav[num] = (calc(num - 1) + calc(num - 2))% 1000000007;


	//앞 반의합 뒤 반의 합 같으면 
	
	//11111
	//11112
	//1112
	//112
	//한칸 남았을때 들어갈 수 있는 방법의 수 
	//두칸 남았을때 들어갈 수 있는 방법의수를
	//더한 것이 return 값에 해당된다.
}

//앞의 반 뒤의 반 합 같으면 

int main() {
	int c;
	  
	scanf("%d", &c);

	for (int i = 0; i < c; i++) {

		scanf("%d", &n);
		 long long s=calc(n);

		sav[0] = 1;
		if (n % 2 == 0) s = s - sav[n / 2] - sav[n / 2 - 1];
		else s = s - sav[n / 2];

		printf("%lld\n", (s + 1000000007 + 1000000007) % 1000000007);

		memset(sav, 0, sizeof(sav));
	}
}