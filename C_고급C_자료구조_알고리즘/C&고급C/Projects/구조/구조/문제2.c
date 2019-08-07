#include <stdio.h>
struct vec{
	int s[3],v[3],a[3];

};

int main(){
	struct vec s1;
	int i,sum=0;

	for(i=0;i<3;i++){
		scanf("%d",&s1.s[i]);

	}
		for(i=0;i<3;i++){
		scanf("%d",&s1.v[i]);

	}
		for(i=0;i<3;i++){
			s1.a[i]=s1.s[i]*s1.v[i];
			printf("%d ",s1.a[i]);

		}
		printf("|\n");
			for(i=0;i<3;i++){
			sum+=s1.a[i];
					

		}
			printf("%d",sum);
		




			return 0;
}