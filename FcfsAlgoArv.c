#include<stdio.h>
// FCFS algorithm with their arrival time
int main()
{
    int n,i,j;
    printf("Enter no of process :");
    scanf("%d",&n);
    int bt[n],at[n],tat[n],wt[n],temp[n];
    float awt=0,atat=0;
    printf("\nEnter the burst time of the process : ");
    for ( i = 0; i < n; i++)
    {
        printf("\np[%d] :",i+1);
        scanf("%d",&bt[i]);
    }
    printf("\nEnter the arrival time of the process :");
    for ( i = 0; i < n; i++)
    {
        printf("\np[%d] :",i+1);
        scanf("%d",&at[i]);
    }
    temp[0]=0;
    printf("processes\t burst time\t arrival time\t waiting time\t burst time\t turn around time\n");
    for ( i = 0; i < n; i++)
    {
        wt[i]=0;
        tat[i]=0;
        temp[i+1]=temp[i]+bt[i];
        wt[i]=temp[i]-at[i];
        tat[i]=wt[i]+bt[i];
        awt = awt + wt[i];
        atat = atat + tat[i];
        printf("%d\t%d\t%d\t%d\t%d\n",i+1,bt[i],at[i],wt[i],tat[i]);
    }
    awt = awt/n;
    atat=atat/n;
    printf("\naverage waiting time %f ",awt);
    printf("\naverage turn around time %f",atat);
    
    
  return 0;
}