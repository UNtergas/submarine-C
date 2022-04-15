#include <stdio.h>


int main()
{
    int n;
    printf("in ra so nguyen to tu 1 den n ");scanf("%d",&n);
    for (int num = 1; num <= n;num++)
    {
        int count = 0;
        for (int i = 2; i < num; i++)
        {
            if (num % i == 0)
            {
                count++;
            }
        }
        if (count == 0 )
            printf("%d\t", num);
    }
    
    return 0;
    
}