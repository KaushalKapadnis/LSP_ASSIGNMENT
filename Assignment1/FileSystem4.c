#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat sobj;

    if(argc != 2)
    {
        printf("Invalid argument\n");
        return 0;
    }

    stat(argv[1],&sobj);

    ////printf("%A\n",sobj.st_mode);
    printf("Inode : %d\n",sobj.st_ino);
    printf("Link : %d\n",sobj.st_nlink);
    printf("UID : %d\n",sobj.st_uid);    
    printf("GID : %d\n",sobj.st_gid);
    printf("Size : %d\n",sobj.st_size);
    printf("Block Size : %d\n",sobj.st_blksize);
    
    return 0;
}