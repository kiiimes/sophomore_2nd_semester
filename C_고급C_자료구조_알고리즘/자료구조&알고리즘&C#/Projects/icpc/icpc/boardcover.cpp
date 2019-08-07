#include <stdio.h>
#include <string.h>

int h, w;
int cnt = 0;

int calc(int type, int starth,int startw,int **arr) {
	if (type == 1) {
		arr[starth][startw] = '#';

	}//¤¡
	else if (type == 2) {

	}//r
	else if (type == 3) {

	}//¤¤
	else if (type == 4) {

	}//¤Ã
}

int main() {
	int c;
	int arr[22][22] = { '\0' };

	scanf("%d", &c);

	for (int i = 0; i < c; i++) {
		scanf("%d %d", &h, &w);

		for (int j = 0; j < h; j++) {
			getchar();
			scanf("%s", arr + h);
		}


	}

}