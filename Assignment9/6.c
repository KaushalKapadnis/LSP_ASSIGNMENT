#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/resource.h>
#include<sched.h>

int main()
{
    sched_yield();
    
    return 0;
}