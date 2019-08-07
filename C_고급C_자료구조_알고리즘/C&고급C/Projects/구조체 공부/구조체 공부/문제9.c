#include <stdio.h>
#include <string.h>
typedef struct complex{
	float s,h;

}complex;
complex add(complex *b1,complex *psum){
	
	int i;


		for(i=0;i<2;i++){
			psum->s=psum->s+b1[i].s;
			psum->h=psum->h+b1[i].h;
		}
		return *psum;
	
	

}

void main(){
	complex a[2],*sum={0};
	int i;

	for(i=0;i<2;i++){
		scanf("%f %f",&(a[i].s),&(a[i].h));
	}
	
	add(a,sum);
	
	printf("%f + %fi",sum->s,sum->h);


}