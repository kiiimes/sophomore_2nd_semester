#include <stdio.h>

void hanoi(int n, char from, char tmp, char to) {
	if (n == 1)printf("%c %c\n", from, to);
	else {
		hanoi(n - 1, from, to, tmp);
		/*
		tmp==c로 생각하고 b로 옮김 

		*/
		printf("%c %c\n", from, to);
		hanoi(n - 1, tmp, from, to);
	}
}

void main() {
	int n;

	scanf("%d", &n);//원판 개수 입력

	hanoi(n, 'A', 'B', 'C');// 개수, a,b,c




}