#include "internal.h"

int factorial(int iNo)
{
    int iFact = 1;

    for(int i = 1; i <= iNo; i++)
    {
        iFact = iFact * i;
    }

    return iFact;
}