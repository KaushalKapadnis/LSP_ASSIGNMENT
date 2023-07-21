#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
    int fd1 = 0,fd2 = 0,ret = 0;
    char path[50];
    char Buffer[11];
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

    if(creat("Demo.txt",0777) == -1)
    {
        printf("Unable to create Demo.txt\n");
        return -1;
    }

    fd2 = open("Demo.txt",O_WRONLY);
    if(fd2 == -1)
    {
        printf("Unable to open Demo.txt\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(path,"%s/%s",argv[1],entry -> d_name);
        stat(path,&sobj);

        if(!S_ISREG(sobj.st_mode))
        {
            continue;
        }

        fd1 = open(path,O_RDONLY);
        if(fd1 == -1)
        {
            printf("Unable to open %s file\n",entry->d_name);
            break;
        }

        ret = read(fd1,Buffer,sizeof(Buffer));
        
        write(fd2,Buffer,ret);
    }

    if(entry == NULL)
    {
        printf("Successfully copied 10 bytes to file\n");
    }
    else
    {
        return -1;
    }


    return 0;
}