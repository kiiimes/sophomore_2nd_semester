#include <stdio.h>

int reverse(int num) {

	if (num / 10 == 0) {
		printf("%d\n", num);
		return ;
	}
	else {
		printf("%d\n", num % 10);
		reverse(num / 10);
	}

}

void main() {
	int num;

	scanf("%d", &num);

	reverse(num);


}