#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

//#define WEXITSTATUS(stat_val) ((unsigned)(stat_val) >> 8)

#ifndef BINDIR
#define BINDIR "/usr/local/bin"
#endif

#define BINARY "usage.pl"

int
main( int argc, char *argv[] )
{
    char command[1024];
    int i;
    int returnval;
    int posix_exit;

    /* Be root */
    setuid( geteuid(  ) );
    setgid( getegid(  ) );

    sprintf( command, "%s/%s", BINDIR, BINARY );

    returnval = execv(command, argv);

    posix_exit = WEXITSTATUS(returnval);

    return posix_exit;
}
