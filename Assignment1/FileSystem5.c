#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
    int fd = 0;
    char *Buffer = NULL;

    if(argc != 3)
    {
        printf("Invalid Arguments\n");
        return -1;
    }

    fd = open(argv[1],O_WRONLY);

    if(fd == -1)
    {
        printf("Unable to open File\n");
        return -1;
    }

    Buffer = (char*)malloc(argv[2]);

    read(fd,argv[2],Buffer);

    printf("%s\n",Buffer);

    return 0;
}