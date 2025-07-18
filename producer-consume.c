#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>
#define maxitems 3
#define buffersize 3
sem_t empty;
sem_t full;
int in=0;
int out=0;
int buffer[buffersize];
pthread_mutex_t mutex;
void *producer(void*pno)
{
    int item;
    for(int i=0;i<maxitems;i++)
    {
        item=rand()%100;
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        buffer[in]=item;
        printf("Producer %d : insert %d at %d\n",*(int*)pno,buffer[in],in);
        in=(in+1)%buffersize;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
    return NULL;
}
void *consumer(void *cno)
{
    int item;
    for(int i=0;i<maxitems;i++)
    {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        item=buffer[out];
        printf("Consumer %d remove %d from %d\n",*(int*)cno,item,out);
        out=(out+1)%buffersize;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
    return NULL;
}
int main()
{
    pthread_t pro[3],con[3];
    pthread_mutex_init(&mutex,NULL);
    sem_init(&empty,0,buffersize);
    sem_init(&full,0,0);
    int a[3]={1,2,3};
    for(int i=0;i<3;i++)
    {
        pthread_create(&pro[i],NULL,(void*)producer,(void*)&a[i]);
    }
    for(int i=0;i<3;i++)
    {
        pthread_create(&con[i],NULL,(void*)consumer,(void*)&a[i]);
    }
    for(int i=0;i<3;i++)
    {
        pthread_join(pro[i],NULL);
    }
    for(int i=0;i<3;i++)
    {
        pthread_join(con[i],NULL);
    }
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
}