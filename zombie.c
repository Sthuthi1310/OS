#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
void main()
{
    pid_t mypid,parent_pid,child_pid;
    int i=10;
    child_pid=fork();
    if(child_pid<0)
    {
        printf("Fork failed\n");
        exit(0);
    }
    if(child_pid==0)
    {
        printf("[CHILD]Inside child process\n");
        mypid=getpid();
        parent_pid=getppid();
        printf("[CHILD]My pid is %d\n",mypid);
        printf("[CHILD]Parent pid is %d\n",parent_pid);
        printf("Exiting\n");
        exit(0);
    }
    else{
        printf("Inside parent process\n");
        mypid=getpid();
        parent_pid=getppid();
        printf("[PARENT]My pid is %d\n",mypid);
        printf("[PARENT]PArents pid is %d\n",parent_pid);
        printf("Sleeping for 10 seconds\n");
        sleep(10);
        printf("[Parent]Child %d has terminated.But its entry is still there in table Hence it is zombie\n",child_pid);
    }
}