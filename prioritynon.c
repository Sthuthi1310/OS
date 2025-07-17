#include<stdio.h>
#include<stdlib.h>
typedef struct process{
    int ID,AT,BT,CT,WT,TAT,priority,isCompl;
}pro;
pro p[15];
void main()
{
    int n,total_TAT=0,total_WT=0,idletime=0;
    float avg_WT,avg_TAT;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("Enter the arrival burst and priority\n");
    printf("AT BT P\n");
    for(int i=0;i<n;i++)
    {
        p[i].ID=i+1;
        scanf("%d%d%d",&p[i].AT,&p[i].BT,&p[i].priority);
        p[i].isCompl=0;
    }
    int minindex,minPriority,completed=0,curTime=0;
    printf("\nGantt chart\n");
    while(completed!=n)
    {
        minindex=-1;
        minPriority=9999;
        for(int i=0;i<n;i++)
        {
            if(p[i].AT<=curTime&&p[i].isCompl==0)
            {
                if(p[i].priority<minPriority||(p[i].priority==minPriority&&p[i].AT<p[minindex].AT))
                {
                    minPriority=p[i].priority;
                    minindex=i;
                }
            }
        }
        if(minindex==-1)
        {
            curTime++;
            idletime++;
        }
        else{
            if(idletime>0)
            {
                printf("IDle time %d",idletime);
            }
            idletime=0;
            curTime+=p[minindex].BT;
            p[minindex].CT=curTime;
            p[minindex].TAT=p[minindex].CT-p[minindex].AT;
            p[minindex].WT=p[minindex].TAT-p[minindex].BT;
            total_TAT+=p[minindex].TAT;
            total_WT+=p[minindex].WT;
            p[minindex].isCompl=1;
            completed++;
            printf("|P%d (%d) %d ",p[minindex].ID,p[minindex].BT,p[minindex].CT);
        }
    }
    printf("|\n");
    avg_TAT=(float)total_TAT/n;
    avg_WT=(float)total_WT/n;
    printf("PID\tAT\tBT\tCT\tTAT\tWT\tP\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].ID,p[i].AT,p[i].BT,p[i].CT,p[i].TAT,p[i].WT,p[i].priority);
    }
    printf("Avg TAT=%.2f Avg WT=%.2fn",avg_TAT,avg_WT);
}
