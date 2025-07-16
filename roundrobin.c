#include<stdio.h>
#include<stdlib.h>
typedef struct process{
    int ID,AT,BT,WT,flag,CT,TAT;
}pro;
pro p[15];
void swap(pro *a,pro *b)
{
    pro temp=*a;
    *a=*b;
    *b=temp;
}
void sort(int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(p[j].AT>p[j+1].AT)
            {
                swap(&p[j],&p[j+1]);
            }
        }
    }
}
void main()
{
    int quantum,total_WT=0,total_TAT=0,n,tempBT[15];
    float avg_WT=0,avg_TAT=0;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("Enter the Arival time and Burst time:\n");
    printf("AT BT\n");
    for(int i=0;i<n;i++)
    {
        p[i].ID=i+1;
        scanf("%d%d",&p[i].AT,&p[i].BT);
        p[i].flag=0;
        tempBT[i]=p[i].BT;
    }
    printf("\nEnter the time quantum: ");
    scanf("%d",&quantum);
    sort(n);
    int completed=0,curIndex,curTime=p[0].AT,front=0,rear=0;
    int *queue=(int*)malloc(n*sizeof(int));
    if(queue==NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    queue[rear]=0;
    p[0].flag=1;
    while(completed!=n)
    {
        curIndex=queue[front];
        front=(front+1)%n;
        if(p[curIndex].BT>quantum)
        {
            p[curIndex].BT-=quantum;
            curTime+=quantum;
            printf("|P%d (%d) %d ",p[curIndex].ID,quantum,curTime);
        }
        else{
            curTime+=p[curIndex].BT;
            printf("|P%d (%d) %d ",p[curIndex].ID,quantum,curTime);
            p[curIndex].BT=0;
            p[curIndex].CT=curTime;
            p[curIndex].TAT=p[curIndex].CT-p[curIndex].AT;
            p[curIndex].WT=p[curIndex].TAT-tempBT[p[curIndex].ID-1];
            total_TAT+=p[curIndex].TAT;
            total_TAT+=p[curIndex].WT;
        }
        for(int i=0;i<n&&p[i].AT<=curTime;i++)
        {
            if(i==curIndex||p[i].flag==1||p[i].BT==0)
            continue;
            rear=(rear+1)%n;
            p[i].flag=1;
            queue[rear]=i;
        }
        if(p[curIndex].BT>0)
        {
            rear=(rear+1)%n;
            queue[rear]=curIndex;
        }
        else{
            completed++;
        }
    }
        avg_TAT=(float)(total_TAT)/n;
        avg_WT=(float)(total_WT)/n;
        printf("\nPID\tAT\tBT\tCT\tWT\tTAT\n");
        for(int i=0;i<n;i++)
        {
            printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].ID,p[i].AT,tempBT[i],p[i].CT,p[i].WT,p[i].TAT);
        }
        printf("Avg WT=%.2f\tAvg TAT=%.2f\n",avg_WT,avg_TAT);

    }