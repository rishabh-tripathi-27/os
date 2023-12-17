#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main()
{
    int shmid;
    key_t key = ftok("shared_memory_example", 65);
    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1)
    {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    char *shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (char *)-1)
    {
        perror("shmat");
        exit(EXIT_FAILURE);
    }
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }
    if (pid > 0)
    {
        printf("Parent process writing to shared memory...\n");
        sprintf(shmaddr, "Hello from parent!");
        sleep(2);
        shmdt(shmaddr);
        shmctl(shmid, IPC_RMID, NULL);
    }
    else
    {
        sleep(1);
        printf("Child process reading from shared memory...\n");
        printf("Child process received: %s\n", shmaddr);
        shmdt(shmaddr);
    }
    return 0;
}