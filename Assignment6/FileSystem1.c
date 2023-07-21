#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc,char **argv)
{
    int fd = 0;

    if(argc != 2)
    {
        printf("Invalid Arguments\n");
        return -1;
    }

    fd = open(argv[1],O_RDONLY);
    if(fd == -1)
    {
        printf("Unab;e to open file\n");
        return -1;
    }

    return 0;
}