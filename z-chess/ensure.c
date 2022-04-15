deplacement saisie_deplacement(echiquier grid,couleur player_color)
{

    int ok = 0;
    deplacement d1;
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
                printf("Move ?");
                scanf(" %c%i",&col2,&lig2);
                if(col2>'H' || col2 < 'A' || lig2 <1 || lig2>8 )
                    printf("Coordonnees non valides. Recommencez\n");
                else
                {
                    d1 = get_deplacement(col,lig,col2,lig2);
                    ok=1;
                }
            }
        }
    }
    return d1;
}