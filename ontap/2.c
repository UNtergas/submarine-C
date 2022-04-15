#include<stdio.h>
#include<stdlib.h>


void xoaphantu(int * p,int &n){
	int m;
	
	printf("nhap ph/an tu muon xoa");
	scanf("%d",&m);
	for(int k=m-1 ;k<=n-1;k++){
		p[k]=p[k+1];

	}
p = (int *)realloc(p,(n-1) * sizeof(int));
n--;
}
void inmang(int * p,int n){
	printf("\n\n");
	for(int i=0;i<n;i++){
		printf(" phan tu thu %d cua mang",i+1);
		printf("  %d  \n",p[i]);
	}

}
void themphantu(int *p,int &n){
	int m,k;
	p=(int*)realloc(p,(n+1)*sizeof(int));
	
	printf("nhap so them");
	scanf("%d",&k);
	printf("nhap vi tri them");
	scanf("%d",&m);
	for(int l=n+1;l>=m-1;l--){
		p[l]=p[l-1];
	}
p[m-1]=k;
n++;

}

int main(){
	int *ptr;
	int n;
	printf("nhap so luong phan tu");
	scanf("%d",&n);
	ptr = (int*) malloc (n * sizeof(int));
	if(ptr==NULL){
		printf("error");
		exit(0);
	}
	for(int i=0;i<n;i++){
		printf("nhap phan tu thu %d cua mang",i+1);
		fflush(stdin);scanf("%d",ptr+i);

	}
	inmang(ptr,n);
	// xoaphantu(ptr,n);
	themphantu(ptr,n);
	inmang(ptr,n);
	free(ptr);
	return 0;	
}