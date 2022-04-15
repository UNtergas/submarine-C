#ifndef arbre_h
#define arbre_h

#include <stdio.h>

struct noeud{
	int data;
	struct noeud* gauche;
	struct noeud* droite;
};

struct 