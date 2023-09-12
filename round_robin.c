#include<stdio.h>
int main()
{
  int n,i,j,qt,count=0,sq=0,temp;
  printf("Enter number of process :");
  scanf("%d",&n);
  int bt[n],tat[n],rem_bt[n],wt[n];
  float atat=0,awt=0;
  printf("Enter burst time of processes : ");
  for ( i = 0; i < n; i++)
  {
    printf("\np[%d]",i+1);
    scanf("%d",&bt[i]);
    rem_bt[i]=bt[i];
  }
  printf("\nEnter a quintum time : ");
  scanf("%d",&qt);
  while (1)
  {
     for ( i = 0,count=0; i < n; i++)
     {
       if (rem_bt[i]==0)
       {
        count++;
        continue;
       }
       if (rem_bt[i]>qt)
       {
         rem_bt[i]=rem_bt[i]-qt;
       }
       else
       if (rem_bt[i]>=qt)
       {
         temp = rem_bt[i];
         rem_bt[i] = 0;
       }
       sq = sq + temp;
       tat[i]=sq;

     }
     if (n==count)
     {
      break;
     }
     
     
  }
  printf("\nprocess \tburst time \tturnaround time \twaiting time\n");
     for ( i = 0; i < n; i++)
     {
       wt[i]=tat[i]-bt[i];
       awt=awt+wt[i];
       atat=atat+tat[i];
       printf("%d\t%d\t%d\t%d\n",i+1,bt[i],tat[i],wt[i]);
     }
     atat=atat/n;
     awt=awt/n;
     printf("Average waiting time : %0.3f",awt);
     printf("\nAverage turnaround time : %0.3f",atat);
     
  
  
  return 0;
}