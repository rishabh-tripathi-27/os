#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFFER_SIZE 25
int main()
{
    int pipe_fd[2];
    pid_t pid;
    char buffer[BUFFER_SIZE];
    if (pipe(pipe_fd) == -1)
    {
        perror("Pipe creation failed");
        exit(EXIT_FAILURE);
    }
    pid = fork();
    if (pid < 0)
    {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }
    if (pid > 0)
    {
        close(pipe_fd[0]);
        printf("Parent process writing to the pipe...\n");
        write(pipe_fd[1], "Hello from parent!", 18);
        close(pipe_fd[1]);
    }
    else
    {
        close(pipe_fd[1]);
        printf("Child process reading from the pipe...\n");
        read(pipe_fd[0], buffer, BUFFER_SIZE);
        printf("Child process received: %s\n", buffer);
        close(pipe_fd[0]);
        exit(EXIT_SUCCESS);
    }
    return 0;
}