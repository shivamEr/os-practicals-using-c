#include<stdio.h>
// First come first serve algorithm without arrival time program
int main()
{
  int num,i,j,n;
  printf("Enter the number of processes : ");
  scanf("%d",&num);
  int bt[num],tat[num],wt[num];
  float awt=0,atat=0;
  printf("Enter a burst time of each process :\n");
  for(i=0;i<num;i++){
    printf("p[%d] : ",i+1);
    scanf("%d",&bt[i]);
  }
  wt[0]=0;
  for ( i = 1; i < num; i++)
  {
    wt[i]=wt[i-1]+bt[i-1];
  }
  for ( i = 0; i < num; i++)
  {
    tat[i]=bt[i]+wt[i];
  }
  
  
  printf("process\t burst time\t waiting time\t turn arount time\n");
  for ( i = 0; i < num; i++)
  {
    printf("p[%d]\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],wt[i],tat[i]);
  }
  for ( i = 0; i < num; i++)
  {
    awt=awt+wt[i];
    atat=atat+tat[i];
  }
  printf("Average waiting %0.2f\naverage turn around %0.3f",(awt/num),atat/num);
  
  
  // for(i=0;i<num;i++){
  //   for(j=i+1;j<num;j++){
  //     if(bt[i]>bt[j]){
  //       n=bt[i];
  //       bt[i]=bt[j];
  //       bt[j]=n;
  //     }
  //   }
  //  }
  // for ( i = 0; i < num; i++)
  // {
  //   /* code */
  //   printf("\n%d",bt[i]);
  // }
  
  return 0;
}