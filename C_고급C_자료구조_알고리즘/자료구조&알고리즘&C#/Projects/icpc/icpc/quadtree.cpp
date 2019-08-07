#include <stdio.h>
#include <string.h>

char arr[1002] = { '\0' };
int cnt = 0;

int calc(int ind) {
	int i=0;
	if (arr[ind] == 'x') {
		cnt++;
	}
	for (i = 0; i < 4; i++) {
		if (arr[ind + i] == 'x') break;
	}
	if (i == 4) {
		cnt--;
	}

}

int main() {
	int c;

	scanf("%d", &c);

	for (int i = 0; i < c; i++) {
		scanf("%s", arr);
	}
}