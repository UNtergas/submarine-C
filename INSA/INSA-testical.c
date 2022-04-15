#include <stdio.h>
int main(){
	int tab[5];
	int nb_valeurs,i;
	printf("Combien d'entiers souhaitez vous stocker ?\n");
	scanf("%i",&nb_valeurs);
	printf("Saisissez vos %i valeurs.\n",nb_valeurs);
	for(i=0;i<nb_valeurs;i++){
		printf("Valeur %i : ",i+1);
		scanf("%i",&tab[i]);
	}
	printf("votre tableau contient :\n");
	for(i=0;i<nb_valeurs;i++)
	printf("Valeur %i : %i\n",i+1,tab[i]);
	return 0;
}
	 