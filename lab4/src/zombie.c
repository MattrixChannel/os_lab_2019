#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    if ((pid = fork()) == 0) {

        printf("Parent process PID: %d\n", getpid());
	sleep(5);
	printf("Parent finished\n");
        exit(0);
    } else if (pid > 0) {

        printf("Child process PID: %d waiting...\n", getpid());
        //wait(NULL);//, sleep убрать

        sleep(10);
        printf("Child finished\n");
    } else {
        // Ошибка при создании процесса
        perror("fork");
        return 1;
    }

    return 0;
}
