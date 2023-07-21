#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[])
{   
    int fd = 0,ret = 0;
    char Buffer[21];

    if(argc != 3)
    {
        printf("Invalid Arguments\n");
        return -1;
    }

    fd = open(argv[1],O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open File\n");
        return -1;
    }
 
    ret = lseek(fd,atoi(argv[2]),SEEK_SET);
    if(ret == -1)
    {
        printf("Unable set file offset to desired location\n");
        return -1;
    }

    ret = read(fd,Buffer,sizeof(Buffer));
    if(ret == -1)
    {
        printf("Unable to read file\n");
        return -1;
    }

    printf("%s\n",Buffer);
    
    return 0;
}