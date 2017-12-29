/*----------------------------------------------------------------
 |	Autor: Ivan Casado Garcia
 |  e-mail: ivan.casado@estudiants.urv.cat
 |	Data: Gener 2016                 Versio: 2.8
 |-----------------------------------------------------------------|
 |	Nom projecte: Vaixells
 |	Nom: tipus.h
 |  Descripcio del Programa:   Declaracio dels registres i altre variables.
 | ----------------------------------------------------------------*/

#ifndef TIPUS_H_INCLUDED
#define TIPUS_H_INCLUDED

/* Definicio de constants del projecte*/
#define DIM_MAX         10
#define MAX_RECORDS     10      /* Doneu un valor a la constant */
#define CARACTERS_MAX   8
#define VAIXELLS_TOTAL  10
#define DIM             25
#define FITXER_RECORDS   "records.txt"
#define FITXER_JOC       "partida.bin"

/* Definicio de nous tipus del projecte*/
/** -------------------------------------------------------
 NIVEL 1
 ------------------------------------------------------- */

typedef struct
{
    double pun;
} record_tbase;

typedef struct     /*Registre per simplificar el record*/
{
    double pun;
    char nom[CARACTERS_MAX];
    record_tbase nou;
} record_tipus;

/** -------------------------------------------------------
 NIVEL 2
 ------------------------------------------------------- */
typedef struct     /*Registre per simplificar les posicions dels vaixells*/
{
    int x, y, orientacio;
} coor_tipus;

typedef struct     /*Registre per diferenciar taules entre diferents jugadors*/
{
    char taulell_vaixells[DIM_MAX][DIM_MAX], taulell_resultat[DIM_MAX][DIM_MAX];
    int tirs_total, tirs_resultat, vaixells_enfonsats;
} jugador_tipus;

#endif /* TIPUS_H_INCLUDED */
