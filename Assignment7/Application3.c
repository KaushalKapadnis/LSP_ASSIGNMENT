#include "prime.h"
#include "perfect.h"
#include <dlfcn.h>

int main()
{
    void *ptr1 = NULL;
    void *ptr2 = NULL;

    bool(*fptr1)(int);
    int(*fptr2)(int);

    bool bRet1 = false;
    int bRet2 = false;

    ptr1 = dlopen("./primelib.so",RTLD_LAZY);
    ptr2 = dlopen("./perfectlib.so",RTLD_LAZY);

    if(ptr1 == false || ptr2 == false)
    {
        printf("Unable to load so file\n");
        return -1;
    }

    fptr1 = dlsym(ptr1,"ChkPrime");
    fptr2 = dlsym(ptr2,"ChkPerfect");

    if(fptr1 == false || fptr2 == false)
    {
        printf("Unable to load function\n");
        return -1;
    }

    bRet1 = fptr1(6);
    bRet2 = fptr2(30);

    if(bRet1 == true)
    {
        printf("Prime Number\n");
    }
    else
    {
        printf("Not a Prime Number \n");
    }

    if(bRet2 == true)
    {
        printf("Perfect Number\n");
    }
    else
    {
        printf("Not a Perfect Number\n");
    }

    return 0;
}