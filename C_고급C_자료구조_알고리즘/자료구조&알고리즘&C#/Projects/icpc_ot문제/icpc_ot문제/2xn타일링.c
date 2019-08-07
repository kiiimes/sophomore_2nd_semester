#include <stdio.h>

int cnt=0;
int sav;
int s[3];
int k = 0;

int calcTile(int n,int num,int countTwo,int countOne,int c) {
	int flag = 0;
	if (s[1] == 2 && (s[0] == 2 || s[2] == 2))flag = 1;
	if (n == 0) {
		if ((countTwo % 2 == 0 && countTwo <= ((sav / 2) * 2) && countTwo != 0) || countOne == sav) {
			if(flag==1||countOne==sav) cnt++;
		}
		return;
	}
	else {
		for (k = 2; k >= c; k--) {
			s[k] = 0;
		}
		num = 1;
		if (s[0] == 0) s[0] = num;
		else if (s[1] == 0) s[1] = num;
		else if (s[2] == 0) s[2] = num;
		else {
			s[0] = s[1];
			s[1] = s[2];
			s[2] = num;
		}
		calcTile(n - 1, num,(num== 2 ?countTwo+1:countTwo),(num==1?countOne+1:countOne),c+1);
		for (k = 2; k >= c; k--) {
			s[k] = 0;
		}
		num = 2;
		if (s[0] == 0) s[0] = num;
		else if (s[1] == 0) s[1] = num;
		else if (s[2] == 0) s[2] = num;
		else {
			s[0] = s[1];
			s[1] = s[2];
			s[2] = num;
		}
		calcTile(n - 1, num, (num == 2 ? countTwo + 1 : countTwo), (num == 1 ? countOne + 1 : countOne),c+1);
	}
}

int main() {
	int n,i;
	int sav1, sav2;

	scanf("%d", &n);
	
	sav = n;
	if (n > 1) {
		calcTile(n, 1, 0, 0,0);
		sav1 = cnt;
		printf("%d", sav1);
	}
	else printf("1");
	

	return 0;
}
//1 1
//2 2
//3 3
//4 5
//5 8
//6 13
//7 21
//8 34
//9 55
