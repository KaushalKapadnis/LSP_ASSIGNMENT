#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int Mode = 0;
    struct stat sobj;

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

    stat(argv[1],&sobj);

    // if(!strcmp(Mode,sobj.st_mode))
    // {
    //     printf("unable to open file in specified mode\n");
    //     return -1;
    // }

    // printf("We can acess %s in %s mode\n",argv[1],argv[2]);

    printf("%o\n",sobj.st_mode & (S_IRUSR));
    
    // printf("\tperms: %o\n", sb.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO));

    return 0;
}