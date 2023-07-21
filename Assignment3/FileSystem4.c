#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
    char path[50];
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sobj;

    if(argc != 2)
    {
        printf("Invalid Arguments\n");
        return -1;
    }

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(path,"%s/%s",argv[1],entry -> d_name);
        stat(path,&sobj);

        if(sobj.st_size == 0)
        {
            remove(path);
        }
    }

    return 0;
}