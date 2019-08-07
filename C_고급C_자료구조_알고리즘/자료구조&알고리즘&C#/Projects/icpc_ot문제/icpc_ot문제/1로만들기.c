#include <stdio.h>

int cnt[1000001] = { 0 };
int sav=0;
int flag=0;

void cal(int num) {
	//�迭�� ��ȣ�� �Űܼ� �� ��ȣ�� �ش��ϴ� ������ 1���� ���� �ּ� ����� ���� �����س��´� 
	//10�̸� -1 �ؼ� �ϴ� ���� 2�� �ٷ� ������ ��� �� �ش� �ε����� �迭�� ���� �� ���� �Ÿ� sav�� ����
	
	if (num == 1) return;
	
	if (cnt[num] != 0) {
		sav = cnt[num];
		return;
	}
	//�����Ÿ� ����
	else if (num % 3 == 0 && num % 2 == 0) {
		if (cnt[num / 3] < cnt[num / 2]) num /= 3;
		else num /= 2;
	}
	else if (num % 3 == 0) {
		if (cnt[num - 1] < cnt[num / 3]) num -= 1;
		else num /= 3;
	}
	else if (num % 2 == 0) {
		if ((cnt[num - 1]) < cnt[num / 2]) num -= 1;
		else num /= 2;
	}
	else {
		num -= 1;
	}
	cal(num);
	sav++;

}

int main() {
	int num,i;

	scanf("%d", &num);

	for (i = 1; i <= num; i++) {
		sav = 0;
		flag = 0;
		cal(i);
		cnt[i] = sav;
		//printf("%d (%d) \n", cnt[i],i);
	}

	printf("%d", cnt[num]);

	return 0;
}