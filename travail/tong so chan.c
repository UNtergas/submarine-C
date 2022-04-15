#include <stdio.h>
 
int main()
{
    int a, b;
    int sum = 0;
 
    printf("Nhap a = ");
    scanf("%d", &a);
 
    printf("Nhap b = ");
    scanf("%d", &b);
 
    // Nếu a > b => thoát chương trình
    if (a > b)
    {
        printf("Khong hop le!");
        return 0;
    }
 

    for(int i = a; i <= b; i++){
        if(i % 2 == 0){
            sum += i;
        }
    }
    printf("tong %d\n",sum);

        return 0;
}    