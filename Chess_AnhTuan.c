// Probleme 1
typedef enum { BLANCE , NOIR} couleur ;

typedef enum { PION , CAVALIER , FOU , TOUR , ROI , DAME }	type_piece;

typedef struct 
	{
		type_piece type ; 
		couleur color ;
	} piece ;

typedef struct 
	{
		int ligne ; 
		int colonne ;	
	} position ; 

typedef struct 
	{
		position depart ; 
		position arrivee ;
	} deplacement ; 
	
// Probleme 2
//a.
void JEU_INITIATE ( piece *echiquier[8][8] )
	{
		int i,j ;
		for ( i=0 ; i<8 ; ++ )
			{
				for ( j=0 ; i< 8 ; j ++)
					{
						echiquier[i][j] = NULL ;
				 	} 
			}
		// khoi tao quan co 

	// ---------------------------------------------------------------------------------------//		
	// ------------------------------- Le_Noir (quan den)-------------------------------------//
	// ---------------------------------------------------------------------------------------//

	//La Dame
		piece *Noir_dame;
		Noir_dame = (piece*)malloc( sizeof(piece) );
		Noir_dame->type  = DAME;
		Noir_dame->color = NOIR;
		echiquier[0][3]  = Noir_dame;
	// Le Roi
		piece *Noir_roi;
		Noir_roi = (piece*)malloc( sizeof(piece) );
		Noir_roi->type  = ROI;
		Noir_roi->color = NOIR;
		echiquier[0][4] = Noir_roi; 
	//Le Cavalier
		piece *Noir_cavalier;
		Noir_cavalier = (piece*)malloc(sizeof(piece));
		Noir_cavalier->type  = CAVALIER;
		Noir_cavalier->color = NOIR;
		echiquier[0][1] = Noir_cavalier;
		echiquier[0][6] = Noir_cavalier;
	//La Fou
		piece *Noir_fou;
		Noir_fou = (piece*)malloc(sizeof(piece));
		Noir_fou->type  = FOU;
		Noir_fou->color = NOIR;
		echiquier[0][2] = Noir_fou;
		echiquier[0][5] = Noir_fou;
	//La Pion
		piece *NOIR_pion;
		NOIR_pion = (piece*)malloc(sizeof(piece));
		NOIR_pion->type  = PION;
		NOIR_pion->color = NOIR;
	for( j=0 ; j<8 ; j++ )
		{
			echiquier[1][j] = NOIR_pion;
		}
	// La Tour
		piece *NOIR_tour;
		NOIR_tour = (piece*)malloc(sizeof(piece));
		NOIR_tour->type  = TOUR;
		NOIR_tour->color = NOIR;
		echiquier[0][0]  = NOIR_tour;
		echiquier[0][7]  = NOIR_tour;
	
	// ---------------------------------------------------------------------------------------//		
	// ---------------------------- La_Blanc   (quan trang)-----------------------------------//
	// ---------------------------------------------------------------------------------------//

		
	//La Dame 
		piece *BLANC_dame;
		BLANC_dame = (piece*)malloc( sizeof(piece) );
		BLANC_dame->type  = DAME;
		BLANC_dame->color = BLANC;
		echiquier[7][3]   = BLANC_dame;
	
	//Le Roi
		piece *BLANC_roi;
		BLANC_roi = (piece*)malloc( sizeof(piece) );
		BLANC_roi->type  = ROI;
		BLANC_roi->color = BLANC;
		echiquier[7][4]  = BLANC_roi;
	
	//Le Cavalier
		piece *BLANC_cavalier;
		BLANC_cavalier = (piece*)malloc( sizeof(piece) );
		BLANC_cavalier->type  = CAVALIER;
		BLANC_cavalier->color = BLANC;
		echiquier[7][1] = BLANC_cavalier;
		echiquier[7][6] = BLANC_cavalier;
	
	//Le Fou
		piece *BLANC_fou;
		BLANC_fou = (piece*)malloc( sizeof(piece) );
		BLANC_fou->type = FOU;
		Noir_fou->color = BLANC;
		echiquier[7][2] = BLANC_fou;
		echiquier[7][5] = BLANC_fou;
	
	//La Pion
		piece *BLANC_pion;
		BLANC_pion = ( piece* ) malloc ( sizeof(piece) );
		BLANC_pion->type  = PION;
		BLANC_pion->color = BLANC;
		for( j=0 ; j<8 ; j++ )
			{
				echiquier[6][j] = BLANC_pion;
			}
	//Le Tour
		piece *BLANC_tour;
		BLANC_tour = (piece*)malloc( sizeof(piece) );
		BLANC_tour->type  = TOUR;
		BLANC_tour->color = BLANC;
		echiquier[7][0]   = BLANC_tour;
		echiquier[7][7]   = BLANC_tour;
		} 
	
// 2b.

void Affichage_de_Jeu ( piece *echiquier[8][8] )
	{
		int i , j , Y ;
		for ( i=0 ; i<8 ; i ++)
		{
			Y = 8 - i ; 
			printf("%d\t",a);
			for ( j=0 ; j<8 ; j ++)
				{
					if(echiquier[i][j]==NULL)
					{
						printf("|\t");
					}
				//Le Noir 
					//Le Roi
					if(echiquier[i][j] != NULL && echiquier[i][j]->type == 4 && echiquier[i][j]->color == 1)
					{
						printf("|R(noir)\t");
					}
					//Le Cavalier
					if(echiquier[i][j] != NULL && echiquier[i][j]->type == 1 && echiquier[i][j]->color == 1)
					{
						printf("|C(noir)\t");
					}
					//La Pion 
					if(echiquier[i][j] != NULL && echiquier[i][j]->type == 0 && echiquier[i][j]->color == 1)
					{
						printf("|P(noir)\t");
					}
					//La Fou
					if(echiquier[i][j] != NULL && echiquier[i][j]->type == 2 && echiquier[i][j]->color == 1)
					{
						printf("|F(noir)\t");
					}	
					//Le Tour
					if(echiquier[i][j] != NULL && echiquier[i][j]->type == 3 && echiquier[i][j]->color == 1)
					{
						printf("|T(noir)\t");
					}
					//La Dame
					if(echiquier[i][j] != NULL && echiquier[i][j]->type == 5 && echiquier[i][j]->color == 1)
					{
						printf("|D(noir)\t");
					}
				//La Blance
					//Le Roi
					if(echiquier[i][j] != NULL && echiquier[i][j]->type == 4 && echiquier[i][j]->color == 0)
					{
					printf("|R(blanc)\t");
					}
					//Le Cavalier
					if(echiquier[i][j] != NULL && echiquier[i][j]->type == 1 && echiquier[i][j]->color == 0)
					{
						printf("|C(blanc)\t");
					}
					//La Pion
					if(echiquier[i][j] != NULL && echiquier[i][j]->type == 0 && echiquier[i][j]->color == 0){
						printf("|P(blanc)\t");
					}
					//Le Fou
					if(echiquier[i][j] != NULL && echiquier[i][j]->type == 2 && echiquier[i][j]->color == 0){
						printf("|F(blanc)\t");
					}
					//Le Tour
					if(echiquier[i][j] != NULL && echiquier[i][j]->type == 3 && echiquier[i][j]->color == 0){
						printf("|T(blance)\t");
					}
					//La Dame
					if(echiquier[i][j] != NULL && echiquier[i][j]->type == 5 && echiquier[i][j]->color == 0){
						printf("|D(blance)\t");
					}	
				}
				printf("|");
				printf("\n\t-----------------------------------------------------------------\n");
		}
	}