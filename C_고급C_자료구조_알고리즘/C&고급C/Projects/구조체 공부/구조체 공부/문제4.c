#include <stdio.h>
#include <string.h>
typedef struct fraction{
	int j1,m1,j2,m2;
	}fraction;
void main(){
	fraction f;
	scanf("%d %d %d %d",&(f.j1),&(f.m1),&(f.j2),&(f.m2));
	printf("%d/%d",(f.j1)*(f.j2),(f.m1)*(f.m2));
}