#include <stdio.h>

#define MAX_PROC 10

struct Proc {
    int id;
    int burst;
    int rem;
};

void roundRobin(struct Proc procs[], int n, int quantum) {
    int rem_t[MAX_PROC];
    int t = 0;
    int d = 0;

    for (int i = 0; i < n; i++) {
        rem_t[i] = procs[i].burst;
    }

    while (d < n) {
        for (int i = 0; i < n; i++) {
            if (rem_t[i] > 0) {
                if (rem_t[i] <= quantum) {
                    t += rem_t[i];
                    rem_t[i] = 0;
                    printf("P%d completed at time %d\n", procs[i].id, t);
                    d++;
                } else {
                    t += quantum;
                    rem_t[i] -= quantum;
                }
            }
        }
    }
}

int main() {
    int n, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_PROC) {
        printf("Invalid number of processes.\n");
        return 1;
    }

    struct Proc procs[n];

    for (int i = 0; i < n; i++) {
        procs[i].id = i + 1;
        printf("Enter Burst Time for P%d: ", procs[i].id);
        scanf("%d", &procs[i].burst);
        procs[i].rem = procs[i].burst;
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    printf("Round Robin CPU Scheduling:\n");
    roundRobin(procs, n, quantum);

    return 0;
}