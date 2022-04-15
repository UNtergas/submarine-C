#include<stdio.h>
#include<stdlib.h>

float moyenne(const float *tab, int nbelem)
{
 float m=0;
 int i;
 for (i=0;i<nbelem;i++)
 m+=tab[i];
 return m/nbelem;
}

int main(){
	
}
