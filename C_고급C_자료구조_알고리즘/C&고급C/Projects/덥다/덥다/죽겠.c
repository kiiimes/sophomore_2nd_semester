#include <stdio.h>
int main()/*{
		  int num1,num2,i,j,ar1;
		  scanf("%d %d",&num1,&num2);
		  for(i=0;i<num1;i++){
		  ar1=i;
		  for(j=1;j<=num2;j++){
		  printf("%d",ar1);
		  ar1++;
		  }
		  printf("\n");
		  }
		  return 0;
		  }*/
		  /*{
		  int x[100],i,max,min;
		  scanf("%d",&x[0]);
		  max=x[0],min=x[0];
		  for(i=1;i<100;i++){
		  scanf("%d",x[i]);

		  }


		  return 0;
		  }*/
		  /*{
		  int n,k,i,num1,count=0,a=0;
		  scanf("%d %d",&n,&k);
		  for(i=1;i<=n;i++){
		  scanf("%d",&num1);
		  count++;
		  if(k==num1){
		  printf("%d ",count);
		  a=1;
		  }
		  }
		  if(a==0){
		  printf("%d",n+1);
		  }
		  return 0;
		  }*/
		  /*{
		  int a,b,c,d,e,f,num1,num2,num3;
		  scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
		  if((f-c)<=0){
		  printf("%d",c-f);}
		  else if((f-c)>0){
		  printf("%d",c+(10-f));
		  b--;
		  }
		  if((e-b)<=0){
		  printf("%d",b-e);}
		  else if((e-b)>0){
		  printf("%d",b+(10-e));
		  a--;
		  }
		  if((d-a)<=0){
		  printf("%d",b-e);}
		  else if((e-b)>0){
		  printf("%d",b+(10-e));
		  a--;
		  }





		  return 0;
		  }*/
		  /*{
		  int n,i,num1,su=1,sum=0;
		  scanf("%d",&n);
		  scanf("%d",&num1);
		  sum+=num1;
		  for(i=1;i<n;i++){
		  scanf("%d",&num1);
		  su*=10;
		  sum=sum+num1*su;
		  }
		  printf("%d",sum);
		  return 0;
		  }*/
		  /*{
		  int n,m,i,oh,ar;
		  scanf("%d %d",&n,&m);
		  if(n>=m){
		  oh=m;
		  }
		  else oh=n;
		  for(i=1;i<=oh;i++){
		  if(m%i==0&&n%i==0){
		  ar=i;
		  }
		  }
		  printf("%d",ar);
		  return 0;
		  }*/
{
	int x[100],i,max,min;
	scanf("%d",&x[0]);
	max=x[0],min=x[0];
	for(i=1;i<100;i++){
		scanf("%d",&x[i]);
		if(x[i]==0){
			break;
		}
		if(max<=x[i]){
			max=x[i];
		}
		if(min>=x[i]){
			min=x[i];
		}
		
	}
	printf("%d %d",max,min);


	return 0;
}































