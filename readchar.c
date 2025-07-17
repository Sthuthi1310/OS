#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#define BUFFER_SIZE 30
int main()
{
    int fd=open("grep.c",O_RDWR),n;
    char buffer[BUFFER_SIZE];
    printf("FIEL DESCRIPTOR is %d\n",fd);
    if(fd==-1)
    {
        printf("Failed to open file\n");
        exit(0);
    }
    printf("Reading first 10 characters from the file\n");
    n=read(fd,buffer,10);
    write(1,buffer,n);
    printf("\nSkipping 5 character feom current position\n");
    lseek(fd,5,SEEK_CUR);
    n=read(fd,buffer,10);
    write(1,buffer,n);
    printf("Goint to 10 chars before current position\n");
    lseek(fd,-10,SEEK_CUR);
    n=read(fd,buffer,6);
    write(1,buffer,n);
    printf("Going to 3rd character in file\n");
    lseek(fd,3,SEEK_SET);
    n=read(fd,buffer,10);
    write(1,buffer,n);
    return 0;
}