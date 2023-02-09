#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n, i, tst = 0, diff;

    printf("Enter the no : of requests :");
    scanf("%d", &n);
    int req[n + 1];
    printf("Enter the curent head position : ");
    scanf("%d", &req[0]);
    printf("Enter the requests : ");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &req[i]);
        diff = abs(req[i] - req[i - 1]);
        tst = tst + diff;
    }

    for (i = 0; i <= n; i++)
    {
        printf("%d", req[i]);
        if (i == n)
        {
            break;
        }
        printf("->");
    }

    printf("Total seek time is %d", tst);
    return 0;
}