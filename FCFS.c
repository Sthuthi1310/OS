#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int AT,BT,CT,TAT,ID,RT,WT;
}process;
void fcfs(process[],int);
int main()
{
    int n;
    printf("Enter the numberr of processes: ");
    scanf("%d",&n);
    process pro[n];
    for(int i=0;i<n;i++)
    {
        printf("For process %d \n",i+1);
        printf("Enter the arrival time : ");
        scanf("%d",&pro[i].AT);
        printf("\nEnter the burst time : ");
        scanf("%d",&pro[i].BT);
        pro[i].ID=i+1;
    }
        for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (pro[j].AT > pro[j + 1].AT) {
                process temp = pro[j];
                pro[j] = pro[j + 1];
                pro[j + 1] = temp;
            }
        }
    }
    fcfs(pro,n);
    return 0;
}
void fcfs(process pro[],int n)
{
    int ET=0;
    float avgWT,avgTAT,avgRT;
    int totalWT=0,totalTAT=0,totalRT=0;
    printf("\nGantt Chart\n");
    for(int i=0;i<n;i++)
    {
        if(pro[i].AT>ET)
        ET=ET+(pro[i].AT-ET);
        int temp=ET;
        pro[i].RT=ET-pro[i].AT;
        ET+=pro[i].BT;
        pro[i].CT=ET;
        pro[i].TAT=pro[i].CT-pro[i].AT;
        pro[i].WT=pro[i].TAT-pro[i].BT;
        printf("|(%d) P%d (%d) ",temp,pro[i].ID,ET);
    }
    printf("|\n");
    printf("Observation Table\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",pro[i].ID,pro[i].AT,pro[i].BT,pro[i].CT,pro[i].TAT,pro[i].WT,pro[i].RT);
        totalTAT+=pro[i].TAT;
        totalWT+=pro[i].WT;
        totalRT+=pro[i].RT;
    }
    avgTAT=(float)totalTAT/n;
    avgWT=(float)totalWT/n;
    avgRT=(float)totalRT/n;
    printf("Avg TAT=%.2f Avg WT=%.2f Avg RT=%.2f\n",avgTAT,avgWT,avgRT);
}