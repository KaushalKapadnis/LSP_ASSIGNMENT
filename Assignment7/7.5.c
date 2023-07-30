#include<dlfcn.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include "./Library_Files/Stat.c"

int main(int argc , char * argv[])
{
    Stat(argv[1]);

    return 0;
}