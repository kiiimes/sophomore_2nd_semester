#include <stdio.h>
#include <string.h>

int main() {
	int n,i,cnt=0,j,k;
	char str[20][101],min[101];

	scanf("%d", &n);//문자열 개수

	for (i = 0; i < n; i++) {
		scanf("%s", str[i]);
	}

	for (i = 0; i < n; i++) {
		cnt = 0;
		for (j = 0; j<strlen(str[i]); j++) {
			
			if (str[i][j] == '0') {
				cnt++;
				if (strlen(str[i]) == cnt) {
					str[i][0] = '0';
					str[i][1] = '\0';
					printf("%s", str[i]);
					return 0;
				}
			}
			else if (str[i][j] != '0') {
				if (cnt == 0) {
					break;
				}
				else {
					for (k = 0;k<(strlen(str[i])-cnt); k++) {
						
						
						str[i][k] = str[i][j+k];
						
					}
					str[i][k]='\0';
					break;
				}
			}
		}
	}
	
	strcpy(min, str[0]);
	for (i = 0; i < n; i++) {
		if (strlen(min) == strlen(str[i])) {
			if (strcmp(min, str[i]) > 0) {
				strcpy(min, str[i]);
			}
		}
		else if (strlen(min) > strlen(str[i])) {
			strcpy(min, str[i]);
		}
	}

	printf("%s", min);
	
}