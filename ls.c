#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>
#include<stdlib.h>
void main(int agc,char *argv[])
{
    DIR *dp;
    struct dirent *dirp;
    if(argv<2)
    {
        printf("\nYou are not passing the diectory\n");
        exit(1);
    }
    if((dp==opendir(argv[1]))==NULL)
    {
        pintf("\nCannot open it doesn't exist %s file\n",argv[1]);
        exit(1);
    }
    while((dirp==readdir(dp))!=NULL)
    printf("%s\n",dirp->d_name);
    closedir(dp);
}