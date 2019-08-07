/*{
	double x[5]={0},min=x[0];
	int i,index;
	for(i=0;i<5;i++){
		scanf("%lf",&x[i]);
	}
	min=x[0];
	for(i=1;i<5;i++){
		if(min>x[i]){
			min=x[i];
			index=i;
		}
	}
	printf("%lf\n%d",min,index);
	return 0;
}*///실습 5
/*{
	int a[2][3]={{10,20,50},{20,30,40}};//{국어 영어 수학}
	int i,j;
	for(i=0;i<2;i++){
		for(j=0;j<3;j++){
			printf("a[%d][%d]=%d\n",i,j,a[i][j]);
		
		}
	}
	return 0;
}*/
/*{
	int gr[3][2]={{20,100},{70,36},{30,50}};
	int i,j,sum;
	double ave;
	for(i=0;i<3;i++){
		sum=0;
		ave=0;
		for(j=0;j<2;j++){
			sum+=gr[i][j];
			
		}
		ave=sum/2;
		printf("%lf\n",ave);

	}*/
/*{
	int num[3][3],i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%d",&num[i][j]);
		}
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%d",num[i][j]);
		}
		printf("\n");
	}
	return 0;
}*///실습 7
/*{
	int x[3][3]={0},i,j;
	int hang,yeol,num;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%d",x[i][j]);
		}
		printf("\n");
	}
	scanf("%d %d %d",&hang,&yeol,&num);
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(i==hang-1&&j==yeol-1){
				printf("%d",num);
			}
			else{
				printf("%d",x[i][j]);
			}
		}	
		printf("\n");
	}
	return 0;
}*///실습 8
#include <stdio.h>
int main()
/*{
	int x[10],i,j,count;
	for(i=0;i<10;i++){
		scanf("%d",&x[i]);
	}
	for(i=0;i<10;i++){
		count=0;
		for(j=0;j<i;j++){
			if(x[j]==x[i]){
				count++;
				break;
			}
		}
		if(count==1){
			printf("");
		}
		else if(count==0){
		printf(" %d",x[i]);
		}
	}
	return 0;
}*/
/*{
	int n,i,j,count1,count2=0,num1;
	scanf("%d",&n);
	for(i=1;;i++){
		count1=0;
		for(j=1;i>=j;j++){
			if(i%j==0){
				count1++;
			}
			
		}
		if(count1==2){
			num1=i;
			count2++;
		}
		if(count2==n){
			printf("%d",num1);
			break;
		}
	}
	return 0;
}*///복습문제 1
{
	int n,bj,bm,jgo=1,mgo=1,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d %d",&bj,&bm);
		jgo*=bj;
		mgo*=bm;
	}
	for(i=1;;i++){
		if(jgo%i==0&&mgo%i==0){
			jgo=jgo/i;
			mgo=mgo/i;
			if(jgo/i==0&&mgo/i==0){
				break;
			}
		}
		i=1;
	}
	printf("%d/%d",jgo,mgo);
	return 0;
}






















