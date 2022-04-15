#include<stdio.h>

int main(){
	int n;
	puts("nhap so n:.");scanf("%d",&n);
	printf("bang cuu chuong cua %d la \n",n);
	for (int i=1;i<=10;i++) {
		printf("%d * %d  = %d    ",i,n,i * n);
	}	
	return 0;
}