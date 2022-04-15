#include<stdio.h>
void sao(int g){
	for(int m=1;m<=g;m++){
		printf ("*");
	}
	printf("\n");
}

/*------------------------------------------------------------*/
int main(){
    int n;
    float arr[30];
    printf("nhap so hoc sinh ");scanf("%d",&n);
    
    for (int i=1; i <= n;i++){
    	int vrai=0;
    	/*---------------------------[1]----------------------------*/
    	while(vrai < 1){
    	/*---------------------------[1]---------------------------*/	
        printf("nhap diem cho hs thu %d\n",i);scanf("%f",&arr[i]);
        if (arr[i]>20){
        	printf("diem nhap phai < 20 \n");
        /*----------------------------[2]-----------------------------*/	
        } else {
        	vrai ++;
        	}        
        } 
        /*----------------------------[2]-----------------------------*/     
    }
    printf("bang diem hoc sinh\n");
    for (int j=1;j <= n;j++){
    	printf("/|%f|",arr[j]);
/*---------------------------------------------------------------*/
    }
    float min=arr[1];
    float max=0;
    float dem=0;
    /*------------------------------------*/
    int a=0;
    int b=0;
    int c=0;
    int d=0;
    /*-------------------------------------*/
    for (int k=1;k <= n; k++){
    	if (arr[k] >= max) max=arr[k];
    	if (arr[k] <= min) min=arr[k];
      	dem+=arr[k];
     /*-------------------------------------*/ 	
      	if (arr[k]>=0 && arr[k]<8) a++;
      	if (arr[k]>=8 && arr[k]<10) b++;
      	if (arr[k]>=10 && arr[k]<12) c++;
      	if (arr[k]>=12 && arr[k]<=20) d++;
     /*---------------------------------------*/
    }
    printf("\n");
    printf("diem lon nhat la %f , diem be nhat la %f\n",max,min);
    printf("trung binh cong %f\n",dem / (float)n);
    /*-----------------------------------------*/
    printf("-----------------\n");
    printf(" 0 -  8 :");sao(a);
    printf(" 8 - 10 :");sao(b);
    printf("10 - 12 :");sao(c);
    printf("12 - 20 :");sao(d);
    printf("-----------------\n");

    return 0;

}



