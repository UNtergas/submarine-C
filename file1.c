#include<studio.h>

typedef enum{ APPLE,PC,STATION-DE-TRAVAIL } type ;

typedef struct 
{
	char numero_inventaire[] ;
	char nom_de_CPU[]
	int frequence;
	int disque;
	int ram;
	type type_ordinateur; 
	
} ordinateur ;


typedef struct 
typedef struct salle {
	nomsalle nomsalle;
	int number_ordinateur;
	int etage;
} salle ;


void entre ()
{
	int selection;
	printf("\n Type d'ordinateur : ");
	printf("\n1.APPLE \n2.PC \n3.Station de travail ");
re: printf(" Sélection : ");
	scanf("%d",&selection);
		if ( selection != 1 && selection != 2 && selection && != 3)
		{
			printf(" \n Choix inapproprié ! ");
			goto re ;
		}
}




