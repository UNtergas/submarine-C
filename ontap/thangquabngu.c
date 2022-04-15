#include<stdio.h>
#include<stdlib.h>

typedef struct Element Element;
struct Element{
	int nombre;
	Element *suivant;
};

typedef struct Liste Liste;
struct Liste{
	Element *premier;
};

Liste *initialisation()
{
    Liste *liste;
    liste = (*liste) malloc(sizeof(liste));
    Element *element = malloc(sizeof(*element));

    if (liste == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    element->nombre = 0;
    element->suivant = NULL;
    liste->premier = element;

    return liste;
}

void insertion(Liste *liste, int nvNombre)
{
    /* Création du nouvel élément */
    Element* nouveau = (nouveau*) malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->nombre = nvNombre;

    /* Insertion de l'élément au début de la liste */
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}

void suppression(Liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (liste->premier != NULL)
    {
        Element *aSupprimer = liste->premier;
        liste->premier = liste->premier->suivant;
        free(aSupprimer);
    }
}

void afficherListe(Liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *actuel = liste->premier;

    while (actuel != NULL)
    {
        printf("%d -> ", actuel->nombre);
        actuel = actuel->suivant;
    }
    printf("NULL\n");
}

int main(){
	int n;
	printf("ajouter le nombre du element....");
    scanf("%d",&n);
    Liste *maListe = initialisation();
    for(int i = 1; i <= 6; i++){
        int m;
        printf("ajouter le nombre inserer %d ...",i);
        scanf("%d",&m);
        insertion(maListe,m);
    }
    afficherListe(maListe);
    return 0;
}