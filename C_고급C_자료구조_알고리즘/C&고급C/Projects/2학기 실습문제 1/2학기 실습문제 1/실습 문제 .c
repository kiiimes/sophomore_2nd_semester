#include <stdio.h>
/*int main(){
	int n,x,y,z,i,count=0;
	scanf("%d %d %d %d",&n,&x,&y,&z);
	for(i=1;i<=n;i++){
		if(i%x==0){
			printf("");
		}
		else if(i%y==0){
			printf("");
		}
		else if(i%z==0){
			printf("");
		}
		else{
			printf(" %d",i);
			count++;
		
	}
		if(count==10){
			printf("\n");
			count=0;

		}
	}
	return 0;
}//문제 1
*/
 /*int main(){
	 int n,i,j,k,h,count=0;
	 char m='A'-1;
	 scanf("%d",&n);
	 for(i=1;i<=n;i++){
		 for(j=n-i;j>0;j--){
			 printf(" ");
		 }
		 for(k=1;k<=i;k++){
			 if(m+1=='Z'+1){
				 m='A'-1;
			 }
			 printf("%c",m+1);
			 m=m+1;
			  
			 count++;
			 if(count<i){
				 printf(".");
			 }
		 }
		 count=0;
		 printf("\n");

	 }
	 for(i=n-1;i>=1;i--){
		 for(j=1;j<=n-i;j++){
			 printf(" ");
		 }
		 for(k=1;k<=i;k++){
			  if(m+1=='Z'+1){
				 m='A'-1;
			 }
			 printf("%c",m+1);
			 m=m+1;
			 
			 count++;
			 if(count<i){
				 printf(".");
			 }
		 }
		 count=0;
		 printf("\n");
	 }


	 return 0;
 }*///문제2

/*int main(){
	int n,i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		
		for(j=i+1;j<=n;j++){
		
			for(k=j+1;k<=n;k++){
				printf("%d %d %d\n",i,j,k);
			
				
			}
		}
		
	}

	return 0;
}*///문제3
int main(){
	int x[100]={0},y[100]={0},z[100]={0},n,i,n1,sav,j,cnt=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&x[i]);
	}
	scanf("%d",&n1);
	for(i=0;i<n1*2;i++){
		scanf("%d",&y[i]);
	}
	for(i=0;i<n1;i++){
		for(j=y[i+1];j>=y[i];j--){
			z[cnt]=x[j];
			cnt++;
		}
		
		i=i+1;
	}



	
	for(i=0;i<=n;i++){
		printf("%d",x[i]);
	}

	return 0;
}










