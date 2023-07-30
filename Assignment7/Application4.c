#include "prime.h"
#include "perfect.h"
#include <dlfcn.h>

int main()
{
    void *ptr = NULL;
    bool(*fptr)(int);
    int iRet = 0, iNo = 4;

    ptr = dlopen("./externallib.so",RTLD_LAZY);
    if(ptr == false)
    {
        printf("Unable to load so file\n");
        return -1;
    }

    fptr = dlsym(ptr,"Fact");
    if(fptr == false )
    {
        printf("Unable to load function\n");
        return -1;
    }

    iRet = fptr(iNo);

    printf("Factorial of %d is : %d\n",iNo,iRet);

    return 0;
}