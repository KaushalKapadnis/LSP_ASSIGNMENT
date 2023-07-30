#include "FileSystem.h"
#include<dlfcn.h>

int main(int argc, char *argv[])
{
    bool bRet = false;
    void *ptr = NULL;
    int (*fptr)(char[], char[]);

    if(argc != 3)
    {
        printf("Invalid Arguments\n");
        return -1;
    }

    ptr = dlopen("./FileSystemlibrary.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to open FileSystemlibrary.so\n");
        return -1;
    }

    fptr = dlsym(ptr,"FileCmp");
    if(fptr == NULL)
    {
        printf("Unable to load function\n");
        return -1;
    }

    bRet = fptr(argv[1], argv[2]);

    if(bRet == true)
    {
        printf("Files are Equal\n");
    }
    else
    {
        printf("Files are not same\n");
        return -1;
    }
    

    return 0;
}
