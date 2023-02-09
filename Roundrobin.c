#include <stdio.h>
struct process
{
    int wt;
    int bt;
    int cbt;
    int pct;
};

int main()
{
    int ct = 0, n, t;
    printf("Enter the no: of the process :");
    scanf("%d", &n);
    struct process p[n];
    printf("Enter the burst time");
    for (int i = 0; i < n; i++)
    {

        scanf("%d", &p[i].bt);
        p[i].cbt = p[i].bt;
        p[i].pct = 0;
        p[i].wt = 0;
    }
    printf("Enter the time quanta :");
    scanf("%d", &t);
    int i = 0, count = 0;
    while (count != n)
    {
        if (p[i].bt == 0)
        {
            i = (i + 1) % n;
        }
        if (p[i].bt > t)
        {

            p[i].bt = p[i].bt - t;
            p[i].wt = p[i].wt + (ct - p[i].pct);
            ct = ct + t;
            p[i].pct = ct;
            i = (i + 1) % n;
        }
        else
        {
            p[i].wt = p[i].wt + (ct - p[i].pct);
            ct = ct + p[i].bt;
            p[i].pct = ct;
            p[i].bt = 0;
            count++;
            i = i + 1 % n;
        }
        }

        int twt = 0, ttat = 0, tat[n];
        for (int i = 0; i < n; i++)
        {

            tat[i] = p[i].wt + p[i].cbt;
            twt = twt + p[i].wt;
            ttat = ttat + tat[i];
        }

        printf("the average waiting time: %.2f\n", (float)twt / n);
        printf("the average turnaround time: %.2f", (float)ttat / n);

        return 0;
    
}
