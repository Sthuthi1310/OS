#include<stdio.h>
#include<string.h>
void main()
{
    char fn[100],pat[100],temp[200];
    FILE *fp;
    printf("Enter the file name: ");
    scanf("%s",fn);
    printf("ENter the pattern to be searched: ");
    scanf("%s",pat);
    fp=fopen(fn,"r");
    while(!feof(fp))
    {
        fgets(temp,100,fp);
        if(strstr(temp,pat))
        printf("%s",temp);
    }
    fclose(fp);
}