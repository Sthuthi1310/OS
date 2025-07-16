#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void *sum(void *arg);
void *Mul(void *arg);
int Sum=0,mul=1;
void *sum(void *param)
{
    int i,n;
    n=atoi(param);
    printf("Inside sum thread\n");
    for(i=1;i<=n;i++)
    {
        Sum+=i;
    }
    printf("Sum done\n");
    return NULL;
}
void *Mul(void *param)
{
    int i,n;
    n=atoi(param);
    printf("Inside mul thread\n");
    for(i=2;i<=n;i++)
    {
        mul*=i;
    }
    printf("Mul done\n");
    return NULL;
}
int main(int argc,char *argv[])
{
    pthread_t T1,T2;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(&T1,&attr,sum,argv[1]);
    pthread_create(&T2,&attr,Mul,argv[1]);
    pthread_join(T1,NULL);
    pthread_join(T2,NULL);
    printf("Inside main thread\n");
    printf("Sum=%d\t Mul=%d\n",Sum,mul);
}