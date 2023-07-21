#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>

#pragma pack(1)

struct FileInfo
{
    char fname[50];
    int isize;
    int inode;
    int blksize;
};

int main(int argc, char *argv[])
{
    int fd = 0,ret = 0;
    char filename[50];
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sobj;
    struct FileInfo fobj;

    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    fd = creat("info.txt",0777);
    if(fd == -1)
    {
        printf("Unable to create file\n");
        return -1;
    }

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    fd = open("info.txt",O_RDWR);
    if(fd == -1)
    {
        printf("Unable to open file\n");
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

        fobj.isize = sobj.st_size;
        fobj.blksize = sobj.st_blksize;
        fobj.inode = sobj.st_ino;
        strcpy(fobj.fname,filename);

        write(fd,&fobj,sizeof(fobj));
    }

    // fd = open("info,txt",O_RDONLY);

    // while(ret = read(fd,&fobj,sizeof(&fobj)))
    // {
    //     printf("%s\n",fobj.fname);
    //     printf("%d\n",fobj.isize);
    //     printf("%d\n",fobj.blksize);
    //     printf("%d\n",fobj.inode);

    // }

    closedir(dp);
    close(fd);

    return 0;
}