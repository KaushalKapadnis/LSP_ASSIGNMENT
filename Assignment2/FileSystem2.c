#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    char Buffer[20] = {'\0'};

    if(argc != 2)
    {
        printf("Invalid Argument\n");
        return -1;
    }

    fd = open(argv[1],O_WRONLY);

    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    printf("enter string\n");
    scanf("%s",Buffer);

    write(fd,Buffer,20);

    close(fd);

    return 0;
}