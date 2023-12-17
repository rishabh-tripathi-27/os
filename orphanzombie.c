#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t child_pid;

    child_pid = fork();

    if (child_pid < 0)
    {
        perror("Fork failed");
        exit(1);
    }

    if (child_pid == 0)
    {
        printf("Child process (PID=%d) created\n", getpid());
        sleep(2);
        printf("Child process (PID=%d) exiting\n", getpid());
    }
    else
    {
        printf("Parent process (PID=%d) created child with PID=%d\n", getpid(), child_pid);
        sleep(1);
        printf("Parent process (PID=%d) exiting\n", getpid());
    }

    return 0;
}
