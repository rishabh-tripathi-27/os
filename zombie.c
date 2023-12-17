//ZOMBIE PROCESS
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
    int
    main()
{
    pid_t child_pid = fork();
    if (child_pid < 0)
    {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }
    if (child_pid == 0)
    {
        printf("| %-12s | %-5s | %-12s |\n", "Process", "PID", "Status");
        printf("|--------------|-------|--------------|\n");
        printf("| %-12s | %-5d | %-12s |\n", "Child", getpid(), "Running");
        sleep(2);
        printf("| %-12s | %-5d | %-12s |\n", "Child", getpid(), "Exiting");
    }
    else
    {
        printf("| %-12s | %-5s | %-12s |\n", "Process", "PID", "Status");
        printf("|--------------|-------|--------------|\n");
        printf("| %-12s | %-5d | %-12s |\n", "Parent", getpid(), "Running");
        printf("| %-12s | %-5d | %-12s |\n", "Parent", getpid(), "Not Waiting");
        sleep(5);
        printf("| %-12s | %-5d | %-12s |\n", "Parent", getpid(), "Exiting");
    }
    return 0;
}