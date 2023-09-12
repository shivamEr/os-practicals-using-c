#include <stdio.h>
int main()
{
    int n, i, j, temp, pos;
    float atat = 0, awt = 0;
    printf("Enter no of process : ");
    scanf("%d", &n);
    int bt[n], tat[n], pr[n], pid[n], wt[n];
    printf("Enter processes id  : ");
    for (i = 0; i < n; i++)
    {
        printf("p[%d]", i + 1);
        scanf("%d", &pid[i]);
    }
    printf("\nEnter burst time of processes : ");
    for (i = 0; i < n; i++)
    {
        printf("\np[%d]", i + 1);
        scanf("%d", &bt[i]);
    }
    printf("\nEnter priority of processes : ");
    for (i = 0; i < n; i++)
    {
        printf("\np[%d]", i + 1);
        scanf("%d", &pr[i]);
    }
    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (pr[pos] > pr[j])
            {
                pos = j;
            }
        }
        // Swap priority of each process
        temp = pr[i];
        pr[i] = pr[pos];
        pr[pos] = temp;
        // Swap processes id of each process
        temp = pid[i];
        pid[i] = pid[pos];
        pid[pos] = temp;
        // Swap burst time of each process
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;
    }
    wt[0] = 0;
    printf("process i'd\tburst time\tpriority\twaiting time\tturn around time\n");
    for (i = 0; i < n; i++)
    {
        wt[i] = 0;
        tat[i] = 0;
        for (j = 0; j < i; j++)
        {
            wt[i] = wt[i] + bt[j];
        }
        tat[i] = wt[i] + bt[i];
        awt = awt + wt[i];
        atat = atat + tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], bt[i], pr[i], wt[i], tat[i]);
    }
    awt = awt / n;
    atat = atat / n;
    printf("Average waiting time : %0.3f", awt);
    printf("\nAverage turnaround time : %0.3f", atat);
    return 0;
}