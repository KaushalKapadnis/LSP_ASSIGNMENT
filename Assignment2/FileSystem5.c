#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int max = 0;
    char filename[50];
    char path[20];
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

        if(S_ISREG(sobj.st_mode))
        {
            if(max < sobj.st_size)
            {
                max = sobj.st_size;
                strcpy(path,entry -> d_name);
            }
        }
        else
        {
            printf("%s\n",path);
            continue;
        }
    }

    printf("%20s : %10d\n",path,max);

    closedir(dp);
    
    return 0;
}