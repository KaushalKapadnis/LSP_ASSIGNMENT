#include<stdio.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
    int fd = 0;

    fd = open(argv[1],O_RDONLY);

    if(fd == -1)
    {
        printf("Failed\n");
    }

    printf("Succesful\n");

    printf("%d\n",O_RDONLY);

    return 0;
}