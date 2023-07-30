#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    int iRet = 0;

    switch(iRet = fork())
    {
        case -1:
            printf("Unable to create child process\n");
            exit(1);

        case 0:
            printf("Child process exited\n");
            break;

        default:
            wait(NULL);
            printf("Parent Process Exited\n");
            break; 
    }

    return 0;
}