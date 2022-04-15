#include<stdio.h>
#include<stdlib.h>

void nhapgt(int *a, int *b, int *c){
  printf("nhap do dai 3 canh \n");
  scanf("%d   %d   %d",&*a,&*b,&*c);
  

}

void tgpossif(int *chek1, int a, int b, int c){
	// nhapgt(a,b,c);
	    *chek1=0;
    if(a+b>=c && a+c >=b && b+c>=a)
    	*chek1+=1;
}
// void maxi(int a, int b, int c){

// 	int max=a;
// 	int ot1=b;
// 	int ot2=c;
// 	if(b>a){
// 		max=b;
// 		ot1=a;
// 	}else if(c>a){
// 		max=c;
// 		ot1=a;
// 	}else{
// 		ot1=b;
// 		ot2=c;
// 	}
	

// }

void tgvuong(int *chek2, int a, int b, int c){
	// nhapgt(a,b,c);
	*chek2=0;
    if(a*a + b*b == c*c || b*b + c*c ==a*a || c*c + a*a == b*b)
    *chek2+=1;
 
}
void tgcan(int *chek3, int a, int b, int c){
	// nhapgt(a,b,c);
	*chek3=0;
	if(a==b || c==a || b==c)
	*chek3+=2; 
}
void tgdeu(int *chek4, int a, int b, int c){
	// nhapgt(a,b,c);
	*chek4=0;
	if(a==b && b==c)
	*chek4+=3;
}

int main(){
	int d,f,g;
	int call=0;
	int kek1,kek2,kek3,kek4;
 	int  keke=0;
 	int  spec=0;

	nhapgt(&d,&f,&g);
	tgpossif(&kek1,d,f,g);
	tgvuong(&kek2,d,f,g);
	tgcan(&kek3,d,f,g);
	tgdeu(&kek4,d,f,g);
	while (call==0){

		if(kek1==1){
			printf("tam giac kha thi\n");
		}else{
			printf("ko la tam giac\n");
			call++;
			break;
		}
		if(kek3 + kek2 == 3){
			printf("tam giac vuong can\n");
			keke++;
			spec++;
		}	
		if(keke==0){
			if(kek2==1){
				printf("tam giac vuong\n");
				spec++;
			}
			if(kek3==2 && kek4==0){
				printf("tam giac can\n");
				spec++;
	        }
	        if(kek4==3){
	        	printf("tam giac deu\n");
	        	spec++;
	        }
	    if (spec==0){
	    	printf("tg binh thuong\n");

	    }
	       
	}
	call++;
}
}	