#include <stdio.h>
#include <stdlib.h>



    void hinhvuong(int a,char b){
    
        printf("nhap do dai canh cua hinh vuong");scanf("%d",&a);
        printf("chon ki tu de in hinh vuong");getchar();scanf("%c",&b);system("cls");
            
        for (int n=1;n<=a;n++)
        {
            for (int m=1;m<=a;m++){
                printf("%c",b);
                printf(" ");
            }
                printf("\n");
            
        
        }
    }
    void haha(int v) {
        printf("nhap so v\n");
        printf("....");
        getchar();scanf("%d",&v);
            
        for (int i=1; i <= v; i++){
            printf ("haha\n");
                // printf ("%d",v);printf("\n");
        }
    }  

    void tamgiacso(int a){
        printf("nhap so tang tam giac:....");getchar();scanf("%d",&a);system("cls");printf("\n");
   
           
        for (int i=1;i <= a; i++){
            for(int j=1;j<= a -i;j++){    
                printf("  ");
                
            }   
            for(int m=1;m<i;m++){
                printf("%d ",m);
                // printf("&");
            }
             
            printf("%d ",i);
            for (int v=i-1;v>0;v--){
               printf("%d ",v);  
                // printf("@");
            }
            
            
            for(int n=1;n<= a -i;n++){    
                printf("  ");
                
            }
            printf("\n");printf("\n");
            
            
        }   
    }
    // void tamgiackitu(int a,int j){
    //     printf("nhap so tang tam giac:....");getchar();scanf("%d",&a);system("cls");printf("\n");
    //     printf("nhap ki tu in tam giac:.....");getchar();scanf("%c",&j);
           
    //     for (int i=1;i <= a; i++){
    //         for(int j=1;j<= a -i;j++){    
    //             printf("  ");
                
    //         }   
    //         for(int m=1;m<i;m++){
    //             printf("%c ",j);
    //             // printf("&");
    //         }
             
    //         printf("%d ",i);
    //         for (int v=i-1;v>0;v--){
    //            printf("%d ",v);  
    //             // printf("@");
    //         }
            
            
    //         for(int n=1;n<= a -i;n++){    
    //             printf("  ");
                
    //         }
    //         printf("\n");printf("\n");
    //     }
    int main (){
    

    int a,v;
    char b,j;
    int c,d;
    int k=0;
        printf(" ---------------------");printf("\n")  ;
        printf("/    CT VE HINH HOC  /");printf("\n")  ;
        printf("---------------------");printf("\n")  ;
        printf("chon ct ve hinh");printf("\n");
        printf("1.hinh vuong\n");
        printf("2.nhung chu haha\n ");
        printf("3.hinh tam giac \n");
        printf("\n");
        while(k<1){
        
            printf(".....");scanf("%d",&c);
        
        switch (c){
            case 1:
                system("cls");
                hinhvuong(a,b);
                k=k+1;
            break;
            case 2:
                system("cls");
                haha(v);
                k += 1;
            break;
            case 3:
                system("cls");
                // printf("chon loai tam giac can in....\n");printf("1.tg so\n");printf("2.tgkt");getchar();scanf("%d",&d);
                // switch (d){
                //     case 1:
                //         system("cls");
                        tamgiacso(a);
                        k +=1;
                    // break;
                    // // // case 2:
                    // //     system("cls");
                    // //     tamgiackitu(a,j);
                    // //     k +=1;
                    // break;
                    // default:
                    //     printf("invalid number, vui long nhap dung so \n");
                    // break;
                // }

                
               
            break;      
            default:
                printf("invalid number, vui long nhap dung so \n");
            break;
     }
     }
        printf("ct ket thuc");printf("\n");
        system ("pause");
    return 0;
     
    }