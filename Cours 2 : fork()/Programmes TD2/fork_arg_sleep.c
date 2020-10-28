/*
 * Exercice 1 fork() TP2
 *
 * fork_arg_sleep.c : ce programme illustre le mécanisme de
 * duplication d'images sous UNIX avec le problème de zombie
 *
 * version : 18/10/2018
 * auteur  : ms
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <assert.h>

int main(int argc, char* argv[]){
    assert(argc==3);

    int res = fork();
    if (res == 0) // fils
		sleep(atoi(argv[1]));
    else  // père
		sleep(atoi(argv[2]));
	printf("Résultat : %d, %d, %d\n", res, getpid(), getppid());
    return EXIT_SUCCESS;
}

