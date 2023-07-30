#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>

int main()
{   
    int fd = 0;
    DIR *dp = NULL;
    struct dirent *entry = NULL;

    fd = creat("demo.txt",0777);
    if(fd == -1)
    {
        printf("Unable to create demo\n");
        return -1;
    }

    dp = opendir("/home/kaushal/Desktop");
    if(dp == NULL)
    {
        printf("Unable to open Desktop directory\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        write(fd,entry -> d_name,sizeof(entry -> d_name));
    }

    return 0;
}