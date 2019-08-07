#include <stdio.h>

int cnt[1000001] = { 0 };
int sav=0;
int flag=0;

void cal(int num) {
	//배열에 번호를 매겨서 그 번호에 해당하는 수에서 1까지 가는 최소 방법의 수를 저장해놓는다 
	//10이면 -1 해서 하는 경우랑 2로 바로 나누는 경우 그 해당 인덱스의 배열의 값이 더 작은 거를 sav에 더함
	
	if (num == 1) return;
	
	if (cnt[num] != 0) {
		sav = cnt[num];
		return;
	}
	//작은거를 가짐
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