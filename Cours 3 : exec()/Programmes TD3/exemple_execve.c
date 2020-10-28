/*
 * Exercice 1 TP3 basé sur la diapositive 6 de Cours_EXEC.pdf
 *
 * exemple_execve.c :
 *
 * version : 03/10/2017
 * auteur  : version originale Christophe Blaess
 *
 * Programme d'exemple du livre "Developpement systeme en C sous Linux"
 * (c) 2000,2005 - Christophe Blaess
 *
 * Livre disponible à la BU Fabron
 * 
 */

// voir aussi https://linuxfr.org/forums/programmation-c--2/posts/environnement-non-transmis-par-variable-environ
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

extern char ** environ;	

int main (void){
    char * argv[] = {"bash", "-c", "echo $SHLVL", (char *) NULL };
    
    fprintf(stdout, "Je lance encore /bin/bash -c \"echo $SHLVL\" :\n");
    
    execve("/bin/bash", argv, environ); 
    // équivalent à lancer dans le shell

    // $ bash -c "echo $SHLVL"

    // -c pour exécuter la commande contenue dans la chaîne suivante
    // ,(et non dans un fichier ou depuis stdin), puis terminer
    
    fprintf(stdout, "Raté : erreur = %d\n", errno);

    return EXIT_SUCCESS;
}
/*
$ echo $SHLVL
2
$ bash -c "echo $SHLVL"
2
$ ./exemple_execve
Je lançe encore /bin/bash -c "echo $SHLVL" :
3
$ bash
$ ./exemple_execve
Je lançe encore /bin/bash -c "echo $SHLVL" :
4
$ bash -c "echo $SHLVL"
3
$ exit
exit
$ echo $SHLVL
2
$ 
exec incrémente le niveau de Shell, pas bash -c
*/
