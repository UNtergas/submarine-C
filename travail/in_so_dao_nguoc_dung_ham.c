#include<stdio.h>

/*---[<|>]-----------------------------------------------------------------------------[<|>]---*/
/*---[<|>]--------HAM (1):-in so dao nguoc    -----------------------------------------[<|>]---*/
/*---[<|>]------------------------------------------------------------- ---------------[<|>]---*/

int daonguoc(int n){
	
	int temp;

	while (n>10){
		// if (n<10){
		// 	temp=n;
		// 	break;
		// }
		temp = n % 10;
		n /= 10;
		printf("%d",temp);
	}	
	temp=n;
	return temp;
}

/*---[<|>]-----------------------------------------------------------------------------[<|>]---*/


int main(){
	int n;
	printf("nhap so N.....");scanf("%d",&n);
	printf("%d\n",daonguoc(n));
	return 0;

}