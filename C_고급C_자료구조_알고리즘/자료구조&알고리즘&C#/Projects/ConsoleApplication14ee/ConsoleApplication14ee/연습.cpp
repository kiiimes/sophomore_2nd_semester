#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {

	int eunsuk;
}Student;

int main() {

	char str[10];
	char* tmp;
	char* tmpp;
	int flag;
	int sav=1,savv=1;
	int sum = 0;

	scanf("%s",str);

	flag = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/') {
			if (str[i]=='+') {
				tmp = strtok(str,"+");
				tmpp = strtok(NULL," ");
		
				sav = atoi(tmp);
				savv = atoi(tmpp);
				
				printf("%d",sav);
				printf("%d",savv);

				sum = sav + savv;
			}

		}
	}

	printf("%d", sum);

}
