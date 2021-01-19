#include  <stdio.h>

int main()
{
    int bt[20], p[20], wt[20], tat[20], i, j, n, total = 0, pos, temp; 
    float avg_wt, avg_tat; 
    printf("Enter number of process: "); 
    scanf("%d", &n); 
  
    for(i = 0; i < n; i++)
    {
        printf("Enter the CPU Burst time of p[%d]: ",  i+1); 
        scanf("%d", &bt[i]); 
        p[i] = i + 1;          
    }
  
    for(i = 0; i < n; i++)
    {
        pos = i; 
        for(j = i + 1; j < n; j++)
        {
            if(bt[j] < bt[pos])
                pos = j; 
        }
  
        temp = bt[i]; 
        bt[i] = bt[pos]; 
        bt[pos] = temp; 
  
        temp = p[i]; 
        p[i] = p[pos]; 
        p[pos] = temp; 
    }
   
    wt[0] = 0;             
  
   
    for(i = 1; i < n; i++)
    {
        wt[i] = 0; 
        for(j = 0; j < i; j++)
            wt[i] += bt[j]; 
  
        total+= wt[i]; 
    }
  
    avg_wt = (float) total / n;       
    total = 0; 
  
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time"); 

    for(i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];    
        total+= tat[i]; 
        printf("\nP[%d]\t\t%d\t\t%d\t\t\t%d\n", p[i], bt[i], wt[i], tat[i]); 
    }
    
    printf("\nGantt Chart\n");
    
    for(i = 0; i < n; i++)
    {
        printf("|\tP[%d]\t", p[i]);
    }

    printf("|\n");
    
    int last = bt[n-1] + ( n == 1 ? 0 : wt[n-1]);

    for(i = 0; i < n; i++)
    {
        printf("%d\t\t", wt[i]);
    }

    printf("%d", last);
  
    avg_tat = (float) total / n;     
    printf("\n\nAverage Waiting Time = %0.2f", avg_wt); 
    printf("\nAverage Turnaround Time = %0.2f\n", avg_tat); 
}