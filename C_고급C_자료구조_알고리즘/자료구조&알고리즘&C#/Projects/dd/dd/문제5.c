#include <stdio.h>

void main() {
	int n, x[110], infnum, info[500],tmp,i,j,k,sav[500];

	scanf("%d", &n);//���� ����
	for (i = 0; i < n; i++) {
		scanf("%d", x + i);//���� �Է�
	}
	scanf("%d", &infnum);//��ġ ��ȯ ���� �Է�
	for (i = 0; i < infnum; i++) {
		scanf("%d", info+i);//��ġ ��ȯ ���� �Է�
	}

	for(i = 0; i < infnum; i++) {		
		sav[i] = x[info[i]];
	}

	for (i = 0; i < infnum; i++) {
		if (i == infnum - 1) {
			break;
		}
		
		x[info[i + 1]] = sav[i];
	}

	for (i = 0; i < n; i++) {
		printf(" %d", x[i]);
	}

}