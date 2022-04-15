#include<stdio.h>
#define SIZE 1000

void nhapmang(int arr[], int *n){
	puts("nhap gia tri n");
	scanf("%d",&*n);
	for(int i=0; i<*n; i++){
		scanf("%d",&arr[i]);
	}
}

void xuatmang(int arr[], int n){
	for(int i=0; i<n; i++){
		printf("\t %d",arr[i]);
	}
}

int summang(int arr[], int n, int sum){
	for(int i=0; i<n; i++){
		sum+=arr[i];
	}
	return sum;
}
void ordermang(int arr[], int n){
	int ao;
	printf("\n");
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]<arr[j]){
				ao=arr[i];
				arr[i]=arr[j];
				arr[j]=ao;
			}

		}
	}
}


int main(){
	int heye[SIZE];
	int n;
	nhapmang(heye,&n);
	xuatmang(heye,n);
	// int SUM=0;
	ordermang(heye,n);
	xuatmang(heye,n);
	printf("\n");
	// printf("\n tong %d \n",summang(heye,n,SUM));
	return 0;
}	