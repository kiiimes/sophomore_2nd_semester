#include <stdio.h>
#include <string.h>

int n;
int sav[3500];
char arr[10010]; // 100000글자면 정수범위 넘으니까 무조건 문자열로 받아야됨

int min(int a, int b, int c) {
	int m;
	if (a != 0) m = a;
	else if (b != 0) m = b;
	else if (c != 0) m = c;
	else return 0;

	if (m == a) {
		if (m > b&&b > 0) m = b;
		if (m > c&&c > 0) m = c;
	}
	else if (m == b) {
		if (m > a&&a > 0) m = a;
		if (m > c&&c > 0) m = c;
	}
	else if (m == c) {
		if (m > a&&a > 0) m = a;
		if (m > b&&b > 0) m = b;
	}
	return m;
}

int calc(int num,int lst,int in,int *s) {
	
	if (lst > n&&num<n) return 0;
	if (sav[num] != 0) return sav[num];  //
	if (num == n) {
		if (s[0] == (num -in-1)) return 1;  //이거는 확시치 않은거 num-1 이부분 바뀔수도
		if (s[1] == (num -in-1)) return 2;
		if (s[2] == (num -in-1)) return 4;
		if (s[3] == (num -in-1)) return 5;
		if (s[4] == (num -in-1)) return 10;
		return 0;
	}//여기 if문 이상

	int tmp = arr[num+1]-arr[num];
	int t=tmp;
	for (int i = 0; i < 5; i++) s[i] = 0;
	for (int i = num; i < (lst-1); i++) {
 		if (arr[i] == arr[i + 1]) s[0] += 1;
		if (arr[i + 1] - arr[i] == tmp) s[1] += 1;
		if (arr[i+1]-arr[i]==1||arr[i+1]-arr[i]==-1 ) {
			if ((arr[i + 1] - arr[i]) == 1 && (t == -1 || s[2] == 0)) {
				t = 1;
				s[2] += 1;
			}
			else if (arr[i + 1] - arr[i] == -1 && (t == 1 || s[2] == 0)) {
				t = -1;
				s[2] += 1;
			}
		}//이거도 좀 고민 해봐야될듯
		if (arr[i + 1] - arr[i] == tmp&&tmp!=1) s[3] += 1;
		s[4] += 1;
	}
	 
	return sav[num] += min(calc(lst, lst+3,3,s), calc(lst, lst+4,4,s), calc(lst, lst+5,5,s)); 
}
 
//3개로 나눌때 4개로 나눌때 5개로 나눌때로 경우를 나눔
//즉 


int main() {
	int c;
	int s[5] = { 0 };

	scanf("%d", &c);

	for (int i = 0; i < c; i++) {
		memset(arr, -1, sizeof(arr));
		memset(sav, 0, sizeof(sav));
		scanf("%s", arr);
		n = strlen(arr);
		int a = calc(0, 3, 3, s);
		sav[0] = 0;
		int b = calc(0, 4, 4, s);
		sav[0] = 0;
		int c = calc(0, 5, 5, s);

		printf("%d", min(a, b, c));
	}
}