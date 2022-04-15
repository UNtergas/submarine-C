#include<stdio.h>
#include<stdlib.h>

struct Node{
	int value;
	struct Node* next;
};

void empiler(struct Node** head, int item){
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->value = item;
	node->next = *head;
	*head=node;
}

int depiler(struct Node** head){
	int result;
	struct Node* depil=(struct Node*)malloc(sizeof(struct Node));
	depil=*head;
	result=depil->value;
	*head=depil->next;
	free(depil);
	return result;
}

void afficher(struct Node** head){
	struct Node* current= *head;
	while(current!=NULL){
		printf("%d ->",current->value);
		current=current->next;
	}
	printf("NULL\n");
}

int main(){
	struct Node* tete=NULL;
	empiler(&tete,3);
	empiler(&tete,4);
	empiler(&tete,9);
	empiler(&tete,1);
	printf("etat de la pile");
	afficher(&tete);
	return 0;
}