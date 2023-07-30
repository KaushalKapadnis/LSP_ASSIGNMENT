#include "FileSystem.h"

bool FileCmp(char file1[50], char file2[50])
{
    int fd1 = 0, fd2 = 0, Ret = 0;
    struct stat sobj1,sobj2;
    char Buffer1[BLOCKSIZE];
    char Buffer2[BLOCKSIZE];

    fd1 = open(file1,O_RDONLY);
    fd2 = open(file2,O_RDONLY);

    if(fd1 == -1 || fd2 == -1)
    {
        return false;
    }

    fstat(fd1,&sobj1);
    fstat(fd2,&sobj2);

    if(sobj1.st_size != sobj2.st_size)
    {
        return false;
    }

    while((Ret = read(fd1,Buffer1,sizeof(Buffer1))) != 0)
    {
        Ret = read(fd2,Buffer2,sizeof(Buffer2));
        
        if(memcmp(Buffer1,Buffer2,Ret) != 0)
        {
            break;
        }
    }

    if(Ret == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}