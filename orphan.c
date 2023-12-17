//ORPHAN PROCESS
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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
        printf("| %-10s | %-5d | %-15s |\n", "Child", getpid(), "Running");
        sleep(2);
        printf("| %-10s | %-5d | %-15s |\n", "Child", getpid(), "Exiting");
    }
    else
    {
        printf("| %-10s | %-5d | %-15s |\n", "Parent", getpid(), "Running");
        printf("| %-10s | %-5d | %-15s |\n", "Parent", getpid(), "Exiting");
        exit(EXIT_SUCCESS);
    }
    return 0;
}