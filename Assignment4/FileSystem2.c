#include<stdio.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
    int dirfd = 0;

    if(argc != 2)
    {
        printf("Invalid Arguments\n");
        return -1;
    }

    dirfd = mkdir(argv[1],0777);
    if(dirfd == -1)
    {
        printf("Unable to create directory file\n");
        return -1;
    }

    return 0;
}