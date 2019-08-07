#include <stdio.h>
struct vec{
	int s[3],v[3];



};
int main(){
	struct vec s1;
	int i;

	for(i=0;i<3;i++){
		scanf("%d",(s1.s)+i);

	}
		for(i=0;i<3;i++){
		scanf("%d",(s1.v)+i);

	}

		for(i=0;i<3;i++){
			printf("%d ",(s1.s[i])+(s1.v[i]));

		}


	return 0;
}