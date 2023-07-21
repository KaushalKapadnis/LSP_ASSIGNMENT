#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char* argv[])
{
    int fd = 0;
    int Mode = 0;

    if(argc != 3)
    {
        printf("Invalid Argument \n");
        return -1;
    }

    if(!strcmp(argv[2],"Read"))
    {
        Mode = O_RDONLY;
    }
    else if(!strcmp(argv[2],"Write"))
    {
        Mode = O_WRONLY;
    }
    else if(!strcmp(argv[2],"ReadWrite"))
    {
        Mode = O_RDWR;
    }
    else
    {
        printf("Enter Valid Mode\n");
        return -1;
    }

    fd = open(argv[1],Mode);

    if(fd == -1)
    {
        printf("Failed to open file\n");
        return -1;
    }

    printf("Successfull\n");

    return 0;
}