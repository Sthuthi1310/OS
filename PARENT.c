#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/mman.h>
#include<sys/wait.h>
#include<sys/stat.h>
int main(int argc,char *argv[])
{
    int i,k,n1,n2,n3,shmid;
    const int size=4096;
    void *ptr;
    pid_t pid;
    shmid=shmget((key_t)1122,4096,0666|IPC_CREAT);
    ptr=shmat(shmid,NULL,0666);
    if(argc>1)
    {
        sscanf(argv[1],"%d",&i);
        if(i<1)
        {
            printf("Error input %d \n",i);
            return 0;
        }
    }
    else{
        return 1;
    }
    pid=fork();
    if(pid==0)
    {
        excelp("./fib","fib",argv[1],NULL);
    }
    else if(pid>0)
    {
        wait(NULL);
        printf("\nParent :child completed\n");
        pintf("%s",(char*)ptr);
        shmdt(ptr);
    }
    return 0;
}