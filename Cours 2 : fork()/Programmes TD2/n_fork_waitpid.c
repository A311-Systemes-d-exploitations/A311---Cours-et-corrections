/*
 *  Exercice 3 TP2 basé sur la diapositive 15 du Cours 2
 *
 * n_fork_waitpid.c :
 *
 * version : 06/10/2016
 * auteur  : ms
 * 
 * plusieurs versions de code possibles : positionner la variable
 * CHOIX à TABPID, NBFILS ou WAIT avant de compiler avec
 * make. Exemple:
 *
 * $ make mrproper ; make -e CHOIX=TABPID
 *
 * $ ./n_fork_waitpid 10
 * Je suis le fils 1 (7678) du père 7676
 * Je suis le fils 0 (7677) du père 7676
 * Je suis le fils 2 (7679) du père 7676
 * Je suis le fils 4 (7681) du père 7676
 * [1] Le fils (7678) a terminé avec le code de retour 1
 * [1] Le fils (7679) a terminé avec le code de retour 2
 * Je suis le fils 5 (7682) du père 7676
 * ...
 *
 */



#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <assert.h>

#define MAXFILS 128

int main (int argc, char * argv[]) {
    pid_t pid;
#ifdef TABPID
    pid_t tabpid[MAXFILS];
#endif
    assert(argc==2);
    int NB_FILS = atoi(argv[1]);

    assert(NB_FILS <= MAXFILS);
    
    for (int fils = 0; fils < NB_FILS; fils ++) {
	if ((pid = fork()) < 0) {
	    perror("fork");
	    exit(EXIT_FAILURE);
	}
	if (pid != 0){
#ifdef TABPID
	    tabpid[fils]=pid;
#endif
	    continue;
	} else {
	    printf("Je suis le fils %d (%d) du père %d\n", fils, getpid(), getppid());
	    //exit(EXIT_SUCCESS);
	    exit(fils); // juste pour jouer avec le code retour
	}
    }


    int w, retour;
/*
 * Méthode 1 : on attend les processus dans l'ordre de leur création
 * car on a sauvegardé leur pid
 */

#if defined(TABPID)

    for (int i = 0; i < NB_FILS; i ++) {
    	if ((w = waitpid(tabpid[i], &retour, 0)) > 0 )
    	    printf("[1] Le fils %d (%d) a terminé avec le code de retour %d et %d\n", i, tabpid[i], WEXITSTATUS(retour), w);
    }

#elif defined(NBFILS)
    
/*
 * Méthode 2 : on attend NB_FILS processus dans l'ordre de leur
 * terminaison
 */
    for (int i = 0; i < NB_FILS; i ++) {
    	if ((w = waitpid(-1, &retour, 0)) > 0)	/* The call wait(&status) is equivalent to:
						   waitpid(-1, &status, 0); */
    	    printf("[2] Le fils (%d) a terminé avec le code de retour %d\n", w, WEXITSTATUS(retour));
    }

#else

/*
 * Méthode 3 : on attend tous les processus qui terminent
 */

    while ((w = wait(&retour))>0){
	    printf("[3] Le fils (%d) a terminé avec le code de retour %d\n", w, WEXITSTATUS(retour)); 
    }

#endif

    exit(EXIT_SUCCESS);
}
/*
$ make mrproper ; make -e CHOIX=TABPID
$ ./n_fork_waitpid 10
Je suis le fils 0 (15958) du père 15957
Je suis le fils 1 (15959) du père 15957
Je suis le fils 2 (15960) du père 15957
Je suis le fils 5 (15963) du père 15957
Je suis le fils 4 (15962) du père 15957
Je suis le fils 6 (15964) du père 15957
[1] Le fils 0 (15958) a terminé avec le code de retour 0 et 15958
[1] Le fils 1 (15959) a terminé avec le code de retour 1 et 15959
[1] Le fils 2 (15960) a terminé avec le code de retour 2 et 15960
Je suis le fils 8 (15966) du père 15957
Je suis le fils 7 (15965) du père 15957
Je suis le fils 3 (15961) du père 15957
Je suis le fils 9 (15967) du père 15957
[1] Le fils 3 (15961) a terminé avec le code de retour 3 et 15961
[1] Le fils 4 (15962) a terminé avec le code de retour 4 et 15962
[1] Le fils 5 (15963) a terminé avec le code de retour 5 et 15963
[1] Le fils 6 (15964) a terminé avec le code de retour 6 et 15964
[1] Le fils 7 (15965) a terminé avec le code de retour 7 et 15965
[1] Le fils 8 (15966) a terminé avec le code de retour 8 et 15966
[1] Le fils 9 (15967) a terminé avec le code de retour 9 et 15967
$
$ make mrproper ; make -e CHOIX=NBFILS
$ ./n_fork_waitpid 10
Je suis le fils 1 (16027) du père 16025
Je suis le fils 0 (16026) du père 16025
Je suis le fils 2 (16028) du père 16025
Je suis le fils 4 (16030) du père 16025
Je suis le fils 5 (16031) du père 16025
Je suis le fils 8 (16034) du père 16025
[2] Le fils (16027) a terminé avec le code de retour 1
[2] Le fils (16026) a terminé avec le code de retour 0
[2] Le fils (16028) a terminé avec le code de retour 2
[2] Le fils (16030) a terminé avec le code de retour 4
Je suis le fils 7 (16033) du père 16025
Je suis le fils 3 (16029) du père 16025
Je suis le fils 9 (16035) du père 16025
Je suis le fils 6 (16032) du père 16025
[2] Le fils (16029) a terminé avec le code de retour 3
[2] Le fils (16031) a terminé avec le code de retour 5
[2] Le fils (16033) a terminé avec le code de retour 7
[2] Le fils (16034) a terminé avec le code de retour 8
[2] Le fils (16035) a terminé avec le code de retour 9
[2] Le fils (16032) a terminé avec le code de retour 6
$
$ make mrproper ; make -e CHOIX=WAIT
$ ./n_fork_waitpid 10
Je suis le fils 0 (16094) du père 16093
Je suis le fils 1 (16095) du père 16093
Je suis le fils 2 (16096) du père 16093
Je suis le fils 5 (16099) du père 16093
Je suis le fils 4 (16098) du père 16093
Je suis le fils 6 (16100) du père 16093
Je suis le fils 3 (16097) du père 16093
Je suis le fils 7 (16101) du père 16093
Je suis le fils 8 (16102) du père 16093
[3] Le fils (16094) a terminé avec le code de retour 0
[3] Le fils (16095) a terminé avec le code de retour 1
[3] Le fils (16096) a terminé avec le code de retour 2
[3] Le fils (16097) a terminé avec le code de retour 3
[3] Le fils (16098) a terminé avec le code de retour 4
[3] Le fils (16099) a terminé avec le code de retour 5
[3] Le fils (16100) a terminé avec le code de retour 6
[3] Le fils (16101) a terminé avec le code de retour 7
[3] Le fils (16102) a terminé avec le code de retour 8
Je suis le fils 9 (16103) du père 16093
[3] Le fils (16103) a terminé avec le code de retour 9
$
*/
