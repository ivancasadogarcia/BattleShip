/*----------------------------------------------------------------
 |	Autor: Ivan Casado Garcia
 |  e-mail: ivan.casado@estudiants.urv.cat
 |	Data: Gener 2016                 Versio: 2.8
 |-----------------------------------------------------------------|
 |	Nom projecte: Vaixells
 |	Nom: funcions.h
 |  Descripcio del Programa:   Declaracio de les capçaleres.
 | ----------------------------------------------------------------*/

#ifndef FUNCIONS_H_INCLUDED
#define FUNCIONS_H_INCLUDED
#include "tipus.h"

/* Cap dels procediments */
/** -------------------------------------------------------
 NIVEL 1
 ------------------------------------------------------- */
/*
 .
 */
extern int num_aleatori (int max, int min);

/*
 .
 */
extern void imprimir_taulell (int dim, char t[][DIM_MAX]);             /*Funció per mostrar per pantalla la matriu*/

/*
 .
 */
void inici_taulell_resultats (int dim, char taulell_resultats[][DIM_MAX]);     /*Inicialitza la matriu dels llançaments amb '?'*/

/*
 .
 */
void inici_taulell_vaixells (int dim, char taulell_vaixells[][DIM_MAX]);       /*Inicialitza la matriu dels vaixells amb '.'*/

/*
 accio jugar (var f:caracter, var c:enter, dim:enter, taulell_llancament:taula de caracters);
 */
extern void jugar (char *f, int *c, int dim, char taula[][DIM_MAX]);

/*
 .
 */
extern void imprimir_records_pantalla(record_tipus t[], int *num_records); /*Mostrar els record del fitxer per pantalla*/

/*
 funcio verificacio_posicio (var f:caracter, var c:enter, dim:enter, taulell_llancament:taula de caracters);
 */
extern bool verificacio_posicio (int dim, char taulell_vaixells[][DIM_MAX], int v, coor_tipus vaixell, int *error);
/*Realitza la comprovació de les posicions dels vaixells per evitar errors de incumpliment de les normes de joc*/

/*
 funcio emmagatzema_records (fitxer_record:taula de caracters, var num_records:enter, records:taula de record_tipus) retorna boolea.
 */
extern bool emmagatzema_records (char fitxer_record[], int num_records, record_tipus records[]);

/*
 funcio recupera_records (fitxer_record:taula de caracters, var num_records:enter, records:taula de record_tipus) retorna boolea.
 */
extern bool recupera_records (char fitxer_record[], int *num_records, record_tipus records[]);

/*

 */
extern void partida (bool carga, int dim, int num_jugadors, jugador_tipus jugadors[]);

/** -------------------------------------------------------
 NIVEL 2
 ------------------------------------------------------- */
/*
 funcio emmagatzema_joc (nom_fitxer:taula de caracters, dim, num_jugadors: enter, jugadors:taula de jugador_tipus) retorna boolea;
 */
extern bool emmagatzema_joc (char nom_fitxer[], int dim, int num_jugadors, jugador_tipus jugadors[]);

/*
 funcio recupera_joc (nom_fitxer:taula de caracters, var dim, var num_jugadors: enter, var jugadors:taula de jugador_tipus) retorna boolea;
 */
extern bool recupera_joc (char nom_fitxer[], int *dim, int *num_jugadors, jugador_tipus jugadors[]);

/** -------------------------------------------------------
 NIVEL 3
 ------------------------------------------------------- */
/*
 accio inicia_elmeu_taulell (dim:enter, taulell_vaixells:taula de caracters);
 */
extern void inicia_elmeu_taulell (int dim, char taulell_vaixells[][DIM_MAX]);

#endif /* FUNCIONS_H_INCLUDED */
