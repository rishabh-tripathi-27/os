#include <stdio.h>
#include <stdlib.h>
int calculateHeadMovement(int queue[], int head, int size)
{
    int totalHeadMovement = 0;
    for (int i = 0; i < size; ++i)
    {
        totalHeadMovement += abs(head - queue[i]);
        head = queue[i];
    }
    return totalHeadMovement;
}
void fcfs(int queue[], int head, int size)
{
    int totalHeadMovement = calculateHeadMovement(queue, head, size);
    printf("FCFS Head Movement: %d\n", totalHeadMovement);
}
int main()
{
    int size, head;
    printf("Enter the number of requests in the queue: ");
    scanf("%d", &size);
    printf("Enter the disk request queue:\n");
    int queue[size];
    for (int i = 0; i < size; ++i)
    {
        scanf("%d", &queue[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    fcfs(queue, head, size);
    return 0;
}
