#include "data.h"
#include "interface.h"
#include "jeu.h"
#include<stdio.h>

//1– La modélisation : déterminer les données que vous allez manipuler
typedef enum{BLANC, NOIR} couleur;
typedef enum{PION, CAVALIER, FOU, TOUR, ROI, DAME} type_piece;
typedef struct piece_{
	type_piece type;
	couleur color;
}piece;
typedef struct position_{
	int ligne;
	int colonne;
}position;
typedef struct deplacement_{
	position depart;
	position arrivee;
}deplacement;
//2-les fonction de base
//a) Initilisation 
void init_jeu(piece *echiquier[8][8]){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			echiquier[i][j] = NULL; // au debut l'echiquier est vide
		}
	}
	// ======================================PIECES-NOIR===============================================
	//ROI
	piece *roi_noir;
	roi_noir = (piece*)malloc(sizeof(piece));
	roi_noir->type = ROI;
	roi_noir->color = NOIR;
	echiquier[0][4] = roi_noir;
	//CAVALIER
	piece *cavalier_noir;
	cavalier_noir = (piece*)malloc(sizeof(piece));
	cavalier_noir->type = CAVALIER;
	cavalier_noir->color = NOIR;
	echiquier[0][1] = cavalier_noir;
	echiquier[0][6] = cavalier_noir;
	//FOU
	piece *fou_noir;
	fou_noir = (piece*)malloc(sizeof(piece));
	fou_noir->type = FOU;
	fou_noir->color = NOIR;
	echiquier[0][2] = fou_noir;
	echiquier[0][5] = fou_noir;
	//PION
	piece *pion_noir;
	pion_noir = (piece*)malloc(sizeof(piece));
	pion_noir->type = PION;
	pion_noir->color = NOIR;
	for(int j=0;j<8;j++){
		echiquier[1][j] = pion_noir;
	}
	//TOUR
	piece *tour_noir;
	tour_noir = (piece*)malloc(sizeof(piece));
	tour_noir->type = TOUR;
	tour_noir->color = NOIR;
	echiquier[0][0] = tour_noir;
	echiquier[0][7] = tour_noir;
	//DAME
	piece *dame_noir;
	dame_noir = (piece*)malloc(sizeof(piece));
	dame_noir->type = DAME;
	dame_noir->color = NOIR;
	echiquier[0][3] = dame_noir;
	// ======================================PIECES-BLANC=============================================== 
	//ROI(B)
	piece *roi_blanc;
	roi_blanc = (piece*)malloc(sizeof(piece));
	roi_blanc->type = ROI;
	roi_blanc->color = BLANC;
	echiquier[7][4] = roi_blanc;
	//CAVALIER(B)
	piece *cavalier_blanc;
	cavalier_blanc = (piece*)malloc(sizeof(piece));
	cavalier_blanc->type = CAVALIER;
	cavalier_blanc->color = BLANC;
	echiquier[7][1] = cavalier_blanc;
	echiquier[7][6] = cavalier_blanc;
	//FOU(B)
	piece *fou_blanc;
	fou_blanc = (piece*)malloc(sizeof(piece));
	fou_blanc->type = FOU;
	fou_blanc->color = BLANC;
	echiquier[7][2] = fou_blanc;
	echiquier[7][5] = fou_blanc;
	//PION(B)
	piece *pion_blanc;
	pion_blanc = (piece*)malloc(sizeof(piece));
	pion_blanc->type = PION;
	pion_blanc->color = BLANC;
	for(int j=0;j<8;j++){
		echiquier[6][j] = pion_blanc;
	}
	//TOUR(B)
	piece *tour_blanc;
	tour_blanc = (piece*)malloc(sizeof(piece));
	tour_blanc->type = TOUR;
	tour_blanc->color = BLANC;
	echiquier[7][0] = tour_blanc;
	echiquier[7][7] = tour_blanc;
	//DAME(B)
	piece *dame_blanc;
	dame_blanc = (piece*)malloc(sizeof(piece));
	dame_blanc->type = DAME;
	dame_blanc->color = BLANC;
	echiquier[7][3] = dame_blanc;
}
void affichage_jeu(piece *echiquier[8][8]){
	for(int i=0;i<8;i++){
		int a = 8-i;
		printf("%d\t", a);
		for(int j=0;j<8;j++){
			if(echiquier[i][j]==NULL){
				printf("|\t");
			}
			//=========================PIECES-NOIR==================================================
			//roi(n)
			if(echiquier[i][j] != NULL && echiquier[i][j]->type == 4 && echiquier[i][j]->color == 1){
				printf("|R(n)\t");
			}
			//cavalier(n)
			if(echiquier[i][j] != NULL && echiquier[i][j]->type == 1 && echiquier[i][j]->color == 1){
				printf("|C(n)\t");
			}
			//pion(n)
			if(echiquier[i][j] != NULL && echiquier[i][j]->type == 0 && echiquier[i][j]->color == 1){
				printf("|P(n)\t");
			}
			//fou(n)
			if(echiquier[i][j] != NULL && echiquier[i][j]->type == 2 && echiquier[i][j]->color == 1){
				printf("|F(n)\t");
			}
			//tour(n)
			if(echiquier[i][j] != NULL && echiquier[i][j]->type == 3 && echiquier[i][j]->color == 1){
				printf("|T(n)\t");
			}
			//dame(n)
			if(echiquier[i][j] != NULL && echiquier[i][j]->type == 5 && echiquier[i][j]->color == 1){
				printf("|D(n)\t");
			}
			//=======================================PIECES-BLANC=====================================
			//roi(b)
			if(echiquier[i][j] != NULL && echiquier[i][j]->type == 4 && echiquier[i][j]->color == 0){
				printf("|R(b)\t");
			}
			//cavalier(b)
			if(echiquier[i][j] != NULL && echiquier[i][j]->type == 1 && echiquier[i][j]->color == 0){
				printf("|C(b)\t");
			}
			//pion(b)
			if(echiquier[i][j] != NULL && echiquier[i][j]->type == 0 && echiquier[i][j]->color == 0){
				printf("|P(b)\t");
			}
			//fou(b)
			if(echiquier[i][j] != NULL && echiquier[i][j]->type == 2 && echiquier[i][j]->color == 0){
				printf("|F(b)\t");
			}
			//tour(b)
			if(echiquier[i][j] != NULL && echiquier[i][j]->type == 3 && echiquier[i][j]->color == 0){
				printf("|T(b)\t");
			}
			//dame(b)
			if(echiquier[i][j] != NULL && echiquier[i][j]->type == 5 && echiquier[i][j]->color == 0){
				printf("|D(b)\t");
			}
		}
		printf("|");
		printf("\n\t-----------------------------------------------------------------\n");
	}
	char str = 'a';
	for(int k=0;k<8;k++){
		printf("\t    %c", str);
		str++;
	}
}
deplacement saisie_deplacement(piece *echiquier[8][8], couleur colordejoueur){
	position deplacer;
	position arriver;
	deplacement deplace;
	printf("\nLa position de la piece a deplacer: ");
	do{
		printf("\nNhap toa do truc y: ");
		scanf("%d", &deplacer.ligne);
		fflush(stdin);
		printf("\nNhap toa do truc x: ");
		scanf("%d", &deplacer.colonne);
		fflush(stdin);
	}while(deplacer.ligne>8 || deplacer.colonne>8 || echiquier[8-deplacer.ligne][deplacer.colonne-1]->color!=colordejoueur);
	if(echiquier[8-deplacer.ligne][deplacer.colonne-1]==NULL){
		printf("\nPiece n'existe pas! ");
	}
	if(echiquier[8-deplacer.ligne][deplacer.colonne-1]!=NULL){
		printf("\nLa position de la destination: ");
		do{
			printf("\nNhap toa do truc y: ");
		    scanf("%d", &arriver.ligne);
		    fflush(stdin);
		    printf("\nNhap toa do truc x: ");
		    scanf("%d", &arriver.colonne);
		    fflush(stdin);
	    }while(arriver.ligne>8 || arriver.colonne>8);
	}
	deplace.depart.ligne = deplacer.ligne;
	deplace.depart.colonne = deplacer.colonne;
	deplace.arrivee.ligne = arriver.ligne;
	deplace.arrivee.colonne = arriver.colonne;
	return deplace;
}
void deplacer_piece(piece *echiquier[8][8], couleur colordejoueur){
	deplacement deplace2;
	deplace2 = saisie_deplacement(echiquier, colordejoueur);
	if(echiquier[8-deplace2.arrivee.ligne][deplace2.arrivee.colonne-1]!=NULL){
		echiquier[8-deplace2.arrivee.ligne][deplace2.arrivee.colonne-1]=NULL;
	}
	echiquier[8-deplace2.arrivee.ligne][deplace2.arrivee.colonne-1] = echiquier[8-deplace2.depart.ligne][deplace2.depart.colonne-1];
	echiquier[8-deplace2.depart.ligne][deplace2.depart.colonne-1]=NULL;
}

int main()
{

    init_dessins_pieces(dessin_piece);
    printf("\n\n\n\n\n\n \t\tMETTRE EN PLEIN ECRAN PUIS APPUYER SUR UNE TOUCHE\n");getchar();
    	deplacement de;
	piece *echiquier[8][8];
	init_jeu(echiquier);
	affichage_jeu(echiquier);
	deplacer_piece(echiquier, BLANC);
	affichage_jeu(echiquier);
	printf("\n\n");


  return 0;
}
