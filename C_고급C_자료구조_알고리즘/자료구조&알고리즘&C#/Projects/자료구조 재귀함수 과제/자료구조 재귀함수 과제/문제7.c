#include <stdio.h>
#include <string.h>

int confirm(char str[], char g,int i) {
	int sav;
	
	if (i == 0) {
		if (str[i] == g) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		i--;
		sav=confirm(str, g, i);
		
		if (str[i] == g) {
			
			if (i == 0) {
				return sav;
			}
			return 1 + sav;
		}
		else return sav;
		
	}
}

int main() {
 	char str[101] = { '\0' },g,i;

	scanf("%s", str);

	getchar();

	scanf("%c", &g);
	
	printf("%d",confirm( str,  g,strlen(str)));

}
