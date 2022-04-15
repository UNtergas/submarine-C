#include<stdio.h>

int main(){
   int a,b,c,max;
   printf("nhap 3 so a,b,c :");scanf("%d  %d  %d",&a,&b,&c);
   max=a;
   if (max < b){
		max=b;  			
   }
   if (max <c){
   		max=c;
   }
   printf("so lon nhat...%d\n",max);
   return 0;
}