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
void scan(int queue[], int head, int size)
{
    int totalHeadMovement = 0;
    int direction = 1; // 1 for right, -1 for left
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (queue[j] > queue[j + 1])
            {
                int temp = queue[j];
                queue[j] = queue[j + 1];
                queue[j + 1] = temp;
            }
        }
    }
    int index;
    for (index = 0; index < size; ++index)
    {
        if (head < queue[index])
        {
            break;
        }
    }
    for (int i = index; i < size; ++i)
    {
        totalHeadMovement += abs(head - queue[i]);
        head = queue[i];
    }
    for (int i = index - 1; i >= 0; --i)
    {
        totalHeadMovement += abs(head - queue[i]);
        head = queue[i];
    }
    printf("SCAN Head Movement: %d\n", totalHeadMovement);
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
    scan(queue, head, size);
    return 0;
}