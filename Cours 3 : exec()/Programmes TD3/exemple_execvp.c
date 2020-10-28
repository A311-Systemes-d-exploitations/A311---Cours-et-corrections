/*
 * Exercice 1 TP3 basé sur la diapositive 4 de Cours_EXEC.pdf
 *
 * exemple_execvp.c :
 *
 * auteur  : version originale Christophe Blaess
 *
 * Programme d'exemple du livre "Developpement systeme en C sous Linux"
 * (c) 2000,2005 - Christophe Blaess
 *
 * Livre disponible à la BU Fabron
 *
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main (void) {
    char * argv[] = { "nimportequoi", "-l", "-i", (char *) NULL };
    //char * argv[] = { "-l", "-i", (char *) NULL };

    // ls est bien exécutée mais seule l'option -i est prise en compte
    // car argv[0] est réservé pour le nom de la commande
    // plus d'informations sur :
    // https://stackoverflow.com/questions/2050961/is-argv0-name-of-executable-an-accepted-standard-or-just-a-common-conventi
    // https://unix.stackexchange.com/questions/315812/why-does-argv-include-the-program-name

    execvp("ls", argv);

    // si l'appel à exec réussit, alors la suite de ce programme
    // n'existe pas car le code du processus est remplacé par celui de
    // la commande ls

    // sinon, on affiche le message d'erreur correspondant.
    
    fprintf(stderr, "Erreur %d\n", errno);
    return EXIT_FAILURE;
}


