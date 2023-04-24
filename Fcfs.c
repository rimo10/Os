// FCFS with Arrival Time=0
#include <stdio.h>
struct processs
{
    int bt;
    int tat;
    int wt;
    int ct;
};
void main()
{
    struct processs p[10];
    float avg_wt = 0.0, avg_tat = 0.0;
    for (int i = 0; i < 10; i++)
    {
        printf("Enter the burst time of process[%d]:", i);
        scanf("%d", &p[i].bt);
    }
    int queue = 0;
    for (int i = 0; i < 10; i++)
    {
        queue += p[i].bt;
        p[i].ct = queue;
        p[i].tat = p[i].ct;
        p[i].wt = p[i].tat - p[i].bt;
        avg_tat += p[i].tat;
        avg_wt += p[i].wt;
    }
    printf("\nProcess\t\tBurstTime\t\tCompletionTime\t\tTurnarounTime\t\tWaitingTime\n");
    for (int i = 0; i < 10; i++)
    {
        printf("P[%d]\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n", i, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("Average Waiting Time:%f\n", (float)avg_wt / 10.0);
    printf("Average Turnaround Time:%f\n", (float)avg_tat / 10.0);
}