#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/resource.h>

int main()
{
    int priority = 0;

    priority = getpriority(PRIO_PROCESS,0);

    printf("Priority of process : %d\n",priority);

    return 0;
}