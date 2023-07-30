#include<stdio.h>
#include<unistd.h>

int main()
{
    int iRet = 0;

    iRet = fork();

    switch(iRet)
    {
        case -1:
            printf("Unable to crete Child Process\n");
            break;
        
        case 0:
            execl("./ChildProcess","NULL",NULL);
            break;
    }

    printf("Parent Ends\n");

    return 0;
}