#include <stdio.h>
#include <string.h>
int main(){
	int n,i,count=0,sav[4];
	char arr[50]={NULL};

	scanf("%d",&n);





	for(i=0;;i++){
		count++;
		sav[i]=n%10;
		n=n/10;
		if(n==0){
			break;
		}
	}

		for(i=3;count!=0;i--){
			if(sav[count-1]==0){
				
				count--;
				continue;

			}



			switch(sav[count-1]){
			case 1: strcat(arr,"one "); break;
			case 2: strcat(arr,"two "); break;
			case 3: strcat(arr,"three "); break;
			case 4: strcat(arr,"four "); break;
			case 5: strcat(arr,"five "); break;
			case 6: strcat(arr,"six "); break;
			case 7: strcat(arr,"seven "); break;
			case 8: strcat(arr,"eight "); break;
			case 9: strcat(arr,"nine "); break;
			}
			if(count==4){
				strcat(arr,"THO ");
				count--;

			}
			else if(count==3){
				strcat(arr,"HUN ");
				count--;
			}
				else if(count==2){
				strcat(arr,"TEN ");
				count--;
			}
				else{
					count--;

				}
				
		}

		for(i = 0; arr[i] ; i++);

		arr[i-1] = '\0';

	

		
				printf("%s",arr);












	return 0;
}
