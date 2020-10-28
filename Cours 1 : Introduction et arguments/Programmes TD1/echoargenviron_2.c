/*
 * Diapositive 24 du Cours_INTRO
 *
 *
 * exemple_environ_2.c : affiche toutes les valeurs des variables de
 * l'environnement (comme la commande shell env) en utilisant un
 * troisième argument de la fonction main()
 *
 * version : 26/09/2019
 * auteur  : Blaess / ms (Programme d'exemple tiré du livre "Développement système en C sous Linux")
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[], char * envp[]){
    
    for (int i = 0; envp[i] != NULL; i ++){
		fprintf(stdout, "%d : %s\n", i, envp[i]);
    }
    
    return EXIT_SUCCESS;
}
