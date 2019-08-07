#include <stdio.h>
#include <string.h>
typedef struct vec{
	int x,y,z;
}vec;
void main(){
	vec a,b;
	scanf("%d %d %d",&(a.x),&(a.y),&(a.z));
	scanf("%d %d %d",&(b.x),&(b.y),&(b.z));

	printf("%d %d %d",(a.x)+(b.x),(a.y)+(b.y),(a.z)+(b.z));

}