#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc, char *argv[])
{
    char path[50];
    DIR *dp = NULL;
    struct dirent *entry = NULL;

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(path,"%s/%s",argv[1],argv[2]);

        if(strcmp(entry -> d_name,argv[2]) == 0)
        {
            break;
        }
    }

    if(entry == NULL)
    {
        printf("File Not Found\n");
    }
    else
    {
        printf("File Found\n");
    }

    return 0;
}