#include <stdio.h>

int main()
{
    int temp, n, i;
    printf("Enter the no: of the processes :");
    scanf("%d", &n);
    int bt[n], wt[n], tat[n];
    printf("Enter the burst time :");
    for (i = 0; i < n; i++)
    {

        scanf("%d", &bt[i]);
    }
    for (i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {

            if (bt[j] > bt[j + 1])
            {
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
            }
        }
    }

    wt[0] = 0;

    for (i = 1; i < n; i++)
    {

        wt[i] = wt[i - 1] + bt[i - 1];
    }
    int ttat = 0, twt = 0;
    printf("---------------------------------------\n");
    printf("| Process | waiting time |   ta time  |\n");
    for (i = 0; i < n; i++)
    {

        tat[i] = wt[i] + bt[i];
        twt = twt + wt[i];
        ttat = ttat + tat[i];
        printf("---------------------------------------\n");
        printf("|    P%d    |     %d        |    %d       |\n", i, wt[i], tat[i]);
    }

    printf("the average waiting time: %.2f\n", (float)twt / n);
    printf("the average turnaround time: %.2f", (float)ttat / n);
}
