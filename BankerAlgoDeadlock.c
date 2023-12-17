#include <stdio.h>
#include <stdbool.h>

#define P 5
#define R 3

int avail[R], max[P][R], alloc[P][R], need[P][R];

bool is_safe_state();

void request_resources(int process_id, int request[]);

int main()
{
    int processes, resources;

    printf("Enter the number of processes and resources: ");
    scanf("%d %d", &processes, &resources);

    printf("Enter the available resources:\n");
    for (int i = 0; i < resources; i++)
        scanf("%d", &avail[i]);

    printf("Enter the maximum demand of each process:\n");
    for (int i = 0; i < processes; i++)
        for (int j = 0; j < resources; j++)
            scanf("%d", &max[i][j]);

    printf("Enter the allocated resources for each process:\n");
    for (int i = 0; i < processes; i++)
    {
        for (int j = 0; j < resources; j++)
        {
            scanf("%d", &alloc[i][j]);
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    int process_id;
    int request[resources];
    printf("Enter the process id for resource request: ");
    scanf("%d", &process_id);

    printf("Enter the resource request for process %d:\n", process_id);
    for (int i = 0; i < resources; i++)
        scanf("%d", &request[i]);

    request_resources(process_id, request);

    return 0;
}

void request_resources(int process_id, int request[])
{
    for (int i = 0; i < R; i++)
    {
        if (request[i] > need[process_id - 1][i] || request[i] > avail[i])
        {
            printf("Error: Requested resources exceed the need or available resources.\n");
            return;
        }
    }

    for (int i = 0; i < R; i++)
    {
        alloc[process_id - 1][i] += request[i];
        need[process_id - 1][i] -= request[i];
        avail[i] -= request[i];
    }

    if (is_safe_state())
    {
        printf("Resource request for process %d is granted. System is in a safe state.\n", process_id);
    }
    else
    {
        printf("Resource request for process %d is denied. System would be in an unsafe state.\n", process_id);
        for (int i = 0; i < R; i++)
        {
            alloc[process_id - 1][i] -= request[i];
            need[process_id - 1][i] += request[i];
            avail[i] += request[i];
        }
    }
}

bool is_safe_state()
{
    int work[R];
    bool finish[P];

    for (int i = 0; i < R; i++)
        work[i] = avail[i];

    for (int i = 0; i < P; i++)
        finish[i] = false;

    int count = 0;
    while (count < P)
    {
        int i;
        for (i = 0; i < P; i++)
        {
            if (!finish[i])
            {
                int j;
                for (j = 0; j < R; j++)
                    if (need[i][j] > work[j])
                        break;

                if (j == R)
                {
                    for (j = 0; j < R; j++)
                        work[j] += alloc[i][j];

                    finish[i] = true;
                    count++;
                }
            }
        }

        if (i == P)
            break;
    }

    return count == P;
}
