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
            execl("./CountCapital","NULL",NULL);
            break;
    }

    iRet = fork();

    switch(iRet)
    {
        case -1:
            printf("Unable to crete Child Process\n");
            break;
        
        case 0:
            execl("./CountSmall","NULL",NULL);
            break;
    }

    printf("Parent Ends\n");

    return 0;
}