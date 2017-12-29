/*----------------------------------------------------------------
 |	Autor: Ivan Casado Garcia
 |  e-mail: ivan.casado@estudiants.urv.cat
 |	Data: Gener 2016                 Versio: 2.8
 |-----------------------------------------------------------------|
 |	Nom projecte: Vaixells
 |	Nom: funcions.c
 |  Descripcio del Programa:   Implementacio dels procediments.
 | ----------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "tipus.h"
#include "vaixells.h"
#include "funcions.h"

/** NIVEL 1 */
/*
 funcio num_aleatori (max:enter, min:enter) retorna enter;
 */
int num_aleatori (int max, int min)     /*Regenador de número aleatori amb interval*/
{
    int aleatori=0;

    aleatori=rand()%(max-min+1)+min;

    return aleatori;
}

/*
 accio imprimir_taulell (dim:enter, t:taula de caracters);
 */
void imprimir_taulell (int dim, char t[][DIM_MAX])     /*Funció per mostrar per pantalla la matriu*/
{
    int i, c, f;

    printf("\n");
    printf("  ");
    for (i=0; i<dim; i++)
    {
        printf(" %i", i+1);
    }

    printf("\n");
    for (f=0; f<dim; f++)
    {
        printf("\n%c ", f+65);

        for (c=0; c<dim; c++)
        {
            printf(" %c", t[f][c]);
        }
    }

    printf("\n");
}

/*
 accio inici_taulell_resultats (dim:enter, taulell_resultats:taula de caracters);
 */
void inici_taulell_resultats (int dim, char taulell_resultats[][DIM_MAX])     /*Inicialitza la matriu dels llançaments amb '?'*/
{
    int f, c;

    for (f=0; f<dim; f++)
    {
        for (c=0; c<dim; c++)
        {
            taulell_resultats[f][c]='?';
        }
    }
}

/*
 accio inici_taulell_vaixells (dim:enter, taulell_vaixells:taula de caracters);
 */
void inici_taulell_vaixells (int dim, char taulell_vaixells[][DIM_MAX])     /*Inicialitza la matriu dels vaixells amb '.'*/
{
    int f, c;

    for (f=0; f<dim; f++)
    {
        for (c=0; c<dim; c++)
        {
            taulell_vaixells[f][c]='.';
        }
    }
}

/*
 accio imprimir_records_pantalla (t:taula de record_tipus, var num_records:enter);
 */
void imprimir_records_pantalla (record_tipus t[], int *num_records)     /*Mostrar els record del fitxer per pantalla*/
{
    int n;

    printf("Procediment recupera_records...");
    if(*num_records-1!=0)
    {
        printf("\n\n\nRECORDS (TOP 10)\n");
    }
    for (n=0; n<*num_records-1 && n<DIM_MAX; n++)
    {
        if (t[n].nom[0]!=46)
        {
            printf("%i. %s \t\t%.00f\n", n+1, t[n].nom, t[n].pun);
        }
    }

    printf("\nNumero de jugadors totals: %i", *num_records-1);
}

/*
 funcio verificacio_posicio (dim:enter, taulell_vaixells:taula de caracters, tipus_vaixell:enter, vaixell:coor_tipus, var error:enter) retorna boolea;
 */
bool verificacio_posicio (int dim, char taulell_vaixells[][DIM_MAX], int tipus_vaixell, coor_tipus vaixell, int *error)
{
    int f, c;
    bool corr, fi=false;

    corr=true;

    if (vaixell.orientacio==1)     /*En el cas que l'orientació sigui vertical*/
    {
        for (f=vaixell.y-2; f<((tipus_vaixell+2)+(vaixell.y-2)) && corr; f++)
        {
            for (c=vaixell.x-2; c<(3+vaixell.x-2) && corr; c++)
            {
                if ((f>=0 && f<dim) && (c>=0 && c<dim))
                {
                    if (taulell_vaixells[f][c]!='.' || taulell_vaixells[f][c]=='@')
                    {
                        corr=false;
                        *error=1;
                    }
                }
            }
        }

        for (f=vaixell.y-1; f<(tipus_vaixell+(vaixell.y-1)); f++)
        {
            if (f>=dim)
            {
                corr=false;
                *error=2;
            }
        }

        if (corr)
        {
            for (f=vaixell.y-1; f<(tipus_vaixell+(vaixell.y-1)); f++)
            {
                taulell_vaixells[f][vaixell.x-1]='@';
            }
            fi=true;
            *error=0;
        }
    }

    else     /*En el cas que l'orientació sigui horitzontal*/
    {
        for (f=vaixell.y-2; f<(3+vaixell.y-2) && corr; f++)
        {
            for (c=vaixell.x-2; c<((tipus_vaixell+2)+(vaixell.x-2)) && corr; c++)
            {
                if ((f>=0 && f<dim) && (c>=0 && c<dim))
                {
                    if (taulell_vaixells[f][c]!='.' || taulell_vaixells[f][c]=='@')
                    {
                        corr=false;
                        *error=1;
                    }
                }
            }
        }

        for (c=vaixell.x-1; c<(tipus_vaixell+(vaixell.x-1)); c++)
        {
            if (c>=dim)
            {
                corr=false;
                *error=2;
            }
        }

        if (corr)
        {
            for (c=vaixell.x-1; c<(tipus_vaixell+(vaixell.x-1)); c++)
            {
                taulell_vaixells[vaixell.y-1][c]='@';
            }
            fi=true;
            *error=0;
        }
    }

    return fi;
}

/*
 funcio emmagatzema_records (var fitxer_record:fitxer, num_records:enter, records:taula de record_tipus) retorna boolea
 */
bool emmagatzema_records (char fitxer_record[], int num_records, record_tipus records[])     /*Llegeix un nou record introduit per teclat*/
{
    record_tipus nou, aux;
    bool correcte=true;
    int n, i;
    FILE* frecord;

    frecord=fopen(fitxer_record, "w");    /* Obrir el fitxer en mode escriptura */

    printf("Procediment emmagatzema_records...\n\nIntrodueix un nom pel record, un maxim de 7 caracters: ");
    scanf("%s", nou.nom);

    if (nou.nom[CARACTERS_MAX-1]!=0)
    {
        correcte=false;
        while (!correcte)
        {
            printf("No et passis de caracters! Nomes 7 [Exemple: SUPREM1]: ");
            scanf("%s", nou.nom);

            if (nou.nom[CARACTERS_MAX-1]==0)
            {
                correcte=true;
            }
        }
    }

    nou.pun=records[0].nou.pun;

    for (i=0; nou.pun!=-1 && i<DIM; i++)
    {
        if (nou.pun>=records[i].pun)
        {
            aux.pun=records[i].pun;
            records[i].pun=nou.pun;
            nou.pun=aux.pun;

            strcpy(aux.nom, records[i].nom);
            strcpy(records[i].nom, nou.nom);
            strcpy(nou.nom, aux.nom);
        }
    }

    for (n=0; n<num_records && n<DIM; n++)
    {
        fprintf(frecord, "%s\t%f\n", records[n].nom, records[n].pun);     /*Llegeix el nom del jugador*/
    }
    printf("\nEmmagatzemat!\n\n");

    fclose(frecord);
    return true;
}

/*
 funcio recupera_records (var fitxer_record:fitxer, var num_records:enter, records:taula de record_tipus) retorna boolea.
 */
bool recupera_records (char fitxer_record[], int *num_records, record_tipus records[])     /*Llegir els record del fitxer*/
{
    int i;
    FILE* frecord;

    frecord=fopen(fitxer_record, "r");    /* Obrir el fitxer en mode lectura */

    if (frecord == NULL)
    {
        printf("\nError: No existeix %s\n", fitxer_record);
    }

    else
    {
        for (i=0; i<DIM+1; i++)     /*INICIAR LA TAULA RECORD AMB '\n' al nom I -1 a la puntuació*/
        {
            records[i].nom[0]='\n';
            records[i].pun=-1;
        }

        for (i=0; !feof(frecord) && i<DIM; i++)
        {
            fscanf(frecord, "%s", records[i].nom);      /*Llegeix el nom del jugador*/
            fscanf(frecord, "%lf", &records[i].pun);     /*Llegeix la puntuació*/
        }

        records[i].nom[0]='.';
        *num_records=i;
    }

    fclose(frecord);
    return true;
}

/*
 accio jugar (var f:caracter, var c:enter, dim:enter, taulell_llancament:taula de caracters);
 */
void jugar(char *f, int *c, int dim, char taula[][DIM_MAX])
{
    bool aprop=false, A=false, B=false, X=false, Y=false;
    int f_enter, c_enter;

    f_enter=*f-65; c_enter=*c-1;

    if (taula[f_enter][c_enter]=='X')
    {
        if (taula[f_enter-1][c_enter]=='?')
        {
            Y=true;  aprop=true;
        }

        else if (taula[f_enter][c_enter+1]=='?')
        {
            B=true;  aprop=true;
        }

        else if (taula[f_enter+1][c_enter]=='?')
        {
            A=true;  aprop=true;
        }

        else if (taula[f_enter][c_enter-1]=='?')
        {
            X=true;  aprop=true;
        }

        if (!A && !B && !X && !Y)
        {
            aprop=false;
        }
    }

    if (aprop)
    {
        if (A)
        {
            *f=f_enter+66;
            *c=c_enter+1;
        }

        else if (B)
        {
            *f=f_enter+65;
            *c=c_enter+2;
        }

        else if (X)
        {
            *f=f_enter+65;
            *c=c_enter;
        }

        else if (Y)
        {
            *f=f_enter+64;
            *c=c_enter+1;
        }
    }

    else
    {
        *f=num_aleatori(64+dim, 65);
        *c=num_aleatori(dim, 1);
        aprop=false;
    }
}

/** NIVEL 2 */
/*
 funcio emmagatzema_joc (nom_fitxer:taula de caracters, dim, num_jugadors:enter, jugadors:taula de jugador_tipus) retorna boolea;
 */
bool emmagatzema_joc (char nom_fitxer[], int dim, int num_jugadors, jugador_tipus jugadors[])
{
    FILE* guardar;
    int f, c, i;
    bool buit, maquina;
    char continuar='c';

    printf("Procediment emmagatzema_joc...");

    maquina=false;
    buit=false;
    guardar=fopen(nom_fitxer, "rb");

    if (guardar==NULL)
    {
        printf("\nError: No existeir el fitxer partida.bin");
    }

    else if (feof(guardar))
    {
        buit=true;
    }

    else
    {
        printf("\n\nHi ha una partida, si emmagatzema la actual, esborrara la anterior.\nVol emmagatzemar el joc? [s=SI / n=NO]: ");
        continuar=getchar();
        scanf("%c", &continuar);

        if (continuar=='s')
        {
            buit=true;
        }
    }

    fclose(guardar);

    if (buit)
    {
        guardar=fopen(FITXER_JOC, "wb");

        if (num_jugadors==0)
        {
            fwrite(&num_jugadors, sizeof(int), 1, guardar);
            num_jugadors=1;
            maquina=true;
        }

        else
        {
            fwrite(&num_jugadors, sizeof(int), 1, guardar);
        }

        fwrite(&dim, sizeof(int), 1, guardar);

        for (i=0; i<num_jugadors; i++)
        {
            fwrite(&jugadors[i].tirs_resultat, sizeof(int), 1, guardar);
            fwrite(&jugadors[i].tirs_total, sizeof(int), 1, guardar);
            fwrite(&jugadors[i].vaixells_enfonsats, sizeof(int), 1, guardar);

            for (f=0; f<dim; f++)
            {
                for (c=0; c<dim; c++)
                {
                    fwrite(&jugadors[i].taulell_vaixells[f][c], sizeof(char), 1, guardar);
                }
            }


            for (f=0; f<dim; f++)
            {
                for (c=0; c<dim; c++)
                {
                    fwrite(&jugadors[i].taulell_resultat[f][c], sizeof(char), 1, guardar);
                }
            }
        }

        if (maquina)
        {
            num_jugadors=0;
        }

        fclose(guardar);
        printf("\nJoc emmagatzemat!\n\n");
    }

    return true;
}

/*
 funcio recupera_joc (nom_fitxer:taula de caracters, var dim, var num_jugadors:enter, var jugadors:taula de jugador_tipus) retorna boolea;
 */
bool recupera_joc (char nom_fitxer[], int *dim, int *num_jugadors, jugador_tipus records[])
{
    printf("\nProcediment recupera_joc...");

    FILE* recuperar;
    int f, c, i;
    bool buit, maquina;

    maquina=false;
    buit=false;
    recuperar=fopen(nom_fitxer, "rb");

    if (recuperar==NULL)
    {
        printf("\nError: No existeir el fitxer partida.bin");
    }

    else if (feof(recuperar))
    {
        printf("\nError: El fitxer partida.bin");
        buit=true;
    }

    else
    {
        fread(&*num_jugadors, sizeof(int), 1, recuperar);
        fread(&*dim, sizeof(int), 1, recuperar);

        if (*num_jugadors==0)
        {
            *num_jugadors=1;
            maquina=true;
        }

        for (i=0; i<*num_jugadors; i++)
        {
            fread(&records[i].tirs_resultat, sizeof(int), 1, recuperar);
            fread(&records[i].tirs_total, sizeof(int), 1, recuperar);
            fread(&records[i].vaixells_enfonsats, sizeof(int), 1, recuperar);

            for (f=0; f<*dim; f++)
            {
                for (c=0; c<*dim; c++)
                {
                    fread(&records[i].taulell_vaixells[f][c], sizeof(char), 1, recuperar);
                }
            }

            for (f=0; f<*dim; f++)
            {
                for (c=0; c<*dim; c++)
                {
                    fread(&records[i].taulell_resultat[f][c], sizeof(char), 1, recuperar);
                }
            }
        }
    }

    fclose(recuperar);

    for (i=0; i<*num_jugadors; i++)
    {
        printf("  R: %i ", records[i].tirs_resultat);
        printf(" T: %i ", records[i].tirs_total);
    }
    printf("\nRecuperat!\n\n");

    if (maquina)
    {
        *num_jugadors=0;
    }

    return true;     /*Retorna true per mostrar al MENÚ PRINCIPAL totes les opcions de joc*/
}

/*

 */
/*JUGAR UNA PARTIDA*/
void partida (bool carga, int dim, int num_jugadors, jugador_tipus jugadors[])
{
    bool final=false, fi=false;
    char comand='s', f='\0', f_ant = '\0', f_maquina='\0', f_ant_maquina='\0';
    int c=-1, f_aux=-1, c_aux=-1, acum=0, acum_ant=0, i, j, f_enter = 0, c_enter = 0, c_ant = 0, llarg=0, c_maquina=-1, f_aux_maquina=-1, c_aux_maquina=-1, acum_maquina=0, acum_ant_maquina=0, f_enter_maquina=0, c_enter_maquina=0, c_ant_maquina=0;

    if (carga==true)
    {
        printf( "\nJugar una partida...\n" );

        if (num_jugadors==0)
        {
            while(!final && jugadors[num_jugadors].vaixells_enfonsats<VAIXELLS_TOTAL)
            {
                imprimir_taulell(dim, jugadors[num_jugadors].taulell_resultat);

                comand=getchar();
                printf("Efectuar un tir [INTRO] / Sortir de la partida [S]: ");
                scanf("%c", &comand);

                if (comand>96)
                {
                    comand=comand-32;
                }

                switch (comand)
                {
                    case ('S'):
                        final=true;
                        break;

                    case ('\n'): f_ant=f; c_ant=c;  acum_ant=acum;

                        acum=0;
                        while (acum==0)
                        {
                            jugar(&f, &c, dim, jugadors[num_jugadors].taulell_resultat);
                            acum=dispara(f, c, jugadors[num_jugadors].taulell_vaixells);
                        }

                        printf("\n\nTir: %i %c\n", c, f);
                        /*printf("\nVaixells enfonsats: %i", jugadors[num_jugadors].vaixells_enfonsats);*/
                        jugadors[num_jugadors].tirs_total++;
                        jugadors[num_jugadors].tirs_resultat=jugadors[num_jugadors].tirs_resultat+acum;
                        c_enter=c-1;  f_enter=f-65;

                        switch (acum)
                    {
                        case (0): printf("Tir REPETIT\n");
                            break;

                        case (1): jugadors[num_jugadors].taulell_resultat[f_enter][c_enter]='.';
                            jugadors[num_jugadors].taulell_vaixells[f_enter][c_enter]='-';

                            if (acum_ant!=1)
                            {
                                f=f_ant;  c=c_ant;  acum=acum_ant;
                            }
                            break;

                        case (2): jugadors[num_jugadors].taulell_resultat[f_enter][c_enter]='X';
                            break;

                        case (3): fi=false;

                            jugadors[num_jugadors].taulell_resultat[f_enter][c_enter]='X';
                            jugadors[num_jugadors].vaixells_enfonsats++;

                            for (i=f_enter-1; i<f_enter+2 && !fi; i++)
                            {
                                for (j=c_enter-1; j<c_enter+2 && !fi; j++)
                                {
                                    if (i!=f_enter || j!=c_enter)
                                    {
                                        if (jugadors[num_jugadors].taulell_resultat[i][j]=='X')
                                        {
                                            f_aux=i; c_aux=j;

                                            if (f_aux==f_enter)
                                            {
                                                for (j=c_enter; !fi; j--)
                                                {
                                                    if (jugadors[num_jugadors].taulell_resultat[f_aux][j]=='X' && jugadors[num_jugadors].taulell_resultat[f_aux][j-1]!='X')
                                                    {
                                                        fi=true;
                                                    }
                                                }

                                                c_aux=j+1;
                                                fi=false;
                                                for (j=c_aux; j<c_aux+4 && !fi; j++)
                                                {
                                                    if (jugadors[num_jugadors].taulell_resultat[f_aux][j]=='X' && jugadors[num_jugadors].taulell_resultat[f_aux][j+1]!='X')
                                                    {
                                                        fi=true;
                                                    }
                                                }

                                                llarg=j-c_aux;

                                                for (i=f_aux-1; i<(f_aux+2); i++)
                                                {
                                                    for (j=c_aux-1; j<(llarg+1+c_aux); j++)
                                                    {
                                                        if (jugadors[num_jugadors].taulell_resultat[i][j]!='X')
                                                        {
                                                            jugadors[num_jugadors].taulell_resultat[i][j]='.';
                                                            jugadors[num_jugadors].taulell_vaixells[i][j]='-';
                                                        }
                                                    }
                                                }
                                            }

                                            else
                                            {
                                                for (i=f_enter; !fi; i--)
                                                {
                                                    if (jugadors[num_jugadors].taulell_resultat[i][c_aux]=='X' && jugadors[num_jugadors].taulell_resultat[i-1][c_aux]!='X')
                                                    {
                                                        fi=true;
                                                    }
                                                }

                                                f_aux=i+1;
                                                fi=false;
                                                for (i=f_aux; i<f_aux+4 && !fi; i++)
                                                {
                                                    if (jugadors[num_jugadors].taulell_resultat[i][c_aux]=='X' && jugadors[num_jugadors].taulell_resultat[i+1][c_aux]!='X')
                                                    {
                                                        fi=true;
                                                    }
                                                }

                                                llarg=i-f_aux;

                                                for (i=f_aux-1; i<(llarg+1+f_aux); i++)
                                                {
                                                    for (j=c_aux-1; j<(c_aux+2); j++)
                                                    {
                                                        if (jugadors[num_jugadors].taulell_resultat[i][j]!='X')
                                                        {
                                                            jugadors[num_jugadors].taulell_resultat[i][j]='.';
                                                            jugadors[num_jugadors].taulell_vaixells[i][j]='-';
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }

                            if (fi==false)
                            {
                                for (i=f_enter-1; i<f_enter+2; i++)
                                {
                                    for (j=c_enter-1; j<c_enter+2; j++)
                                    {
                                        if (i!=f_enter || j!=c_enter)
                                        {
                                            jugadors[num_jugadors].taulell_resultat[i][j]='.';
                                            jugadors[num_jugadors].taulell_vaixells[i][j]='-';
                                        }
                                    }
                                }
                            }

                            fi=false;
                            break;
                    }

                        break;

                    case ('M'):
                        imprimir_taulell (dim, jugadors[num_jugadors].taulell_vaixells);
                        break;
                }
            }
        }

        else
        {
            while(!final  && jugadors[num_jugadors].vaixells_enfonsats<VAIXELLS_TOTAL && jugadors[num_jugadors-1].vaixells_enfonsats<VAIXELLS_TOTAL)
            {
                imprimir_taulell(dim, jugadors[num_jugadors].taulell_vaixells);
                imprimir_taulell(dim, jugadors[num_jugadors].taulell_resultat);

                final=false;
                comand=getchar();
                printf("Efectuar un tir automatic [A] / Efectuar un tir manual [M] / Sortir de la partida [S]: ");
                scanf("%c", &comand);

                if (comand>96)
                {
                    comand=comand-32;
                }

                switch (comand)
                {
                    case ('S'):
                        final=true;
                        break;

                    case ('A'): f_ant=f; c_ant=c;  acum_ant=acum;

                        acum=0;
                        while (acum==0)
                        {
                            jugar(&f, &c, dim, jugadors[num_jugadors].taulell_resultat);
                            acum=dispara(f, c, jugadors[num_jugadors-1].taulell_vaixells);
                        }

                        printf("\n\nTir: %i %c\n", c, f);
                        jugadors[num_jugadors].tirs_total++;
                        jugadors[num_jugadors].tirs_resultat=jugadors[num_jugadors].tirs_resultat+acum;
                        c_enter=c-1;  f_enter=f-65;

                        break;

                    case ('M'):  f_ant=f; c_ant=c;  acum_ant=acum;
                        f=0; c=0; acum=0;

                        while ((f<65 || f>dim+64) || (c<1 || c>dim))
                        {
                            printf("Introdueix les coordenades fila-columna [1A]:");
                            scanf("%i", &c);
                            scanf("%c", &f);
                        }
                        acum=dispara(f, c, jugadors[num_jugadors-1].taulell_vaixells);


                        printf("\n\nTir: %i %c", c, f);
                        jugadors[num_jugadors].tirs_total++;
                        jugadors[num_jugadors].tirs_resultat=jugadors[num_jugadors].tirs_resultat+acum;
                        c_enter=c-1;  f_enter=f-65;

                        break;
                }

                switch (acum)
                {
                    case (0): printf("Tir REPETIT\n");
                        break;

                    case (1): jugadors[num_jugadors].taulell_resultat[f_enter][c_enter]='.';
                        jugadors[num_jugadors-1].taulell_vaixells[f_enter][c_enter]='-';

                        if (acum_ant!=1)
                        {
                            f=f_ant;  c=c_ant;  acum=acum_ant;
                        }
                        break;

                    case (2): jugadors[num_jugadors].taulell_resultat[f_enter][c_enter]='X';
                        break;

                    case (3): fi=false;

                        jugadors[num_jugadors].taulell_resultat[f_enter][c_enter]='X';
                        jugadors[num_jugadors].vaixells_enfonsats++;

                        for (i=f_enter-1; i<f_enter+2 && !fi; i++)
                        {
                            for (j=c_enter-1; j<c_enter+2 && !fi; j++)
                            {
                                if (i!=f_enter || j!=c_enter)
                                {
                                    if (jugadors[num_jugadors].taulell_resultat[i][j]=='X')
                                    {
                                        f_aux=i; c_aux=j;

                                        if (f_aux==f_enter)
                                        {
                                            for (j=c_enter; !fi; j--)
                                            {
                                                if (jugadors[num_jugadors].taulell_resultat[f_aux][j]=='X' && jugadors[num_jugadors].taulell_resultat[f_aux][j-1]!='X')
                                                {
                                                    fi=true;
                                                }
                                            }

                                            c_aux=j+1;
                                            fi=false;
                                            for (j=c_aux; j<c_aux+4 && !fi; j++)
                                            {
                                                if (jugadors[num_jugadors].taulell_resultat[f_aux][j]=='X' && jugadors[num_jugadors].taulell_resultat[f_aux][j+1]!='X')
                                                {
                                                    fi=true;
                                                }
                                            }

                                            llarg=j-c_aux;

                                            for (i=f_aux-1; i<(f_aux+2); i++)
                                            {
                                                for (j=c_aux-1; j<(llarg+1+c_aux); j++)
                                                {
                                                    if (jugadors[num_jugadors].taulell_resultat[i][j]!='X')
                                                    {
                                                        jugadors[num_jugadors].taulell_resultat[i][j]='.';
                                                        jugadors[num_jugadors-1].taulell_vaixells[i][j]='-';
                                                    }
                                                }
                                            }
                                        }

                                        else
                                        {
                                            for (i=f_enter; !fi; i--)
                                            {
                                                if (jugadors[num_jugadors].taulell_resultat[i][c_aux]=='X' && jugadors[num_jugadors].taulell_resultat[i-1][c_aux]!='X')
                                                {
                                                    fi=true;
                                                }
                                            }

                                            f_aux=i+1;
                                            fi=false;
                                            for (i=f_aux; i<f_aux+4 && !fi; i++)
                                            {
                                                if (jugadors[num_jugadors].taulell_resultat[i][c_aux]=='X' && jugadors[num_jugadors].taulell_resultat[i+1][c_aux]!='X')
                                                {
                                                    fi=true;
                                                }
                                            }

                                            llarg=i-f_aux;

                                            for (i=f_aux-1; i<(llarg+1+f_aux); i++)
                                            {
                                                for (j=c_aux-1; j<(c_aux+2); j++)
                                                {
                                                    if (jugadors[num_jugadors].taulell_resultat[i][j]!='X')
                                                    {
                                                        jugadors[num_jugadors].taulell_resultat[i][j]='.';
                                                        jugadors[num_jugadors-1].taulell_vaixells[i][j]='-';
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        if (fi==false)
                        {
                            for (i=f_enter-1; i<f_enter+2; i++)
                            {
                                for (j=c_enter-1; j<c_enter+2; j++)
                                {
                                    if (i!=f_enter || j!=c_enter)
                                    {
                                        jugadors[num_jugadors].taulell_resultat[i][j]='.';
                                        jugadors[num_jugadors-1].taulell_vaixells[i][j]='-';
                                    }
                                }
                            }
                        }

                        fi=false;
                        break;
                }

                f_ant_maquina=f_maquina; c_ant_maquina=c_maquina;  acum_ant_maquina=acum_maquina;

                acum_maquina=0;
                while (acum_maquina==0)
                {
                    jugar(&f_maquina, &c_maquina, dim, jugadors[num_jugadors-1].taulell_resultat);
                    acum_maquina=dispara(f_maquina, c_maquina, jugadors[num_jugadors].taulell_vaixells);
                }

                printf("\n\nMaquina: %i %c\n", c_maquina, f_maquina);
                /*printf("\nVaixells enfonsats: %i", jugadors[num_jugadors].vaixells_enfonsats);*/
                jugadors[num_jugadors-1].tirs_total++;
                jugadors[num_jugadors-1].tirs_resultat=jugadors[num_jugadors-1].tirs_resultat+acum_maquina;
                c_enter_maquina=c_maquina-1;  f_enter_maquina=f_maquina-65;

                switch (acum_maquina)
                {
                    case (1): jugadors[num_jugadors-1].taulell_resultat[f_enter_maquina][c_enter_maquina]='.';
                        jugadors[num_jugadors].taulell_vaixells[f_enter_maquina][c_enter_maquina]='-';

                        if (acum_ant_maquina!=1)
                        {
                            f_maquina=f_ant_maquina;  c=c_ant_maquina;  acum_maquina=acum_ant_maquina;
                        }
                        break;

                    case (2): jugadors[num_jugadors-1].taulell_resultat[f_enter_maquina][c_enter_maquina]='X';
                        break;

                    case (3): fi=false;

                        jugadors[num_jugadors-1].taulell_resultat[f_enter_maquina][c_enter_maquina]='X';
                        jugadors[num_jugadors-1].vaixells_enfonsats++;

                        for (i=f_enter_maquina-1; i<f_enter_maquina+2 && !fi; i++)
                        {
                            for (j=c_enter_maquina-1; j<c_enter_maquina+2 && !fi; j++)
                            {
                                if (i!=f_enter_maquina || j!=c_enter_maquina)
                                {
                                    if (jugadors[num_jugadors-1].taulell_resultat[i][j]=='X')
                                    {
                                        f_aux_maquina=i; c_aux_maquina=j;

                                        if (f_aux_maquina==f_enter_maquina)
                                        {
                                            for (j=c_enter_maquina; !fi; j--)
                                            {
                                                if (jugadors[num_jugadors-1].taulell_resultat[f_aux_maquina][j]=='X' && jugadors[num_jugadors-1].taulell_resultat[f_aux_maquina][j-1]!='X')
                                                {
                                                    fi=true;
                                                }
                                            }

                                            c_aux_maquina=j+1;
                                            fi=false;
                                            for (j=c_aux_maquina; j<c_aux_maquina+4 && !fi; j++)
                                            {
                                                if (jugadors[num_jugadors-1].taulell_resultat[f_aux_maquina][j]=='X' && jugadors[num_jugadors-1].taulell_resultat[f_aux_maquina][j+1]!='X')
                                                {
                                                    fi=true;
                                                }
                                            }

                                            llarg=j-c_aux_maquina;

                                            for (i=f_aux_maquina-1; i<(f_aux_maquina+2); i++)
                                            {
                                                for (j=c_aux_maquina-1; j<(llarg+1+c_aux_maquina); j++)
                                                {
                                                    if (jugadors[num_jugadors-1].taulell_resultat[i][j]!='X')
                                                    {
                                                        jugadors[num_jugadors-1].taulell_resultat[i][j]='.';
                                                        jugadors[num_jugadors].taulell_vaixells[i][j]='-';
                                                    }
                                                }
                                            }
                                        }

                                        else
                                        {
                                            for (i=f_enter_maquina; !fi; i--)
                                            {
                                                if (jugadors[num_jugadors-1].taulell_resultat[i][c_aux_maquina]=='X' && jugadors[num_jugadors-1].taulell_resultat[i-1][c_aux_maquina]!='X')
                                                {
                                                    fi=true;
                                                }
                                            }

                                            f_aux_maquina=i+1;
                                            fi=false;
                                            for (i=f_aux_maquina; i<f_aux_maquina+4 && !fi; i++)
                                            {
                                                if (jugadors[num_jugadors-1].taulell_resultat[i][c_aux_maquina]=='X' && jugadors[num_jugadors-1].taulell_resultat[i+1][c_aux_maquina]!='X')
                                                {
                                                    fi=true;
                                                }
                                            }

                                            llarg=i-f_aux_maquina;

                                            for (i=f_aux_maquina-1; i<(llarg+1+f_aux_maquina); i++)
                                            {
                                                for (j=c_aux_maquina-1; j<(c_aux_maquina+2); j++)
                                                {
                                                    if (jugadors[num_jugadors-1].taulell_resultat[i][j]!='X')
                                                    {
                                                        jugadors[num_jugadors-1].taulell_resultat[i][j]='.';
                                                        jugadors[num_jugadors].taulell_vaixells[i][j]='-';
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        if (fi==false)
                        {
                            for (i=f_enter_maquina-1; i<f_enter_maquina+2; i++)
                            {
                                for (j=c_enter_maquina-1; j<c_enter_maquina+2; j++)
                                {
                                    if (i!=f_enter_maquina || j!=c_enter_maquina)
                                    {
                                        jugadors[num_jugadors-1].taulell_resultat[i][j]='.';
                                        jugadors[num_jugadors].taulell_vaixells[i][j]='-';
                                    }
                                }
                            }
                        }

                        fi=false;
                        break;
                }

            }

            if (jugadors[1].vaixells_enfonsats==10)
            {
                printf("\nHAS GUANYAT!!");
            }
            else
            {
                printf("\nHAS PERDUT");
            }
        }

        printf("\nFI DE JOC\n");
    }

    else
    {
        printf( "\nNo es pot jugar la partida\n" );
    }
}

/** NIVEL 3 */
/*
 accio inicia_elmeu_taulell (dim:enter, taulell_vaixells:taula de caracters) ;
 */
void inicia_elmeu_taulell (int dim, char taulell_vaixells[][DIM_MAX])
{
    int error=0, numero, tipus_vaixell;;
    char Yaux;
    coor_tipus vaixell;
    bool corr, fi;

    printf("\nIMPORTANT: Els vaixells es colocaran de Esquerra a Dreta, o de Dalt a Baix.\nSi una coordenada es troba fora dels limits del taulell, es demanara de nou aquesta fins que sigui correcte.\n");

    for (tipus_vaixell=4; tipus_vaixell>0; tipus_vaixell--)
    {
        for (numero=5-tipus_vaixell; numero>0; numero--)
        {
            printf("\nVaixell n%i de (%i caselles):", numero, tipus_vaixell);
            fi=false;

            while (!fi)
            {
                corr=true;

                vaixell.x=-1;
                while (vaixell.x<=0 || vaixell.x>dim)
                {
                    printf("\nPosicio del vaixell en coordenada X [Del 1 al %i]: ", dim);
                    scanf("%i", &vaixell.x);
                }

                Yaux='.';
                while (Yaux<65 || Yaux>dim+64)
                {
                    printf("Posicio del vaixell en coordenada Y [De la A a la %c]: ", dim+64);
                    Yaux=getchar();
                    scanf("%c", &Yaux);
                }
                vaixell.y=Yaux-64;

                if(tipus_vaixell!=1)
                {
                    vaixell.orientacio=-1;
                    while (vaixell.orientacio<0 || vaixell.orientacio>1)
                    {
                        printf("Orientacio del vaixell [0=horitzontal, 1=vertical]: ");
                        scanf("%i", &vaixell.orientacio);
                    }
                }

                fi=verificacio_posicio(dim, taulell_vaixells, tipus_vaixell, vaixell, &error);

                switch (error)
                {
                    case 0:   printf("\nVaixell guardat");
                        break;
                    case 1:   printf("\nError %i: Es creua o no respecta el espai.\nRecorda deixar 1 casella de separacio, torna a introduir coordenades.", error);
                        break;
                    case 2:   printf("\nError %i: El vaixell surt dels limits dels limits del taulell.\nRecorda que els vaixells van de esquerra a dreta i de dalt a baix, torna a introduir coordenades.", error);
                        break;
                }

                imprimir_taulell(dim, taulell_vaixells);
            }
        }
    }
}
