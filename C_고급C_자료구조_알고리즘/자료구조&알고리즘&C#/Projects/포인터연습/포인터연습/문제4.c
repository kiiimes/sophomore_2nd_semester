#include <stdio.h>

void main() {
	char ch[11];
	char mst;
	int max = 0,cnt=1;
	char *p, *q;

	scanf("%s", ch);

	mst = *(ch+0);
	for (p = ch + 1; p < ch + 10; p++) {
		if (mst == *p) {
			cnt++;
		}
	}

	max = cnt;
	
	cnt = 1;
	for (p = ch+1; p < ch + 10; p++) {
		for (q = p + 1; q < ch + 10; q++) {
			if (*p == *q) {
				cnt++;
			}
		}
		if (max < cnt) {
			mst = *p;
			max = cnt;
		}	
		cnt = 1;
	}

	printf("%c %d", mst, max);
	




}