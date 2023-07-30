#include "external.h"

int Fact(int iNo)
{
    int iAns = 0;

    void *ptr = dlopen("./internallib.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        return 0;
    }

    int (*fptr)(int) = dlsym(ptr,"factorial");
    if(fptr == NULL)
    {
        return 0;
    }

    iAns = fptr(iNo);

    return iAns;
}