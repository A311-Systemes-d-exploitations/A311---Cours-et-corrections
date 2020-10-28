/*
 * myid.c : simple id shell command to illustrate syscalls and libc
 * functions
 *
 * version : 21/09/2018
 * auteur  : ms
 *
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>

int main(void) {

    int uid = getuid(); 
    // returns the real user ID of the calling process
    fprintf(stdout, "uid=%u", uid);

    struct passwd *pwd;
    if ((pwd = getpwuid(uid)) == NULL) {
       // returns a pointer to a structure containing the broken-out
       // fields of the record in the password database that matches
       // the user ID uid.
		fprintf(stderr, "Error: incorrect UID\n");
		exit(EXIT_FAILURE);
    }
    fprintf(stdout, "(%s) ", pwd->pw_name);

    int gid = getgid();
    // returns the real group ID of the calling process
    fprintf(stdout, "gid=%u", gid);
    struct group *grp;
    if ((grp = getgrgid(gid)) == NULL){
		/* use gid instead of groupname if absent */
		fprintf(stdout, "(%d)", gid);
    }
    else {
		fprintf(stdout, "(%s)", grp->gr_name);
    }
    fprintf(stdout, "\n");
    
    return EXIT_SUCCESS;
}
/*
$ gcc myid.c -o myid
$ ./myid
uid=656838(ttrollie) gid=200038(coati)
*/
