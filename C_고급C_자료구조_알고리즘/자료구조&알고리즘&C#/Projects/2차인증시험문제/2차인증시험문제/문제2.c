#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
	char sav[31],**p;
	int n=1,i,j,k,sum=0,cnt1=0,cnt2=0,cnt3=0;

	p = (char**)malloc(n * sizeof(char*));

	for (i = 0;; i++) {
		gets(sav);
		if (strlen(sav) == 1) {
			for (j = 0; j < n-1; j++) {
				cnt1 = 0, cnt2 = 0, cnt3 = 0,sum=0;
				for (k = 0; k < strlen(p[j]); k++) {
					if (p[j][k] >= '0'&&p[j][k] <= '9') {
						sum = sum + p[j][k] - '0' + 0;
					}
					else if (p[j][k] >= 'A'&&p[j][k] <= 'Z') {
						cnt1++;
					}
					else if (p[j][k] >= 'a'&&p[j][k] <= 'z') {
						cnt2 ++;
					}
					else {
						cnt3++;
					}
				}
				printf("%d %d %d %d\n", sum, cnt1, cnt2, cnt3);
			}
			break;
		}
		else {
			p[i] = (char*)malloc((strlen(sav) + 1)*sizeof(char));
			strcpy(p[i], sav);
			n += 1;
			p = (char**)realloc(p, n*sizeof(char*));
		}
	}

}