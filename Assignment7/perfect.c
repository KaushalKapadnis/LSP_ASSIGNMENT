#include "perfect.h"

bool ChkPerfect(int iNo)
{
    int iSum = 0;

    for(int iCnt = 1; iCnt <= (iNo / 2);iCnt++)
    {
        if(iNo % iCnt == 0)
        {
            iSum = iSum + iCnt;
        }
    }

    if(iSum == iNo)
    {
        return true;
    }
    else
    {
        return false;
    }
}
