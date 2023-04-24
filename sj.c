#include <stdio.h>

int main()

{

    int i, n, p[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, min, k = 1, btime = 0;

    int bt[10], temp, j, arr[10], wait[10], turn[10], ta = 0, sum = 0;

    float wavg = 0, tavg = 0, tsum = 0, wsum = 0;

    printf("\t\t\tShortest Job First Scheduling (Non - Preemptive)\n");

    printf("\nEnter the No. of processes :");

    scanf("%d", &n);

    printf("Enter the arrival time and burst time of the processes:\n");

    for (i = 0; i < n; i++)

        scanf(" %d %d", &arr[i], &bt[i]);

    for (i = 0; i < n; i++)

    {

        for (j = 0; j < n; j++)

        {

            if (arr[i] < arr[j])

            {

                temp = p[j];

                p[j] = p[i];

                p[i] = temp;

                temp = arr[j];

                arr[j] = arr[i];

                arr[i] = temp;

                temp = bt[j];

                bt[j] = bt[i];

                bt[i] = temp;
            }
        }
    }

    for (j = 0; j < n; j++)

    {

        btime = btime + bt[j];

        min = bt[k];

        for (i = k; i < n; i++)

        {

            if (btime >= arr[i] && bt[i] < min)

            {

                temp = p[k];

                p[k] = p[i];

                p[i] = temp;

                temp = arr[k];

                arr[k] = arr[i];

                arr[i] = temp;

                temp = bt[k];

                bt[k] = bt[i];

                bt[i] = temp;
            }
        }

        k++;
    }

    wait[0] = 0;

    for (i = 1; i < n; i++)

    {

        sum = sum + bt[i - 1];

        wait[i] = sum - arr[i];

        wsum = wsum + wait[i];
    }

    wavg = (wsum / n);

    for (i = 0; i < n; i++)

    {

        ta = ta + bt[i];

        turn[i] = ta - arr[i];

        tsum = tsum + turn[i];
    }

    tavg = (tsum / n);

    printf("************************");

    printf("\n RESULT:-");

    printf("\nProcess\t Burst\t Arrival\t Waiting\t Turn-around");

    for (i = 0; i < n; i++)

        printf("\n p%d\t %d\t %d\t\t %d\t\t\t%d", p[i], bt[i], arr[i], wait[i], turn[i]);

    printf("\n\nAVERAGE WAITING TIME : %f", wavg);

    printf("\nAVERAGE TURN AROUND TIME : %f", tavg);

    return 0;
}