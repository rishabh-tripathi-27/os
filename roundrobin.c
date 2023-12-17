#include <stdio.h>

int main()
{
    int n, q;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the time quantum: ");
    scanf("%d", &q);

    int bt[n], rt[n], wt[n], tat[n];

    printf("Enter burst times for each process:\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    int t = 0;
    int comp = 0;

    while (comp < n)
    {
        for (int i = 0; i < n; i++)
        {
            if (rt[i] > 0)
            {
                int et = (rt[i] < q) ? rt[i] : q;
                rt[i] -= et;
                t += et;
                wt[i] += t - bt[i];
                if (rt[i] == 0)
                {
                    tat[i] = t;
                    comp++;
                }
            }
        }
    }

    float avg_wt = 0, avg_tat = 0;
    for (int i = 0; i < n; i++)
    {
        avg_wt += wt[i];
        avg_tat += tat[i];
    }
    avg_wt /= n;
    avg_tat /= n;

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\nAvg Waiting Time: %.2f\n", avg_wt);
    printf("Avg Turnaround Time: %.2f\n", avg_tat);

    return 0;
}
