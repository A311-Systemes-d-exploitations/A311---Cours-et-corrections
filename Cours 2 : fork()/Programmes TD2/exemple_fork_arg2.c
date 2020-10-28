/*
 * Exercice 2 TP2
 *
 * exemple_fork_arg2.c : affichage des informations pid, ppid depuis le
 * père et le fils avec un wait pour éviter le problème de zombie.
 *
 * Le père affiche argv[1] et le fils affiche argv[2]
 * 
 * version : 18/10/2018
 * auteur  : ms
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <assert.h>

int main(int argc, char *argv[]) {

    assert(argc == 3);

    pid_t pid_fils = fork();
    if (pid_fils == -1) {
	fprintf(stderr, "fork() impossible, errno=%d\n", errno);
	return EXIT_FAILURE;
    }
    if (pid_fils == 0) {
	/* processus fils */
	fprintf(stdout, "Fils : %s\n", argv[2]);
	fprintf(stdout, "Fils : PID=%ld, PPID=%ld\n", 
		(long) getpid(), (long) getppid());
	sleep(1); // sinon le fils peut terminer avant le début du père
	return EXIT_SUCCESS;
	
    } else { // pid_fils contient le PID du processus créé par fork()
	/* processus père */
	fprintf(stdout, "Père : %s\n", argv[1]);
	fprintf(stdout, "Père : PID=%ld, PPID=%ld, PID fils=%ld\n",
		(long) getpid(), (long) getppid(), (long) pid_fils);
	wait(NULL); // on attend le premier fils qui termine
	return EXIT_SUCCESS;
    }
}
/*
$ ./exemple_fork_arg2 "message du père" "message du fils"
Père : message du père
Père : PID=15595, PPID=15393, PID fils=15596
Fils : message du fils
Fils : PID=15596, PPID=15595
$
*/
