#include<stdio.h>
#define max 30
int main()
{
    int i,j,t,n,wt[max],p[max],bt[max],tat[max];
    float awt,atat;
    printf("Enter number of processes :");
    scanf("%d",&n);
    printf("Enter the proces number and burst time :");
    for(i=0;i<n;i++){
        scanf("%d %d",&p[i],&bt[i]);
    }
    // now sorting the burst time and processes
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(bt[i]>bt[j]){
                t=bt[i];
                bt[i]=bt[j];
                bt[j]=t;

                t=p[i];
                p[i]=p[j];
                p[j]=t;
            }
        }
    }
    printf("Process \t Burst time \t Waiting time \t Turn around time\n");
    for(i=0;i<n;i++){
        wt[i]=0;
        tat[i]=0;
        for(j=0;j<i;j++){
            wt[i]=wt[i]+bt[j];
        }
        tat[i]=wt[i]+bt[i];
        awt=awt+wt[i];
        atat=atat+tat[i];
        printf("%d\t %d\t\t %d\t\t %d\n",p[i],bt[i],wt[i],tat[i]);
    }
    printf("Avrage waiting time is : %f\n",awt/n);
    printf("Avrage turnaround time is : %f\n",atat/n);


  return 0;
}