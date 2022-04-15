#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int main(){
	int n;
	int m=0;
	int arr[50];
	bool check =true;
	while(m==0){
		puts("nhap so n");scanf("%d",&n);
		while(check == true){
			if(n<=50){
				m+=1;
			}else{
				system("cls");
				printf("ban phai nhap so <= 50\n");
				break;
			}
			int sum=0;
			for (int i=1;i<=n;i++){
				arr[i]=i;
				sum+=arr[i];

			}
			double average;
			average= (float)sum/(float)n;
			printf("gtb %lf\n",average);
			check = false;	
		}	
	}
	
	return 0;
}	