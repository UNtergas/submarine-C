void dichuyenkhathi(echiquier grid,char col2, int lig2, ,char col, int lig,int *camco){
	dong=col -'A';
	cot=_SIZE - lig;
	dong2=col2 -'A';
	cot2=_SIZE - lig2;

	switch (grid[dong][cot]->type){
	//_____________________	
	//--------pawn---------
	//=====================
		case PION:
	 		if(col2!=col){
				printf("move immpossible");
				break;
			}else if(lig2-lig<=2&&lig2-lig>0){
				camco
				break;
			}
		
	}	
}



deplacement saisie_deplacement(echiquier grid,couleur player_color)
{

    int ok = 0;
    int ok2= 0;
    int camco=0;
    deplacement d1;
    deplacement d2;
    char col,col2;
    int lig,lig2;
    while(ok==0)
    {
        if(player_color==NOIR){
            printf("den luot quan do\n");
        }else if (player_color==BLANC){
            printf("den luot quan vang \n");
        }
        printf("input..");
        scanf(" %c%i",&col,&lig);
        if(col>'H' || col < 'A' || lig <1 || lig>8 )
            printf("Coordonnees non valides. Recommencez\n");
        else
        {
            d1.depart.colonne=col-'A';
            d1.depart.ligne = _SIZE-lig;
            if(grid[d1.depart.ligne][d1.depart.colonne]==NULL)
                printf("Pas de piece ici. Recommencez\n");
            else if (grid[d1.depart.ligne][d1.depart.colonne]->color!= player_color)
                 printf("Cette piece n'est pas la votre. Recommencez\n");
            else
            {
                //  kiem tra la quan dong minh truoc khi di chuyen
                //
                while(ok2==0){
                    //while(camco==0){
                        printf("Move ?");
                        scanf(" %c%i",&col2,&lig2);
                        d2.depart.colonne=col2-'A';
                        d2.depart.ligne = _SIZE-lig2;

                    if(col2>'H' || col2 < 'A' || lig2 <1 || lig2>8 )
                        printf("Coordonnees non valides. Recommencez\n");
                    else if(grid[d2.depart.ligne][d2.depart.colonne]->color== player_color){
                        printf("ban khong the an quan cua chinh minh\n");
                    }else{

                        d1 = get_deplacement(col,lig,col2,lig2);
                        ok2=1;
                    }
                }
                ok=1;
            }
        }
    }
    return d1;
}
