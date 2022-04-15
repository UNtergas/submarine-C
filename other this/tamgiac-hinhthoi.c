    #include<stdio.h>
    #include<stdlib.h>

    int main (){
        int a;
        printf("nhap so tang tam giac:....");scanf("%d",&a);system("cls");printf("\n");
   
        /* in tang thuan cua tam giac */

        for (int i=1;i <= a; i++){
            for(int j=1;j<= a -i;j++) printf("  ");    /*tao khoang trong*/
                
            for(int m=1;m<i;m++) printf("%d ",m);   /*in phan ria tam giac*/
                        
            printf("%d ",i);           /*in truc chinh tam giac*/

            for (int v=i-1;v>0;v--) printf("%d ",v);  /*in phan ria tam giac*/
              
            for(int n=1;n<= a -i;n++) printf("  ");   /*tao khoang trong*/
        
            printf("\n");
            
        }    

            /*in phan phan dao nguoc cua tam giac */
            /*bo phan code o duoi de tao thanh 1 tam giac bt,
            giu ca 2 se tao ra 1 hinh thoi co chieu cao= 2*(a-1)+ 1 */

        for (int w=a-1;w>0;w--){
            for(int e=w;e<a && e!=0;e++) printf("  ");

            for(int r=1;r <= w-1;r++) printf("%d ",r);

            printf("%d ",w);

            for(int D=w-1;D>0;D--) printf("%d ",D);

            for(int X=w;X<a && X !=0;X++) printf("  ");

            printf("\n");
        } 

        return 0;
}