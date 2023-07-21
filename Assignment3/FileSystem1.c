#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{

    int fd1 = 0, fd2 = 0, ret = 0;
    char Buffer[BLOCKSIZE] = {'\0'};

    if(argc != 3)
    {
        printf("Invalid Aruments\n");
        return -1;
    } 

    if(access(".",F_OK) == 0)
    {
        printf("Destination file already exist\nPlease provide different name\n");
        return -1;
    }

    creat(argv[2],0777);
   
    fd1 = open(argv[1],O_RDONLY);
    fd2 = open(argv[2],O_WRONLY);

    if(fd1 == -1 || fd2 == -1)
    {
        printf("unable to opon file\n");
        return -1;
    }

    while((ret = read(fd1,Buffer,sizeof(Buffer))) != 0)
    {
        write(fd2,Buffer,ret);
    }

    close(fd1);
    close(fd2);

    return 0;
}