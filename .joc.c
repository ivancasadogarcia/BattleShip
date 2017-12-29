/*----------------------------------------------------------------
 |	Autor: Ivan Casado Garcia
 |  e-mail: ivan.casado@estudiants.urv.cat
 |	Data: Gener 2016                 Versio: 2.8
 |-----------------------------------------------------------------|
 |	Nom projecte: Vaixells
 |	Nom: joc.c
 |  Descripcio del Programa:   Desenvolupament principal del joc.
 | ----------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "vaixells.h"
#include "funcions.h"
#include "tipus.h"

/*CAPCELERES DE LES FUNCIONS O ACCIONS PRINCIPALS DEL PROGRAMA*/
bool nou(int *dim, int *num_jugadors, jugador_tipus jugadors[]);
void partida(bool carga, int dim, int num_jugadors, jugador_tipus jugadors[]);
void podium(double novo);
void sortir(bool *final);

/*FUNCIÓ MAIN on es desenvolupa tot el joc*/
int main()
{
    char menu = 'L';
    int dim=0, num_jug=-1;
    double dim_real=0, total_real=0, resultat_real=0;
    bool final=false, carg=false;
    jugador_tipus jugador[2];
    record_tipus novo;

    novo.nou.pun=0;

    srand((unsigned int)time(NULL));

    /*MENÚ PRINCIPAL*/
    while (!final)
    {
        if (!carg)
        {
            printf( "\nMENU PRINCIPAL" );
            printf( "\n\n1. Crear un nou joc               <N>\n" );
            printf( "2. Carregar un joc emmagatzemat   <C>\n" );
            printf( "3. Veure podium                   <P>\n" );
            printf( "4. Sortir del joc                 <S>" );
        }

        else
        {
            printf( "\n\nMENU PRINCIPAL" );
            printf( "\n\n1. Crear un nou joc               <N>\n" );
            printf( "2. Carregar un joc emmagatzemat   <C>\n" );
            printf( "3. Jugar partida                  <J>\n" );
            printf( "4. Emmagatzemar el joc            <G>\n" );
            printf( "5. Veure podium                   <P>\n" );
            printf( "6. Sortir del joc                 <S>" );
        }

        printf( "\n\nSeleccionar: " );
        scanf("%c", &menu);      /*TRIAR OPCIÓ*/

        if (menu>96)
        {
            menu=menu-32;
        }

        switch( menu )
        {
            case ('N') : carg=nou(&dim, &num_jug, jugador);                 /*Genera un nou joc*/
                break;
            case ('C') : carg=recupera_joc(FITXER_JOC, &dim, &num_jug, jugador);        /*Carrega un joc emmagatzemat*/
                break;
            case ('J') : partida(carg, dim, num_jug, jugador);              /*Executa la partida*/

                dim_real=dim; resultat_real=jugador[num_jug].tirs_resultat; total_real=jugador[num_jug].tirs_total;
                if (carg)
                {
                    novo.nou.pun=100*((dim_real/total_real)*(resultat_real-total_real));
                    /*printf("\n Puntuacio: %00.f   %f %i    %f %i    %f %i\n", novo.nou.pun, dim_real,dim, resultat_real,jugador[num_jug].tirs_resultat, total_real,jugador[num_jug].tirs_total);*/
                }
                break;
            case ('G') : carg=emmagatzema_joc(FITXER_JOC, dim, num_jug, jugador);      /*Emmagatzema la partida*/
                break;
            case ('P') : podium(novo.nou.pun);                                          /*Visualitza el posium*/
                break;
            case ('S') : sortir(&final);                                    /*Sortida del joc*/
                break;
        }

        menu=getchar();        /*Treure el '\n' de la variable tipus caràcter, i evitar una repetició del bucle*/
    }

    return 0;
}



/*CREAR UN NOU JOC*/
/*FUNCIÓ PRINCIPAL on es desenvolupa tota la inicialització de les matrius (posicions dels vaixells i llançaments), i el número de jugadors*/
bool nou (int *dim, int *num_jugadors, jugador_tipus jugadors[])
{
    char autom='Y';
    int i;

    *dim=1;                 /*Inicialitza la variable 'dim'*/
    printf( "\nNOU JOC" );

    while (*dim<8 || *dim>10)                           /*Entra en un bucle per verificar que 'dim' introduida sigui correcte*/
    {
        printf( "\nIntrodueix una dimensio de taulell valida [8=8x8, 9=9x9, 10=10x10]: " );
        scanf("%i", &*dim);
    }
    printf("Ha seleccionat una taula de joc de %ix%i\n", *dim, *dim);

    *num_jugadors=-1;       /*Inicialitza la variable 'num_jugadors'*/
    while (*num_jugadors<0 || *num_jugadors>2)         /*Entra en un bucle per verificar que 'num_jugadors' introduida sigui correcte*/
    {
        printf( "\nIntrodueix un numero de jugadors valid [0=Maquina, 1=Maquina vs. Jugador]: " );
        scanf("%i", &*num_jugadors);
    }

    if (*num_jugadors>0)
    {
        printf( "\nOPCIO DE JOC\n" );
        printf( "Vol generar un taulell automaticament (En cas contrari, es demanara manualment les posicions) [s=SI / n=NO]: ");
        autom=getchar();
        scanf("%c", &autom);

        for (i=0; i<*num_jugadors+1; i++)
        {
            jugadors[i].tirs_resultat=0;
            jugadors[i].tirs_total=0;
            jugadors[i].vaixells_enfonsats=0;

            inici_taulell_resultats(*dim, jugadors[i].taulell_resultat);
            inici_taulell_vaixells(*dim, jugadors[i].taulell_vaixells);
        }

        if (autom=='S'| autom=='s')
        {
            for (i=0; i<*num_jugadors+1; i++)
            {
                inicia_taulell(*dim, jugadors[i].taulell_vaixells);
            }
            imprimir_taulell(*dim, jugadors[1].taulell_vaixells);
        }

        else
        {
            inicia_elmeu_taulell(*dim, jugadors[1].taulell_vaixells);
            inicia_taulell(*dim, jugadors[0].taulell_vaixells);
        }
    }

    else
    {
        jugadors[0].tirs_resultat=0;
        jugadors[0].tirs_total=0;
        jugadors[0].vaixells_enfonsats=0;

        inici_taulell_resultats(*dim, jugadors[0].taulell_resultat);
        inici_taulell_vaixells(*dim, jugadors[0].taulell_vaixells);

        inicia_taulell(*dim, jugadors[0].taulell_vaixells);

        imprimir_taulell(*dim, jugadors[0].taulell_vaixells);
    }
    printf("\n\n\n");

    return true;     /*Retorna carga=true per mostrar al MENÚ PRINCIPAL totes les opcions de joc*/
}


/*PROCEDIMENT PODIUM*/
/*FUNCIÓ PRINCIPAL on es desenvolupa tota gestió dels records*/
void podium (double novo)
{
    int num_records=0;
    char menuP='c';
    bool fi=false, llegir=false, emmagatzemar=false;
    record_tipus record[DIM];
    FILE* reset;

    record[0].nou.pun=novo;    /*Emmagatzemar la puntuació en un apartat*/

    /* MENÚ PRODIUM */
    while (!fi)
    {
        printf( "\n\n\nPODIUM" );
        printf( "\n\n1. Llegir fitxer                <L>\n" );
        printf( "2. Afegir records al fitxer     <A>\n" );
        printf( "3. Sortir                       <S>\n" );

        printf( "\nTria una opcio: " );
        scanf("%c", &menuP);
        scanf("%c", &menuP);

        if (menuP>96)
        {
            menuP=menuP-32;
        }

        switch (menuP)
        {
            case ('L'):    /* OPCIÓ 1: Llegir el fitxer i mostrar per pantalla el que hi ha escrit */
                llegir=recupera_records(FITXER_RECORDS, &num_records, record);
                imprimir_records_pantalla(record, &num_records);

                break;

            case ('A'):    /* OPCIÓ 2: Llegir un conjunt de caracters i un numero enter introduits per teclar, i posar-ho a un fitxer */
                if (!llegir)
                {
                    llegir=recupera_records(FITXER_RECORDS, &num_records, record);
                }

                if (!emmagatzemar)
                {
                    emmagatzemar=emmagatzema_records(FITXER_RECORDS, num_records, record);
                }

                llegir=false;
                break;

            case ('S'): printf("\n\n");    /* OPCIÓ 3: Finalitzar el bucle i sortir del programa */

                fi=true;
                break;

            case ('R'): printf("\nRESET FITXER %s\n", FITXER_RECORDS);

                reset=fopen(FITXER_RECORDS, "w");
                fclose(reset);
                break;
        }
    }

    menuP=getchar();
}


/*SORTIR DEL JOC*/
void sortir (bool *fi)
{
    printf( "\n\nSORTIDA DEL JOC" );
    *fi=true;
    printf("\nFins aviat!!:)\n\n\t");
}
