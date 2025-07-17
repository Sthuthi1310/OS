#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
    pid_t child_pid,parent_pid,mypid;
    int i=10;
    child_pid=fork();
    if(child_pid<0)
    {
        printf("Fork failed\n");
            exit(0);
    }
    if(child_pid==0)
    {
        printf("[CHILD]This is child process\n");
        mypid=getpid();
        parent_pid=getppid();
        printf("[CHILD]MY pid %d\n",mypid);
        printf("[CHILD]PArent pid %d\n",parent_pid);
        printf("[CHILD]Sleeping for 10 seconds\n");
        sleep(10);
        printf("[CHILD]My parent ended.So i am an orphan process adopted by init process\n");
    }
    else{
        printf("[PARENT]THis is parent process\n");
        mypid=getpid();
        parent_pid=getppid();
        printf("[PARENT]My pid %d\n",mypid);
        printf("[PARENT]PArent pid %d\n",parent_pid);
        printf("[PAENT]Exiting..\n");
        exit(0);
    }
    return 0;
}