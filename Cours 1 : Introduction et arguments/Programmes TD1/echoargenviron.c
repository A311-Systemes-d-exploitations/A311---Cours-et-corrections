/*
 * Diapositive 23 du Cours_INTRO
 *
 *
 * echoargenviron.c : affiche tous les arguments ainsi que les valeurs
 * des variables de l'environnement (comme la commande shell env)
 *
 * version : 26/09/2019
 * auteur  : Stevens APUE / ms
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    char **ptr;
    extern char **environ; 
    
    for (int i = 0; i < argc; i++) { /* echo all command-line args */
		printf("argv[%d]: %s\n", i, argv[i]);
    }
    
    for (ptr = environ; *ptr != 0; ptr++) { /* and all env strings */
		printf("%s\n", *ptr);
    }
    
    exit(EXIT_SUCCESS);
}
