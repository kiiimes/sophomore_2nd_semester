#include <stdio.h>



void swap(int *p1, int *p2){
int *ptmp = p1;
p1 = p2;
p2 = ptmp;
}
void main() {
int x = 10, y = 20;
int *p1 = &x, *p2 = &y;
swap( p1, p2); // p1 <‐> p2 교환
printf("%d %d", *p1, *p2);
}