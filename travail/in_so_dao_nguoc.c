#include<stdio.h>

int main(){
	int n;
	printf("nhap so N.....");scanf("%d",&n);
	int temp;

	while (n>10){
		if (n<10){
			break;
		}
		temp = n % 10;
		n /= 10;
		printf("%d",temp);
	}	
	printf("%d\n",n);
	return 0;
}