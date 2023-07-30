#include<dlfcn.h>
#include<stdlib.h>
#include<fcntl.h>
#include "Arithmatic.h"

int main()
{   
    void *ptr = NULL;
    int (*fptr)(int, int);
    int iRet = 0;

    ptr = dlopen("./library.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to open so file\n");
        return -1;
    }

    fptr = dlsym(ptr,"Add");
    if(fptr == NULL)
    {
        printf("Unable to load function\n");
        return -1;
    }

    iRet = fptr(10,11);
    printf("Addtion is : %d\n",iRet);

    return 0;
}