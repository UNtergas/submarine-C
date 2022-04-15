#include<stdio.h>

int main(){
	float a,b,c;
	double tb;
	printf("nhap diem toan  ");scanf("%f",&a);
	printf("nhap diem anh   ");scanf("%f",&b);
	printf("nhap diem van   ");scanf("%f",&c);
	tb=(a+b+c)/3;printf("diem trung binh : %f\n",tb);
	printf("xep hang hoc sinh:   ");
	if (tb < 4.0){
		printf("yeu");
	
	} else if (tb <6.5){
		printf("trung binh");
	} else if (tb <8.0){
		printf("kha");
	} else {
		printf("gioi");	
	}
	printf("\n");
	return 0;
}