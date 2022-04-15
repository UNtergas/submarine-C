#include<stdio.h>

int main(){
	int n,dem;
	printf("\nnhap so n....");scanf("%d",&n);

	for(int i=2;i<=n;i++){
		dem=0;
		while(n % i == 0){
			dem += 1;
			n /= i;
		}
		if(dem){
			if(dem>1) printf("%d^%d",i,dem);
			else printf("%d",i);
			if (n>1) printf("*");
		}
	}
	printf("\n");
	return 0;
}	