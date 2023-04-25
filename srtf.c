#include <stdio.h>

void srtf(int at[], int bt[], int n)
{
    int rt[n], ct[n], wt[n], tt[n], completed = 0, t = 0, shortest, min_at, i, j;
    float total_wt = 0, total_tt = 0;

    for (i = 0; i < n; i++)
    {
        rt[i] = bt[i];
    }

    while (completed != n)
    {
        shortest = -1;
        min_at = 9999;
        for (i = 0; i < n; i++)
        {
            if (rt[i] > 0 && at[i] <= t && at[i] < min_at)
            {
                shortest = i;
                min_at = at[i];
            }
        }

        if (shortest == -1)
        {
            t++;
            continue;
        }

        rt[shortest]--;
        if (rt[shortest] == 0)
        {
            completed++;
            ct[shortest] = t + 1;
            wt[shortest] = ct[shortest] - at[shortest] - bt[shortest];
            if (wt[shortest] < 0)
            {
                wt[shortest] = 0;
            }
            tt[shortest] = ct[shortest] - at[shortest];
            total_wt += wt[shortest];
            total_tt += tt[shortest];
        }
        t++;
    }

    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, at[i], bt[i], ct[i], wt[i], tt[i]);
    }

    printf("Average Waiting Time: %f\n", total_wt / n);
    printf("Average Turnaround Time: %f\n", total_tt / n);
}

int main()
{
    int n, i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int at[n], bt[n];

    printf("Enter the arrival times:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &at[i]);
    }

    printf("Enter the burst times:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }

    srtf(at, bt, n);
    return 0;
}
