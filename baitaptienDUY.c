#include "stdio.h"
#include "math.h"
#include "stdlib.h"

int calcul(int a){
    if(a<2)
        return 1;
    return a*calcul(a-1);
}

int result(int a){
    int flag;
    flag = a % 10;
    return flag;
}

char* factoriel (int a){
    char* group=(char*)malloc(sizeof(calcul(a)));

    while(result(calcul(a))<10){
     group = (char*)result(a) + '0';
    }
    return group;
}   

int main(){
    char* group= factoriel(10);
    printf("%s",group);
    return 0 ;
}