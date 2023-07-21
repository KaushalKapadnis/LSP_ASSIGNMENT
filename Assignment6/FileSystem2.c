#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{  
    int fd = 0, ret = 0;
    char Buffer[BLOCKSIZE];

    if(argc != 2)
    {
        printf("Invalid Arguments\n");
        return -1;
    }

    fd = open(argv[1],O_WRONLY);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    ret = lseek(fd,0,SEEK_END);
    if(ret == -1)
    {
        printf("Unable to st file offset\n");
        return -1;
    }

    ret  = write(fd,Buffer,sizeof(Buffer));
    if(ret == -1)
    {
        printf("Unalbe to make hole in file\n");
        return-1;
    }

    close(fd);

    return 0;
}