#include<stdio.h>
#include<stdlib.h>

struct Element{
	int value;
	Element* next;
};

struct Pile{
	Element* tete;
};

void empiler(struct Pile* pile, int item){
	struct Element* element =(struct Element*)malloc(sizeof(struct Element));
	element->value = item;
	element->next = pile->tete;
	pile->tete = element->next;
}

int depiler(struct Pile* pile){
	int result;
	struct Element* depil=pile->tete;
	result = depil->value;
	pile->tete = depil->next;
	free(depil);
	return result;
}

void afficher(struct Pile* pile){
	struct Element* current = pile->tete;
	while(current->next != NULL){
		printf("%d ->",current->value);
		current = current->next;
	}
}

int main(){
	struct Pile* pile=(struct Pile*)malloc(sizeof(struct Pile));
	pile->tete=NULL;
	empiler(pile,7);
	empiler(pile,4);
	empiler(pile,6);
	empiler(pile,3);
	empiler(pile,2);
	printf("etat de pile\n");
	afficher(pile);
	depiler(pile);
	printf("etat de pile\n");
	afficher(pile);
	return 0;
}