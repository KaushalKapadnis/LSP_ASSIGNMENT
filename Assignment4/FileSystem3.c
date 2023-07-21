#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{   
    int fd1 = 0, fd2 = 0,ret = 0;
    char Buffer1[BLOCKSIZE], Buffer2[BLOCKSIZE];
    struct stat sobj1;
    struct stat sobj2;

    if(argc != 3)
    {
        printf("Invalid Arguments\n");
        return -1;
    }

    fd1 = open(argv[1],O_RDONLY);
    fd2 = open(argv[2],O_RDONLY);

    if(fd1 == -1 || fd2 == -1)
    {
        printf("Unable to open one of file\n");
        return -1;
    }

    stat(argv[1],&sobj1);
    stat(argv[2],&sobj2);

    if(sobj1.st_size != sobj2.st_size)
    {
        printf("Files are Diffrent\n");
        return -1;
    }

    while((ret = read(fd1,Buffer1,sizeof(Buffer1))) != 0)
    {
        ret = read(fd2,Buffer2 ,sizeof(Buffer2));

        if(memcmp(Buffer1,Buffer2,ret) == -1)
        {
            break;
        }
    }

    if(ret == 0)
    {
        printf("Files are same\n");
    }
    else
    {
        printf("Files are not same\n");
        return -1;
    }

    return 0;
}