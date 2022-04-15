#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int main (){
	int mang[100],LCM=1,n,m=1;
	printf("nhap so phan tu...");scanf("%d",&n);
	int dem=1;
	bool dacbiet = true;           /* dung bool de loai truong hop so nhap co gia tri = 0*/
	for (int i=1;i<=n;i++){        /* <---------- Vong FOR (1) -------------nhap phan tu cho mang */
		printf("phan tu thu %d ....",i);scanf("%d",&mang[i]);
		dem *= mang[i];
		if (mang [i]==0){          /* khi nhap gia tri = 0, thoat vong FOR (1) */
			dacbiet = false;    
			break;                 
		}
	}
	int deme;
	if (dacbiet == true){          /*  <---------------------------------truong hop cac so nhap deu khac 0*/
		for (int j=1;j<=dem;j++){	/* <--------- Vong FOR (2) ----------cho j chay tu 1 den n=tich tat ca cac so hang*/
			deme = 0;	
			for (int k=1;k<=n;k++){		/* chia j cho lan luot tung so hang duoc nhap vao ( dieu kien (1))*/			
				if(j % mang[k] == 0){   /* neu co so j thoa man dieu kien (1) , j la LCM cua bo so */
					deme +=1;
				}
			}
			if( deme == n ){           /* ^                                    */
				LCM = j;               /* |                                    */
				m+= 1;                 /* |                                    */
				break;                 /* |									   */	
				                       /* |->gan LCM =j roi thoat vong FOR (2) */
			}                          /* |                                    */
			if(m>1) break;      	   /* |                                    */         
		}   						   /* v                                    */                            
		system("cls");printf("LCM cua %d so.....: ",n);
		for (int z=1;z<=n;z++) printf("%d\t",mang[z]);	
		printf("\n");
		printf("LCM= %d\n",LCM);      /* <---------------------------------in ra LCM*/
	}else{                /* <---------------------------------truong hop co 1 so = 0*/
		system("cls");
		printf("Do co phan tu = 0 nen LCM khong ton tai\n");
	}
	return 0;
}
