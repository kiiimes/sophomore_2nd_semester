#include <stdio.h>
#include <string.h>

int main(){
	int n,i,a,arr[50]={NULL},count=4,s;
	char str[50]={NULL};

	scanf("%d",&n);

	for(i=0;;i++){
		arr[i]=n%10;
		n=n/10;
		if(n==0){

		break;
		}

	}
	s=i;
	
	for(i=s;;i--){
		a=arr[i];
	
		switch(a){
		case 1:strcat(str,"one ");break;
		case 2:strcat(str,"two ");break;
		case 3:strcat(str,"three ");break;
		case 4:strcat(str,"four ");break;
		case 5:strcat(str,"five ");break;
		case 6:strcat(str,"six ");break;
		case 7:strcat(str,"seven ");break;
		case 8:strcat(str,"eight ");break;
		case 9:strcat(str,"nine ");break;

		}
		
			if(count==4){
				strcat(str,"THO ");
			}
			else if(count==3){
				strcat(str,"HUN ");
			}
			else if(count==2){
				strcat(str,"TEN ");
			}
			else if(count==1){
				break;
			}
		
		
		count--;
	
	
	}
	printf("%s",str);


	return 0;
}