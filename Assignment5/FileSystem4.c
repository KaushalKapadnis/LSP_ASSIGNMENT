#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{  
    int fd1 = 0,fd2 = 0,ret = 0;
    char Buffer[BLOCKSIZE];
    char filename[50];
    DIR *dp = NULL;
    struct dirent *entry = NULL; 
    struct stat sobj;

    if(argc != 2)
    {
        printf("Invalid Arguments\n");
        return -1;
    }

    fd1 = creat("Allcombine.txt",0777);
    if(fd1 == -1)
    {
        printf("Unable to create file\n");
        return -1;
    }

    fd1 = open("Allcombine.txt",O_WRONLY);
    if(fd1 == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unabel to open directory\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(filename,"%s/%s",argv[1],entry -> d_name);
        stat(filename,&sobj);

        if(!S_ISREG(sobj.st_mode))
        {
            continue;
        }
        fd2 = open(filename,O_RDONLY);
        if(fd2 == -1)
        {
            printf("Unable to open file\n");
            break;
        }

        while((ret = read(fd2,Buffer,sizeof(Buffer))) != 0)
        {
            write(fd1,Buffer,sizeof(Buffer));
        }
    }   

    if(entry != NULL)
    {
        printf("ERROR\n");
        return -1;
    }
    else
    {
        printf("SUCCESSFUL\n");
    }

    return 0;
}