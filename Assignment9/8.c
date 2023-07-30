#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <sys/resource.h>

extern char **environ;

int main()
{
    char **env = environ;
    char *temp = NULL; 

    printf("Environment of running process is : \n");
    
    for(;*env != NULL; env++)
    {
        temp = strtok(*env,"=");
        
        if(!strcmp(temp,"HOME") || !strcmp(temp,"USER"))
        {
            temp = strtok(NULL,"=");
            printf("%s\n",temp);
        }
    }
    
    return 0;
}