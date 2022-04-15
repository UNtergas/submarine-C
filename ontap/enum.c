#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TAILLE 3
typedef enum { JANVIER=1, FEVRIER, MARS, AVRIL, MAI, JUIN, JUILLET, AOUT, SEPTEMBRE, OCTOBRE, NOVEMBRE, DECEMBRE } mois;
typedef char texte[255];
typedef struct
{
    mois m;
    int a; /* ann�e */
} date;
typedef struct
{
    int code;
    texte titre;
    texte auteur;
    texte editeur;
    date d;
} livre;


livre saisie_livre()
{
    livre l;
    printf("Titre du livre ? ");
    scanf("%s",l.titre);
    printf("Auteur du livre ? ");
    scanf("%s",l.auteur);
    printf("Editeur du livre ? ");
    scanf("%s",l.editeur);
    printf("Date d'emprunt du livre : \n");
    printf("Mois (en chiffre) ?");
    do
    {
        scanf("%i",&l.d.m);
    }while(l.d.m<1 || l.d.m>12);
    printf("Annee ?");
    scanf("%i",&l.d.a);

    return l;
}

void affichage_livre(livre l)
{
    char mois[12][10]={"Janvier","Fevrier","Mars","Avril","Mai","Juin","Juillet","Aout","Septembre","Octobre","Novembre","Decembre"};

    printf("Titre du livre : %s\n",l.titre);
    printf("Auteur du livre : %s\n",l.auteur);
    printf("Editeur du livre : %s\n",l.editeur);
    printf("Date d'emprunt du livre : %s %i\n",mois[l.d.m-1],l.d.a);
}
void saisie_biblio(livre bibli[],int nb_livres)
{
    int i;
    for(i=0;i<nb_livres;i++)
        bibli[i] = saisie_livre();
}
void affichage_biblio(livre bibli[],int nb_livres)
{
    int i;
    for(i=0;i<nb_livres;i++)
        affichage_livre(bibli[i]);
}
void search_autor(livre bibli[],int nb_livres,texte autor)
{
    int i;
    for(i=0;i<nb_livres;i++)
        if(strcmp(bibli[i].auteur,autor)==0)
            affichage_livre(bibli[i]);
}
int search_editor(livre bibli[],int nb_livres,texte editor)
{
    int i,compteur = 0;
    for(i=0;i<nb_livres;i++)
        if(strcmp(bibli[i].editeur,editor)==0)
            compteur++;
    return compteur;
}
int main()
{
    texte txt;
    livre bibliotheque[TAILLE];
    saisie_biblio(bibliotheque,TAILLE);
    affichage_biblio(bibliotheque,TAILLE);
    printf("Quel auteur recherchez vous ? ");
    scanf("%s",txt);
    search_autor(bibliotheque,TAILLE,txt);
    printf("Quel editeur recherchez vous ? ");
    scanf("%s",txt);
    printf("Nous avons %i livres de l'editeur %s\n",search_editor(bibliotheque,TAILLE,txt),txt);

    return 0;
}