#include<stdio.h>
#include<string.h>

#include<stdio.h>
#include<string.h>

int pgcd(int m, int n)
{
	int tmp;
	if (m < n){
		tmp=m;
		m=n;
		n=tmp;
	}
	if (m % n == 0){
		return n;
	}
	return pgcd(m,m % n);

}

int main(){
	int m,n;
	printf("...");
	scanf("%d %d",&m,&n);
	printf("pcdg:..%d\n",pgcd(m,n));
	return 0;

	
}