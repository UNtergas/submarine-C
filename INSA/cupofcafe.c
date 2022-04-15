#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// #include <time.h>

void waterline1(){
	puts("      ||     \n");
	puts("     //      \n");
	puts("    //       \n");
	puts("    ``       \n");
	puts("     ``      \n");
	puts("      ``     ");

}
void waterline2(){
	puts("      ||        \n");
	puts("       ``       \n");
	puts("        ``      \n");
	puts("         ``     \n");
	puts("        //      \n");
	puts("       //       ");

}
void processdisplay(int n){
	printf("|----------------------|\n");
    printf("|Progress:       %d    	\n",n*20);
    printf("|----------------------|\n");
    printf("|-||-CAFE-||--||EAU||--|\n");
    printf("|---(----)-------------|\n");
    printf("    ||  ||             \n");
    printf("     [!!]              \n");
}
void cupofcafe(){
	
	for(int a=0;a<=5;a++){
		processdisplay(a);
		if (a % 2 == 0){
			waterline1();
		
			
		}else{
			waterline2();
		
		}

		for(int i=1;i<=5;i++){
			// puts("0|------|0  \n");
			printf("  ");
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
		printf("   ========");
		sleep(1);
		system("cls");
	}	
}	
void fini(){
	printf("||=====================||\n");
    printf("|| votre cafe est fini ||\n");
    printf("||=====================||\n");
	printf("         | | |    \n");
	printf("         / / /    \n");
	printf("                  \n");
	printf("      ||*******|| \n");
	printf("      ||*******|| \n");
	printf("      ||*******|| \n");
	printf("      ||*******|| \n");
	printf("      ||*******|| \n");
	printf("       =========\n");

}

int main(){
	cupofcafe();
	fini();
	return 0;
}
