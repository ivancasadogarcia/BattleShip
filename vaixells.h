/*----------------------------------------------------------------
 |	Autor: Ivan Casado Garcia
 |  e-mail: ivan.casado@estudiants.urv.cat
 |	Data: Gener 2016                 Versio: 2.8
 |-----------------------------------------------------------------|
 |	Nom projecte: Vaixells
 |	Nom: funcions.h
 |  Descripcio del Programa:   Cap de procediments donats.
 | ----------------------------------------------------------------*/

#ifndef VAIXELLS_H_INCLUDED
#define VAIXELLS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#include "tipus.h"

#define DIM_MAX     10
#define DIM_MIN     8

enum orientacio
{
    HORITZONTAL = 0,
    VERTICAL = 1
};

enum casella
{
    CASELLA_BUIDA = '?',
    CASELLA_AIGUA = '.',
    CASELLA_VAIXELL = '@',
    CASELLA_VAIXELL_TOCAT = 'X',
    CASELLA_AIGUA_TOCADA = '-'
};

enum tret
{
    ERROR = -1,
    REPETIT = 0,
    AIGUA = 1,
    TOCAT = 2,
    ENFONSAT = 3
};

/** cap procediments */
/** =========================================================================
 accio inicia_taulell (dim:enter, var taulell_vaixells:taula de caracters);

 - Inicialitza la disposicio dels vaixells dins del taulell de vaixells.

 - Parametres formals:
 dim: (per valor) dimensiÛ del taulell, ha de ser > DIM_MIN i < DIM_MAX.
 Abans de fer la crida, s'ha de validar que dim sigui correcte.
 taulell_vaixells: (per referËncia) taula de dues dimensions
 DIM_MAX x DIM_MAX. La mida del taulell real dependr‡ del
 parametre dim: dim x dim.
 =========================================================================*/
extern void inicia_taulell (int dim, char taulell_vaixells[][DIM_MAX]);

/** =========================================================================
 accio inicia_taulell_fix(dim:enter,var taulell_vaixells:taula de caracter);

 - Inicialitza la disposicio dels vaixells dins del taulell de vaixells
 sempre amb la mateixa configuracio. Serveix per a fer proves.

 - Parametres formals:
 dim: (per valor) dimensio del taulell, ha de ser > 8 i < DIM_MAX.
 Abans de fer la crida, s'ha de validar que dim sigui correcte.
 taulell_vaixells: (per referËncia) taula de dues dimensions
 DIM_MAX x DIM_MAX. La mida del taulell real dependra del
 parametre dim: dim x dim.
 =========================================================================*/
extern void inicia_taulell_fix (int dim, char taulell_vaixells[][DIM_MAX]);

/** =========================================================================
 funcio dispara (f:car‡cter, c:enter, var taulell_vaixells:taula de caracters)
 retorna enter;

 - Retorna el resultat del llanÁament (REPETIT-0, AIGUA-1...) i
 actualitza el taulell de vaixells amb les anotacions pertinents:
 CASELLA_VAIXELL_TOCAT o CASELLA_AIGUA_TOCADA.
 Si hi ha un error en la fila o columna, o en el contingut de la casella,
 retorna ERROR.

 - Parametres formals:
 fila: (per valor) lletra de la fila, en majuscules. Ha de ser
 correcta d'acord amb les dimensions del taulell.
 col: (per valor) n˙mero de la columna, ha de ser correcte d'acord
 amb les dimensions del taulell.
 Abans de fer la crida, s'ha de validar que fila i col siguin correctes!
 taulell_vaixells: (per referencia) taula de dues dimensions
 DIM_MAX x DIM_MAX.
 =========================================================================*/
extern int dispara (char fila, int col, char t[][DIM_MAX]);

#endif /* VAIXELLS_H_INCLUDED */
