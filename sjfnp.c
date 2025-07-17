#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int ID,AT,BT,CT,TAT,RT,WT,finished;
}process;
void sjfnp(process[],int);
void main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    process p[n];
    printf("Enter the arrival time and burst time:\n");
    printf("AT BT\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&p[i].AT,&p[i].BT);
        p[i].finished=0;
        p[i].ID=i+1;
    }
    sjfnp(p,n);
    return;
}
void sjfnp(process p[],int n)
{
    int totaltat=0,totalwt=0,totalrt=0,et=0,exec,temp,rem=n;
    float avgwt,avgrt,avgtat;
    printf("Gantt chart\n");
    while(rem)
    {
        exec=-1;
        int shortestbursttime=9999;
        for(int i=0;i<n;i++)
        {
            if(!p[i].finished&&p[i].AT<=et)
            {
                if(p[i].BT<=shortestbursttime)
                {
                    exec=i;
                    shortestbursttime=p[i].BT;
                }
            }
        }
        if(exec==-1)
        {
            printf("|(%d)***(%d)",et,et+1);
            et++;
        }
        else{
            temp=et;
            p[exec].RT=et-p[exec].AT;
            et+=p[exec].BT;
            p[exec].finished=1;
            p[exec].CT=et;
            rem--;
            p[exec].TAT=p[exec].CT-p[exec].AT;
            p[exec].WT=p[exec].TAT-p[exec].BT;
            printf("|%d p%d (%d)",temp,p[exec].ID,et);
        }
    }
    printf("|\n");
     printf("Observation table\n");
     printf("ID\tAT\tBT\tCT\tTAT\tBT\tWT\tRT\n");
     for(int i=0;i<n;i++)
     {
         printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].ID,p[i].AT,p[i].BT,p[i].CT,p[i].TAT,p[i].BT,p[i].WT,p[i].RT);
         totaltat+=p[i].TAT;
         totalwt+=p[i].WT;
         totalrt+=p[i].RT;
     }
     avgrt=(float)totalrt/n;
     avgwt=(float)totalwt/n;
     avgtat=(float)totaltat/n;
     printf("AVG TAT %.2f Avg WT %.2f Avg RT %.2f\n",avgtat,avgwt,avgrt);

}