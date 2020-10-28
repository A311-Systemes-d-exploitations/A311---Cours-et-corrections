/*
 * Diapositive 9 Cours 2 
 *
 * exemple_fork.c : affichage des informations pid, ppid depuis le
 * père et le fils avec un wait pour éviter le problème de zombie
 * 
 * version : 19/10/2018
 * auteur  : ms
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>


int main(void) {
    pid_t pid_fils = fork();
    
    if (pid_fils == -1) {
	fprintf(stderr, "fork() impossible, errno=%d\n", errno);
	return EXIT_FAILURE;
    }
    if (pid_fils == 0) {
	/* processus fils */
	fprintf(stdout, "Fils : PID=%ld, PPID=%ld\n", 
		(long) getpid(), (long) getppid());
	sleep(5); // sinon le fils peut terminer avant le début du père
	return EXIT_SUCCESS;
	
    } else { // pid_fils contient le PID du processus créé par fork()
	/* processus père */
	fprintf(stdout, "Père : PID=%ld, PPID=%ld, PID fils=%ld\n",
		(long) getpid(), (long) getppid(), (long) pid_fils);
	wait(NULL); // on attend le premier fils qui termine
	return EXIT_SUCCESS;
    }
}
