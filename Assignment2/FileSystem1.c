#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    int fd = 0;
    int ret = 0;
    char Buffer[BLOCKSIZE];

    if(argc != 2)
    {
        printf("Invalid Arguments \n");
        return -1;
    }

    fd = open(argv[1],O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    while((ret = read(fd,Buffer,BLOCKSIZE)) != 0)
    {
        printf("%s",Buffer);
    }

    close(fd);

    return 0;
}