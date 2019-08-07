#include <stdio.h>

int sum(int n){
int s=1; // ÇÕ ÀúÀå
if( n == 1) s = 1;
else s = s*sum(n-1) ;
return s;

}
void main()
{
	int a;
	scanf("%d",&a);
printf("%d", sum(a) );
}