#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

#define BLOCKSIZE 4096

int main()
{
    int fd  = 0;
    int count = 0;
    int ret = 0;
    char BUFFER[BLOCKSIZE];

    fd = open("demo.txt",O_RDONLY);
    if(fd == -1)
    {
        return -1;
    }

    while((ret = read(fd,BUFFER,sizeof(BUFFER))) != 0)
    {
        for(int iCnt = 0 ; iCnt < ret; iCnt++)
        {
            if(BUFFER[iCnt] >= 'a' && BUFFER[iCnt] <= 'z')
            {
                count++;
            }
        }
    }

    fd = open("count.txt",O_WRONLY | O_APPEND);
    if(fd == -1)
    {
        return -1;
    }

    ret = write(fd,&count,sizeof(count));
    if(ret == -1)
    {
        return -1;
    }

    close(fd);

    return 0;
}