// SJF with Arrival Time!=0
#include <stdio.h>
struct process
{
    int id;
    int at;
    int bt;
    int tat;
    int wt;
    int ct;
};
void main()
{
    float avg_wt = 0.0, avg_tat = 0.0;
    printf("Enter the number of processes:");
    int n;
    scanf("%d", &n);
    struct process p[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the arrival time of process[%d]:", i);
        scanf("%d", &p[i].at);
        printf("Enter the burst time of process[%d]:", i);
        scanf("%d", &p[i].bt);
        p[i].id = i;
    }
    struct process temp;
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (p[j].at < p[min].at) // Sorting on basis of AT
            {
                min = j;
            }
        }
        temp = p[i];
        p[i] = p[min];
        p[min] = temp;
    }
    int sum = p[0].bt;
    for (int i = 1; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (p[j].bt < p[min].bt && p[j].at <= sum)
            {
                min = j;
            }
        }
        temp = p[i];
        p[i] = p[min];
        p[min] = temp;
        sum += p[i].bt;
    }
    p[0].wt = 0;
    for (int i = 1; i < n; i++)
    {
        int t = 0;
        for (int j = 0; j < i; j++)
        {
            t += p[j].bt;
        }
        p[i].wt = t - p[i].at;
    }
    for (int i = 0; i < n; i++)
    {
        p[i].tat = p[i].bt + p[i].wt;
        avg_wt += p[i].wt;
        avg_tat += p[i].tat;
    }
    avg_wt = avg_wt / n;
    avg_tat = avg_tat / n;
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (p[j].id < p[min].id) // Sorting on basis of ID
            {
                min = j;
            }
        }
        temp = p[i];
        p[i] = p[min];
        p[min] = temp;
    }
    printf("\nProcess\t\tArrivalTime\t\tBurstTime\t\tTurnarounTime\t\tWaitingTime\n");
    int k;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            k = 0;
        }
        else
            k = 1;
        printf("P[%d]\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].tat + k, p[i].wt + k);
    }
    printf("Average Waiting Time:%f\n", (float)avg_wt / n);
    printf("Average Turnaround Time:%f\n", (float)avg_tat / n);
}
