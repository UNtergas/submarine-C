#include<stdio.h>

typedef struct date 
{
	int date ; 
	int mois;
	int anne ; 
} date ;

typedef enum{resine, bridge, couronne} typeDeSoin ;
typedef enum {incisive,canine,premolaire,molaire,absente} typeDent;
typedef struct  
{
	char nom[3];
	typeDent type_dent;
	typeDeSoin type_soin;
	int dents_haute[16];
	int dents_basse[16];
} dent ;

typedef struct
{
	char nom[10];
	char prenom[10];
	date dates ; 
	dent nombre_dents ;
	
} client ;


