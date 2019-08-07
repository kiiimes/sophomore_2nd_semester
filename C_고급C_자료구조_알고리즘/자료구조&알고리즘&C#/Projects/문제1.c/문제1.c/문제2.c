#include <stdio.h>
#include <stdlib.h>

int mostOnes(int **p, int n) {
   int i = 0, j = 0, sav = 0;

   while (1) {
      while (p[i][j] == 1) {
         j++;
         sav = i;
      }
	  if (j-1 == n-1) {
		  break;
	  }
      if (p[i][j] == 0) {
         i++;
      }

	  if (i == n - 1) {
		  if (p[i][n] == 1) {
			  break;
		  }
	  }
      if (i == n) {
         break;
      }
   }

   return sav;


}

void main() {

   int n, i, **p, j,ok;

   scanf("%d", &n);

   p = (int**)malloc(n * sizeof(int*));


   for (i = 0; i < n; i++) {
      p[i] = (int*)malloc(n * sizeof(int));
   }


   for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
         scanf("%d", &p[i][j]);
      }
   }

   ok= mostOnes(p, n);

   printf("%d", ok);

}