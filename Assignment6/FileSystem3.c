#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    char filename[50];

    if(argc != 3)
    {
        printf("Invalid Arguments\n");
        return -1;
    }

    sprintf(filename,"%s/%s",argv[1],argv[1]);
    fd = creat(filename,0777);

    if(fd == -1)
    {
        printf("Unable to  crete file\n");
        return -1;
    }

    printf("Succesful\n");

    return 0;
}