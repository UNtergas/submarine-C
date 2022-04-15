#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>


typedef struct nguoidung{
	int age;
	char name[100];
	char nickname[50];
	char password[40];

}nd;
typedef nd * point;

// nd *haha;
// typedef nguoidung nd;

void regist(point haha ){
	printf("input name:");
	fgets(haha->name, sizeof (haha->name), stdin );
	//scanf("%c",haha->name);
	printf("input pass:");
	fgets(haha->password, sizeof (haha->password), stdin );
	// scanf("%c",haha->password);
}
void signin(point ha){
	printf("sign in\n");
	printf("username:");
	fgets(ha->name, sizeof (ha->name), stdin );
	printf("password:");
	fgets(ha->password, sizeof (ha->password), stdin );

}

void check(point in,point haha){
	int a,b;
	if(in->name != haha->name){
		 a= 1;
	}else if(in -> name == haha->name){
		 a= 3;
	}
	if(in->password != haha->password){
		 b= 2;
	}else if(in->password == haha->password){
		 b= 4;
	}
	printf("%s-%s",in->name,haha->name);
}	

int main(){
  	nd haha,in;
  	fflush(stdin);
  	regist(	&haha);
  	printf("your information\n");
 	printf("username:    %s", haha.name);
	printf("password:    %s\n", haha.password);
	printf("press any key to continue......you fell\n");getch();
	fflush(stdin);system("cls");
	signin (&in);
	printf("%s\n",in.name);
	printf("%s\n",in.password);
	check(&in, &haha);
	// printf("%d\n",a);

 	return 0;	
}

