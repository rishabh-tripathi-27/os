#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int bt[n];
    int pr[n];
    int rt[n];
    bool comp[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter burst time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
        printf("Enter priority for P%d: ", i + 1);
        scanf("%d", &pr[i]);
        rt[i] = bt[i];
        comp[i] = false;
    }

    int t = 0;

    printf("\nExecution Order:\n");
    printf("Time | Process\n");

    while (true)
    {
        int hp = INT_MAX;
        int hp_p = -1;

        for (int i = 0; i < n; i++)
        {
            if (rt[i] > 0 && pr[i] < hp && bt[i] <= t)
            {
                hp = pr[i];
                hp_p = i;
            }
        }

        if (hp_p == -1)
        {
            t++;
        }
        else
        {
            rt[hp_p]--;

            if (rt[hp_p] == 0)
            {
                comp[hp_p] = true;
                printf("%d-%d | P%d\n", t, t + 1, hp_p + 1);
            }
            else
            {
                printf("%d-%d | P%d*\n", t, t + 1, hp_p + 1);
            }

            t++;
        }

        bool all_comp = true;
        for (int i = 0; i < n; i++)
        {
            if (!comp[i])
            {
                all_comp = false;
                break;
            }
        }

        if (all_comp)
        {
            break;
        }
    }

    return 0;
}
