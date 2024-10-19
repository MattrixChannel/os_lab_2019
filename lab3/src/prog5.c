#define _GNU_SOURCE
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

/*
int main() {
    char* args[] = { "prog1", "1", "3", NULL };
    if(execvp("/workspaces/os_lab_2019/lab3/src/prog1", args) == -1) {
        printf("\nfailed connection\n");
    return 1;
    }
}
*/

int main( void ) {


	int pid = fork();

	if ( pid == 0 ) {
		char* args[] = { "prog1", "1", "3", NULL };
		if(execvp("/workspaces/os_lab_2019/lab3/src/prog1", args) == -1) {
		        printf("\nfailed connection\n");
		}
	}

	printf( "Finished executing the parent process\n"
	        " - the child won't get here--you will only see this once\n" );

	return 0;
}
