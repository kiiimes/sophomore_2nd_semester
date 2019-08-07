#include <stdio.h>
struct student{
	int sex,kg,cm;


};

int main(){
	struct student grade[10];
	int n,i,a=0,b=0,c=0;

	scanf("%d",&n);

	for(i=0;i<n;i++){
		scanf ("%d %d %d",&grade[i].sex,&grade[i].kg,&grade[i].cm);

	}




	for(i=0;i<n;i++){
		if(grade[i].sex==1){
			if(grade[i].cm<165){
				if(grade[i].kg<60)
					a++;
				else if(grade[i].kg<70)
					c++;
				else 
					b++;

			}
			else if(grade[i].cm<175){
				if(grade[i].kg<60)
					b++;
				else if(grade[i].kg<70)
					a++;
				else 
					c++;

			}
			else {
				if(grade[i].kg<60)
					c++;
				else if(grade[i].kg<70)
					b++;
				else 
					a++;

			}


		}
		if(grade[i].sex==2){
			if(grade[i].cm<165){
				if(grade[i].kg<50)
					a++;
				else if(grade[i].kg<60)
					c++;
				else 
					b++;

			}
			else if(grade[i].cm<175){
				if(grade[i].kg<50)
					b++;
				else if(grade[i].kg<60)
					a++;
				else 
					c++;

			}
			else {
				if(grade[i].kg<50)
					c++;
				else if(grade[i].kg<60)
					b++;
				else 
					a++;

			}
		}
	}
	printf("%d %d %d",a,b,c);
	return 0;
}