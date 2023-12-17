#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int processes[n][7];

    printf("Enter the Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Process %d:\n", i + 1);
        processes[i][0] = i + 1;
        printf("AT[%d]: ", i + 1);
        scanf("%d", &processes[i][1]);
        printf("BT[%d]: ", i + 1);
        scanf("%d", &processes[i][2]);
        processes[i][3] = processes[i][2];
    }

    int currentTime = 0;
    int completed = 0;

    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    while (completed < n)
    {
        int minIndex = -1;
        int minTime = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (processes[i][1] <= currentTime && processes[i][3] < minTime && processes[i][3] > 0)
            {
                minTime = processes[i][3];
                minIndex = i;
            }
        }

        if (minIndex == -1)
        {
            currentTime++;
        }
        else
        {
            int *p = processes[minIndex];
            p[3]--;

            if (p[3] == 0)
            {
                completed++;
                p[4] = currentTime + 1; // Completion Time
                p[5] = p[4] - p[1];     // Turnaround Time
                p[6] = p[5] - p[2];     // Waiting Time
            }
            currentTime++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i][0], processes[i][1], processes[i][2], processes[i][4], processes[i][5], processes[i][6]);
    }

    return 0;
}