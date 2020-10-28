#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <assert.h>


int main(int argc, char *argv[]){ 
    assert(argc==2);
    int res = fork();
    printf("Résultat : %d, %d, %d\n", res, getpid(), getppid());
    sleep(atoi(argv[1])); // à tester avec ou sans
    return EXIT_SUCCESS;
}

/*
$ ./fork
Résultat : 4311, 4310, 1233
Résultat : 0, 4311, 4310
En fonction du type de connexion, on peut lire 
ppid 1 (init qui est un lien sur systemd) ou celui de systemd --user
*/

