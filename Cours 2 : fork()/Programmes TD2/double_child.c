/*
 * Diapositives 12 et 13 Cours 2
 * fork_waitpid
 * APUE
 * version : 18/10/2018
 * auteur  : ms
 */
/*
 bash-3.1$ gcc fork2.c -o fork2
 bash-3.1$ ./fork2
 Parent from second fork, pid = 1868
 Parent, pid = 1719
 bash-3.1$ second child, parent pid = 1
 bash-3.1$
 */
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h> /* exit */

int main(void) {
    pid_t pid;
    
    if ((pid = fork()) < 0)
	fprintf(stderr, "fork error");
    else if (pid == 0) { /* first child */
	if ((pid = fork()) < 0)
	    fprintf(stderr, "fork error");
	else if (pid > 0) {
	    printf("Parent from second fork, pid = %d\n", getppid());
	    exit(EXIT_SUCCESS); /* parent from second fork == first child */
	}
	
	/* We're the second child; our parent becomes init as soon
	   as our real parent calls exit() in the statement above.
	   Here's where we'd continue executing, knowing that when
	   we're done, init will reap our status. */
	
	sleep(2);
	printf("second child, parent pid = %d\n", getppid());
	exit(EXIT_SUCCESS);
    }
    
    if (waitpid(pid, NULL, 0) != pid) /* wait for first child */
	fprintf(stderr, "waitpid error");
    
    /* We're the parent (the original process); we continue executing,
       knowing that we're not the parent of the second child. */
    printf("Parent, pid = %d\n", getppid());
    
    exit(EXIT_SUCCESS);
}
