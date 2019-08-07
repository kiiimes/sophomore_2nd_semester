#include <stdio.h>

int high(int num) {
	
	if (num / 10 == 0) {
		printf("%d\n", num);
		return num;
	}
	else{ high(num / 10);
	printf("%d\n", num % 10);
	}
	

}

void main() {
	int num;

	scanf("%d",&num);

	high(num);




}