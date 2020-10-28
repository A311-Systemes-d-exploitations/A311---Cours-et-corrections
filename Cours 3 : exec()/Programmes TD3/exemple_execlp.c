
/*
 * Exercice 1 TP3 basé sur la diapositive 7 de Cours_EXEC.pdf
 *
 * exemple_execlp.c :
 *
 * version : 17/10/2016
 * auteur  : version originale Christophe Blaess
 *
 * Programme d'exemple du livre "Developpement systeme en C sous Linux"
 * (c) 2000,2005 - Christophe Blaess
 *
 * Livre disponible à la BU Fabron
 * 
 */

 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main (int argc, char * argv []){
    char compteur[2];

    // valeur initiale du compteur passé en argument de la ligne de
    // commande, 0 par défaut.
    int i = 0;
    if (argc == 2)
	// à la place de
	// i = atoi(argv[1]);
	sscanf(argv[1], "%d", & i);
    
    if (i < 5) {
	i ++;
	sprintf(compteur, "%d", i);
	
	fprintf(stdout, "execlp(%s, %s, %s, NULL) [%d]\n", 
		argv[0], argv[0], compteur, getpid());
	// execlp prend en premier argument le nom de la commande qui
	// sera recherchée dans le PATH, puis une liste d'arguments
	// terminée par un pointeur NULL
	execlp(argv[0], argv[0], compteur, (char *) NULL);
    }
    
    return EXIT_SUCCESS;
}
/*
$ ./exemple_execlp 2
execlp(./exemple_execlp, ./exemple_execlp, 3, NULL) [10519]
execlp(./exemple_execlp, ./exemple_execlp, 4, NULL) [10519]
execlp(./exemple_execlp, ./exemple_execlp, 5, NULL) [10519]
$
Dans cet exemple i est initialisé à 2, on incrément et passe sa valeur
3 fois à execlp qui écrase à chaque fois le code du processus 10519:
c'est un appel récursif de processus!
*/
