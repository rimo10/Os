// FCFS with Arrival Time!=0
#include <stdio.h>
struct processs
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
    struct processs p[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the arrival time of process[%d]:", i);
        scanf("%d", &p[i].at);
        printf("Enter the burst time of process[%d]:", i);
        scanf("%d", &p[i].bt);
        p[i].id = i;
    }
    int queue = 0;
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
        // Sorting Arrival Time
        int temp = p[i].at;
        p[i].at = p[min].at;
        p[min].at = temp;

        // Sorting Burst Time
        temp = p[i].bt;
        p[i].bt = p[min].bt;
        p[min].bt = temp;

        // Sorting ids
        temp = p[i].id;
        p[i].id = p[min].id;
        p[min].id = temp;
    }
    queue = p[0].at;
    for (int i = 0; i < n; i++)
    {
        queue += p[i].bt;
        p[i].ct = queue;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        avg_tat += p[i].tat;
        avg_wt += p[i].wt;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (p[j].id < p[min].id)
            {
                min = j;
            }
        }
        // Sorting Arrival Time
        int temp = p[i].at;
        p[i].at = p[min].at;
        p[min].at = temp;

        // Sorting Burst Time
        temp = p[i].bt;
        p[i].bt = p[min].bt;
        p[min].bt = temp;

        // Sorting ids
        temp = p[i].id;
        p[i].id = p[min].id;
        p[min].id = temp;

        // Sorting Completion time
        temp = p[i].ct;
        p[i].ct = p[min].ct;
        p[min].ct = temp;

        // Sorting waiting time
        temp = p[i].wt;
        p[i].wt = p[min].wt;
        p[min].wt = temp;

        // SOrting turnaround time
        temp = p[i].tat;
        p[i].tat = p[min].tat;
        p[min].tat = temp;
    }
    printf("\nProcess\t\tArrivalTime\t\tBurstTime\t\tCompletionTime\t\tTurnarounTime\t\tWaitingTime\n");
    for (int i = 0; i < n; i++)
    {
        printf("P[%d]\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("Average Waiting Time:%f\n", (float)avg_wt / n);
    printf("Average Turnaround Time:%f\n", (float)avg_tat / n);
}
