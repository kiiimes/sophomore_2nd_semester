#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char **p;
	char *a;
	p = (char **)malloc(2*sizeof(char*));

	p[0] = (char *)malloc(4*sizeof(char));
	p[1] = (char *)malloc(6*sizeof(char));

	strcpy(p[0],"cat");
	strcpy(p[1],"happy");

	a = p[0];
	p[0] = p[1];
	p[1] = a;

	printf("%s %s\n",p[0],p[1]);

	return 0;
}