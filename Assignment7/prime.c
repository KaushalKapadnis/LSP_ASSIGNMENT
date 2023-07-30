#include "prime.h"

bool ChkPrime(int iNo)
{
    int iCnt = 1;

    for(iCnt = 2; iCnt <= iNo / 2;iCnt++)
    {
        if(iNo % iCnt == 0)
        {
            break;
        }
    }

    if(iCnt > iNo / 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}