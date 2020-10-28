/*
 * Diapositive 21 de Cours_INTRO
 *
 * echoargenv.c : affiche un à un les arguments de la ligne de
 * commande si l'argument est le nom d'une variable d'environnement,
 * alors on affiche sa valeur.
 *
 * version : 26/09/2019
 * auteur  : ms
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){
    //printf("argc = %d\n", argc);
    for (int i = 1; i < argc; i++){
		printf ("argument %d: %s\n", i, argv[i]);
		printf ("\n%s\n\n", getenv (argv[i]));
    }
    return EXIT_SUCCESS;
}
