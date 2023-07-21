#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc, char *argv[])
{
    char path1[50];
    char path2[50];

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
        sprintf(path1,"%s/%s",argv[1],entry -> d_name);
        sprintf(path2,"%s/%s",argv[2],entry -> d_name);

        rename(path1,path2);        
    }

    return 0;
}