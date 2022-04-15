#include<stdio.h.>
#include<string.h>

int main(){
	char kt[2000];
	printf("nhap chuoi\n");
	fgets(kt,2000,stdin);
	fflush(stdin);
	// getchar();
	char carak;
	printf("nhap ki tu\n");
	scanf("%c",&carak);
	fflush(stdin);
	// getchar();
	int dem=0;
	int k=strlen(kt) ;
	for(int i=0; i<= k; i++){
		if(kt[i] == carak) dem++;
		
	}
	printf("so ki tu trong chuoi <<%s>> la %d\n",kt,k-1);
	printf("co %d ki tu %c trong cum %s",dem,carak,kt);
	return 0;
}
