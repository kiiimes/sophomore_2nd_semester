#include <stdio.h>

typedef struct rank {
	int inp[10];// �� �Է�
	int rsav[10];//��ŷ ����
}rank;

void main() {
	rank r;
	int i,cnt=0,j;

	for (i = 0; i < 10; i++) {
		scanf("%d", &r.inp[i]);
	}
	
	for (i = 0; i < 10; i++) {
		cnt = 1;
		for (j = 0; j < 10; j++) {
			if (r.inp[i] < r.inp[j]) 
				cnt++;
		}
		r.rsav[i] = cnt;

		if (r.rsav[i] == 3 || r.rsav[i] == 7)
			printf("%d ", r.inp[i]);

	}

}