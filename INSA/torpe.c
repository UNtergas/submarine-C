#include <stdio.h>
#include <stdlib.h>

void min_maj(char* c,char* g){
	 if(*c>='a' && *c<='z')
	 *c = *c +'A'-'a';
	 else if (*c>='A' && *c<='Z')
	 *c = *c +'a'-'A';	
	 g = c;
	printf("dia chi c trong void  %p|%c\n",c,*c);
	 }	
// void min_maj2(char* p,char c){
	
// 	 if(c>='a' && c<='z')
//      c = c +'A'-'a';
// 	 else if (c>='A' && c<='Z')
// 	 c = c +'a'-'A';
// 	p=&c;
// 	printf("address faux  %p|%c\n",&c,c);	
	 
// 	 }
int main() {
	char h;
	// char *gj;
	char c;
	printf("Saisissez un caractere.\n");
	c=getchar();
	min_maj(&c,&h);
	char *j=&h;
	*j=3;
	// min_maj2(&h,c);
	printf("dia chi c  %p|%c\n",&c,c);	
	printf("dia chi h %p|%c\n",&h,h);

	// printf("Le nouveau caractere est : %c.\n",c);
	return 0;
}