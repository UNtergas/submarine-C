#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
for(int a=0;a<=5;a++){
		for(int i=1;i<=5;i++){
			// puts("0|------|0  \n");
			printf(" ");
			printf("||");
			for(int j=1;j<=6;j++){
				if(i + a <= 5){
					printf(" ");
				}else{
					printf("*");
				}
			}
			printf("||");
			printf(" ");
			printf("\n");
		}
		sleep(1);
		system("cls");
	}	
}