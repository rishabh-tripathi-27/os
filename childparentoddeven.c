#include <stdio.h>
#include <unistd.h>

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int numbers[n];

    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &numbers[i]);
    }

    pid_t pid;

    pid = fork();

    if (pid < 0)
    {
        printf("Fork failed\n");
        return 1;
    }
    else if (pid == 0)
    {
        int oddSum = 0;
        for (int i = 0; i < n; i++)
        {
            if (numbers[i] % 2 != 0)
            {
                oddSum += numbers[i];
            }
        }
        printf("Child process: Sum of odd numbers = %d\n", oddSum);
    }
    else
    {
        int evenSum = 0;
        for (int i = 0; i < n; i++)
        {
            if (numbers[i] % 2 == 0)
            {
                evenSum += numbers[i];
            }
        }
        printf("Parent process: Sum of even numbers = %d\n", evenSum);
    }

    return 0;
}
