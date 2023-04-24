#include <stdio.h>

#define MAX_PROCESSES 5
#define TIME_QUANTUM 2

struct Process
{
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turn_around_time;
    int completion_time;
};

int main()
{
    int n, i, j, time = 0, total_waiting_time = 0, total_turnaround_time = 0;
    struct Process processes[MAX_PROCESSES], temp;
    int completed[MAX_PROCESSES] = {0};

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter arrival time and burst time for each process:\n");
    for (i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].pid = i + 1;
    }

    // Sort processes by arrival time using bubble sort
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (processes[j].arrival_time > processes[j + 1].arrival_time)
            {
                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    printf("\n");
    i = 0;
    while (1)
    {
        int done = 1;
        for (j = 0; j < n; j++)
        {
            if (completed[j])
            {
                continue;
            }
            if (processes[j].arrival_time > time)
            {
                break;
            }
            done = 0;
            printf("Time %d: Running process %d\n", time, processes[j].pid);
            if (processes[j].remaining_time > TIME_QUANTUM)
            {
                processes[j].remaining_time -= TIME_QUANTUM;
                time += TIME_QUANTUM;
            }
            else
            {
                time += processes[j].remaining_time;
                processes[j].turn_around_time = time - processes[j].arrival_time;
                processes[j].waiting_time = time - processes[j].arrival_time - processes[j].burst_time;
                total_turnaround_time += time - processes[j].arrival_time;
                total_waiting_time += time - processes[j].arrival_time - processes[j].burst_time;
                processes[j].remaining_time = 0;
                completed[j] = 1;
                processes[j].completion_time = time;
                printf("Process %d completed at time %d\n", processes[j].pid, time);
            }
        }
        if (done)
        {
            if (i == n)
            {
                break;
            }
            time = processes[i].arrival_time;
            i++;
        }
    }
    printf("Process\t\tArrival Time\t\tBurst Time\t\tWaiting Time\t\tTurnaround Time\t\tCompletion Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turn_around_time, processes[i].completion_time);
    }
    printf("Average waiting time: %f\n", (float)total_waiting_time / n);
    printf("Average turnaround time: %f\n", (float)total_turnaround_time / n);
    return 0;
}
