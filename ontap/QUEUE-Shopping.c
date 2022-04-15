#include<stdio.h>
#include<stdlib.h>

typedef struct File{
	int* tab;
	int head;
	int tail;
}File;

void initfile(File * f,int n){
	f->tab= (int*)malloc(n*sizeof(int));
	f->head = 1;
	f->tail = 1;
}

bool estVide(File* f){
	if(f->head == f->tail){
		return true;
	}
	return false;
}

bool estPleine(File* f){
	int veftail=f->tail % sizeof(f->tab)+1;
	if(f->head == veftail){
			return true;
		}
	return false;
}

bool enfiler(File *f,int x){
	if(estPleine(f) == false){
		f->tab[f->tail]=x;
		f->tail=(f->tail % sizeof(f->tab)) + 1;
		return true;
	}
	return false;
}

int defiler(File *f){
	if(estVide(f)==false){
		int x = f->tab[f->head];
		f->head=(f->head % sizeof(f->tab))+1;
		return x;
	}
}


int main(){
	int n;
	int x;
	int i=1;
	File* point;
	printf("size: ");
	scanf("%d",&n);
	initfile(point,n);
	while(estPleine(point)==false){
		printf("in num %d: ",i);
		scanf("%d",&x);
		// nhap so 0 de dung qua trinh enfiller
		if(x==0){
			break;
		}
		enfiler(point,x);
		i++;
	}
	for(int i=0;i<point->head;i++){
		printf("out num%d\n",defiler(point));
	}
	return 0;
}