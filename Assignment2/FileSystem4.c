#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    char filename[50];
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sobj;

    if(argc != 2)
    {
        printf("Invalid Arguments\n");
        return -1;
    }

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {   
        sprintf(filename,"%s/%s",argv[1],entry -> d_name);
        stat(filename,&sobj);

        printf("%20s : ",entry -> d_name);
        if(S_ISDIR(sobj.st_mode))
        {
            printf("Directory File\n");
        }
        else if(S_ISREG(sobj.st_mode))
        {
            printf("Regular File\n");
        }
        else if(S_ISLNK(sobj.st_mode))
        {
            printf("Symbolic Link\n");
        }
    }

    closedir(dp);
    
    return 0;
}