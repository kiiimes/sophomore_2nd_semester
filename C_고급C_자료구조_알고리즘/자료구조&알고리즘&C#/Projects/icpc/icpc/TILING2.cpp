//��
#include <stdio.h>
#include <string.h>

int n;
int sav[101] = { 0 };

int calc(int num) {

	if (num < 0) return 0;
	if (num == 0) return 1;// return�� ����

	if (sav[num] != 0) {
		return sav[num];
	}
	return sav[num] = (calc(num - 1) + calc(num - 2))% 1000000007;


	//�� ������ �� ���� �� ������ 
	
	//11111
	//11112
	//1112
	//112
	//��ĭ �������� �� �� �ִ� ����� �� 
	//��ĭ �������� �� �� �ִ� ����Ǽ���
	//���� ���� return ���� �ش�ȴ�.
}

//���� �� ���� �� �� ������ 

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