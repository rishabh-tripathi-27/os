#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;

    pid = fork();

    if (pid < 0)
    {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }
    if (pid > 0)
    {
        printf("Parent process executing 'ls' command...\n");
        execl("/bin/ls", "ls", "-l", NULL);
        perror("execl");
        exit(EXIT_FAILURE);
    }
    else
    {
        wait(NULL);
        printf("Child process executing 'date' command...\n");
        execl("/bin/date", "date", NULL);
        perror("execl");
        exit(EXIT_FAILURE);
    }
    return 0;
}
