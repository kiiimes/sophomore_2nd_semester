#include <stdio.h>
int main9(){

}

int main10(){
		


}
int main11(){

}

void print_line(int x,int y,int z){
	int j,k,s;
	for(j=1;j<=x;j++){
		printf(" ");
	}
	for(k=1;k<=y;k++){
		printf("*");
	}
	for(s=1;s<=z;s++){
		printf(" ");
	}
}
int main12(){
	int i,num1;
	scanf("%d",&num1);
	for(i=1;i<=num1;i++){
		print_line(num1-1,(num1*2)-1,num1-1);
	}
	return 0;
}
void print_line(int x,int y,int z){
	int j,k,s;
	for(j=1;j<=x;j++){
		printf(" ");
	}
	for(k=1;k<=y;k++){
		printf("*");
	}
	for(s=1;s<=z;s++){
		printf(" ");
	}
}




int main13(){

}
int main14(){

}
int main()
{
	int pro_num=0;
	scanf("%d\n",&pro_num);
	switch(pro_num){
	case 9:main9(); break;
	case 10:main10(); break;
	case 11:main11(); break;
	case 12:main12(); break;
	case 13:main13(); break;
	case 14:main14(); break;
	
	}
}

































	
	