#include <stdio.h>

int main()
{
    int n, bt[30], wait_t[30], turn_ar_t[30], av_wt_t = 0, avturn_ar_t = 0, i, j;
    printf("\nEnter the total no. of processes ");
    scanf("%d", &n);

    printf("\nEnter the Process Burst Time Taken:\n");
    for (i = 0; i < n; i++)
    {
        printf("P[%d]:", i + 1);
        scanf("%d", &bt[i]);
    }

    wait_t[0] = 0;

    for (i = 1; i < n; i++)
    {
        wait_t[i] = 0;
        for (j = 0; j < i; j++)
        {
            wait_t[i] += bt[j];
        }
    }
    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
    for (i = 0; i < n; i++)
    {
        turn_ar_t[i] = bt[i] + wait_t[i];
        av_wt_t += wait_t[i];
        avturn_ar_t += turn_ar_t[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d", i + 1, bt[i], wait_t[i], turn_ar_t[i]);
    }
    av_wt_t /= i;
    avturn_ar_t /= i;
    printf("\nAverage Waiting Time:%d", av_wt_t);
    printf("\nAverage Turnaround Time: %d\n", avturn_ar_t);
    return 0;
}