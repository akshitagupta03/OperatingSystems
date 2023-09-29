#include <stdio.h>
#define max 100

int main(){
    int n, AT[max], WT[max], ET[max], TAT[max], CT[max], PID[max], RT[max], i, min, j, temp, maxCT;
    double avg_WT=0, avg_TAT=0, thrpt;

    printf("Please enter number of processes\n");
    scanf("%d", &n);
    if(n > max){
        printf("Limit exceeded.");
    }
    else if(n<1){
        printf("No process exist or negative input.");
    }
    else{
        for(i=0; i<n; i++){
            printf("Enter details for process %d:\n", i+1);
            printf("Arrival Time: ");
            scanf("%d", &AT[i]);
            printf("Execution Time: ");
            scanf("%d", &ET[i]);
            PID[i]=i+1;
        }
        //sorting for arrival time
        for(i=0;i< -1;i++){
            min=i;
        for(j=i+1;j< n;j++){
            if(AT[j]< AT[min]){
                min=j;
            } 
        }
        temp=AT[i];
        AT[i]=AT[min];
        AT[min]=temp;
        
        temp=ET[i];
        ET[i]=ET[min];
        ET[min]=temp;
        
        temp=PID[i];
        PID[i]=PID[min];
        PID[min]=temp;
        }
        for(i=0;i< n;i++){
            RT[i]=ET[i];
        }
        RT[n]=9999;
        j=0;
        for(min=0;j!=n;min++){
            temp=n;
            for(i=0;i< n;i++){
                if(AT[i]<=min && RT[i]< RT[temp] && RT[i]>0){
                    temp=i;
            }
        }
        RT[temp]--;
        if(RT[temp]==0){
            j++;
            thrpt=min+1;
            CT[temp]=thrpt;
            if(maxCT< thrpt)
            {
            maxCT=thrpt;
            }
        }
        }
        printf("Process\tArrival Time\tExecution Time\tCompletion Time\tTAT\tWaiting Time\n");
        for(i=0;i< n;i++){
        TAT[i]=CT[i]-AT[i];
        WT[i]=TAT[i]-ET[i];
        avg_TAT=avg_TAT+TAT[i];
        avg_WT=avg_WT+WT[i];
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t%d\n", PID[i], AT[i], ET[i], CT[i], TAT[i], WT[i]);
        }
        avg_TAT=(double)avg_TAT/n;
        avg_WT=(double)avg_WT/n;
        thrpt=(double)n/(maxCT-AT[0]);
        printf("\nAvg.TAT=%.2f\n", avg_TAT);
        printf("Avg.WT=%.2f\n", avg_WT);
        printf("Throughput=%.2f", thrpt);
    }
    return 0;
}
