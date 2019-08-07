#include <stdio.h>
void InputName(char *pName) {  printf("InputName 1: pName = %p, %s\n", pName, pName); pName = "Cabin"; printf("InputName 2: pName = %p, %s\n", pName, pName); }
int main( ) {  char *Name = NULL;
InputName(Name); printf("main: Name = %p\n", Name); printf("Name : %s\n", Name);
}
