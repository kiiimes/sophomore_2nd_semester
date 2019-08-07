#include <stdio.h>
void swap (int *p1,int *p2){
	int temp;
	int *ptemp=&temp;
	*ptemp=*p1;
	*p1=*p2;
	*p2=*ptemp;

}




int main(){
	int arr[50],n,i,a,b,sav1,sav2;
	int *pn=&n,*pi=&i,*parr=arr,*pa=&a,*pb=&b,*psav1=&sav1,*psav2=&sav2;
	scanf("%d",pn);
	for(*pi=0;*pi<*pn;(*pi)++){
		scanf("%d",parr++);
		}
	scanf("%d %d",pa,pb);
	parr=arr;

	for(*pi=0;*pi<*pn;(*pi)++){//*pi++°ýÈ£¾ÈÄ§
		
		if(*pi==*pa){
			*psav1=parr[*pi];
				}
		else if(*pi==*pb){
			*psav2=parr[*pi];
		}
		
		

	}
	
	swap(psav1,psav2);

		for(*pi=0;*pi<*pn;(*pi)++){//*pi++°ýÈ£¾ÈÄ§
		
		if(*pi==*pa){
			*(parr+*pi)=*psav1;
				}
		else if(*pi==*pb){
			*(parr+*pi)=*psav2;
		}
		
		

	}
	
	for(*pi=0;*pi<*pn;(*pi)++){
		printf(" %d",parr[*pi]);

	}

	return 0;
}
