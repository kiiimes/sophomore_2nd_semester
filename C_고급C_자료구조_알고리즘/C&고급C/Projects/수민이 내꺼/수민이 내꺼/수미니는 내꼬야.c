#include <stdio.h> 
int main(void) 
{
	int i;
	char ar[9]={'d','u','c','k',' ','p','o','n','d'};

	for(i=0;i<9;i++) printf("%c ",ar[i]);
	printf("\n");
	for(i=0;i<4;i++) printf("%c ",ar[i]);
	printf("\n");
	for(i=0;i<9;i++) printf("%c ",ar[i]);
	printf("\n");


	return 0;
}

