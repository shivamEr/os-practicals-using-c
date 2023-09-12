#include <stdio.h>
int main()
{
    int n;
    printf("Enter total no of process : ");
    scanf("%d", &n);
    int wt = 0, tat=0, arr_time[n], bt[n], temp_bt[n];
    int x = n;
    float average_wt, average_tat;
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter Details of process[%d]\n ", i + 1);
        printf("Enter arrival time : ");
        scanf("%d", &arr_time[i]);
        printf("Enter burst time : ");
        scanf("%d", &bt[i]);
        temp_bt[i] = bt[i];
    }
    int qt;
    printf("\nEnter quantum time : ");
    scanf("%d", &qt);
    int total = 0, count = 0, i;
    printf("process i'd\tBurst time\tTurnaround time\t\tWaiting time");
    for (total = 0, i = 0; x != 0;)
    {
        if (temp_bt[i] <= qt && temp_bt[i] > 0)
        {
            total = total + temp_bt[i];
            temp_bt[i] = 0;
            count = 1;
        }
        else if (temp_bt[i] > 0)
        {
            temp_bt[i] = temp_bt[i] - qt;
            total += qt;
        }
        if (temp_bt[i] == 0 && count == 1)
        {
            x--;
            printf("\nprocess no[%d]\t\t%d\t\t%d\t\t\t%d", i + 1, bt[i], total - arr_time[i], total - arr_time[i] - bt[i]);
            wt = wt + total - arr_time[i] - bt[i];
            tat = tat + total - arr_time[i];
            count = 0;
        }
        if (i == n - 1)
        {
            i = 0;
        }
        else if (arr_time[i + 1] <= total)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }
    average_tat=tat *1.0/n;
    average_wt=wt*1.0/n;
    printf("\n\nAverage Waiting Time : \t %f",average_wt);
    printf("\nAverage Turnaround Time : \t %f",average_tat);

    return 0;
}