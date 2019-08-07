#include <stdio.h>
#define SIZE 3
void Func();
int main()
{
int i;
for (i=0; i<SIZE; i++)
Func();
return 0;
}
void Func()
{
static int cnt1 = 0;
int cnt2 = 0;
cnt1++;
cnt2++;
printf("static:%d local:%d \n", cnt1, cnt2);
}