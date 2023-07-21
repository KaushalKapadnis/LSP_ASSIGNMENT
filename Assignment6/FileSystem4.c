#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    int fd = 0,ret = 0;
    char filename[50];
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sobj;

    if(argc != 2)
    {
        printf("Insufficient arguments\n");
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
        sprintf(filename,"%s/%s",argv[1],entry -> d_name);
        stat(filename,&sobj);
        
        if(sobj.st_size > 100)
        {
            remove(filename);
        }                                            
    }

    if(entry != NULL)
    {
        printf("Failed\n");
        return -1;
    }

    closedir(dp);
    close(fd);

    return 0;
}