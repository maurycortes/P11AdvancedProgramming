//Author: Mauricio Cortés
//ID: A00816689
//Date: 13/10/2016
//Dynamic and static libraries

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

//Converts hexadecimal string to decimal int
int asciiHEXToInt(char *sHex)
{
    int iInt = 0;
    while (*sHex)
    {
        int iByte = *sHex++;
        if (iByte >= '0' && iByte <= '9') iByte = iByte - '0';
        else if (iByte >= 'a' && iByte <='f') iByte = iByte - 'a' + 10;
        else if (iByte >= 'A' && iByte <='F') iByte = iByte - 'A' + 10;
        iInt = (iInt << 4) | (iByte & 0xF);
    }
    return iInt;
}

//Converts binary string to decimal int
int asciiBINToInt(char *sBin)
{
    int iInt = 0;
    while(*sBin)
    {
        iInt *= 2;
        if (*sBin++ == '1')
            iInt += 1;
    }
    return iInt;
}

//Converts octal string to decimal int
int asciiOCTToInt(char *sOct)
{
    int iInt = 0, iIterate = 0;
    char *sAux = sOct;

    while(*sOct)
    {
        iIterate++;
        *sOct++;
    }
    while(*sAux)
    {
        iIterate--;
        iInt =  iInt + ((*sAux-48)* pow(8, iIterate));
        *sAux++;
    }
    return iInt;
}

//Divides a number by two using bit shifts
int divideByTwo(int iNumber)
{
    int iQuotient = 1, iRemainder;

    int iNeg = 1;
    if ((iNumber>0 &&2<0)||(iNumber<0 && 2>0))
        iNeg = -1;

    unsigned int iTempdividend = (iNumber < 0) ? -iNumber : iNumber;
    unsigned int iTempdivisor = (2 < 0) ? -2 : 2;

    if (iTempdivisor == iTempdividend) {
        iRemainder = 0;
        return 1*iNeg;
    }
    else if (iTempdividend < iTempdivisor) {
        if (iNumber < 0)
            iRemainder = iTempdividend*iNeg;
        else
            iRemainder = iTempdividend;
        return 0;
    }
    while (iTempdivisor<<1 <= iTempdividend)
    {
        iTempdivisor = iTempdivisor << 1;
        iQuotient = iQuotient << 1;
    }

    // Call division recursively
    if(iNumber < 0)
        iQuotient = iQuotient*iNeg + divideByTwo(-(iTempdividend-iTempdivisor));
    else
        iQuotient = iQuotient*iNeg + divideByTwo(iTempdividend-iTempdivisor);
     return iQuotient;
}

//Multiplies a number by two using bit shifts
int multByTwo(int iNumber)
{
    int iMult=2;
    unsigned int iResult = 0;

    while(iMult != 0)
    {
        if(iMult & 1)
        {
            iResult += iNumber;
        }
        iNumber <<= 1;
        iMult >>= 1;
    }
    return iResult;
}

int main()
{
    char *sHex = "123AC56A";
    char *sBin = "00101011";
    char *sOct = "24561352";
    int iDiv = 55689456;
    int iMult = 3326523;

    printf("The hexadecimal value is: %s", sHex);
    printf("\nand its decimal value is: %d\n", asciiHEXToInt(sHex));

    printf("\nThe binary value is: %s", sBin);
    printf("\nand its decimal value is: %d\n", asciiBINToInt(sBin));

    printf("\nThe octal value is: %s", sOct);
    printf("\nand its decimal value is: %d\n", asciiOCTToInt(sOct));

    printf("\nThe number to divide is: %d", iDiv);
    printf("\nand the division by 2 result is: %d\n", divideByTwo(iDiv));

    printf("\nThe number to multiply is: %d", iMult);
    printf("\nand the multiplication by 2 result is: %d\n", multByTwo(iMult));

    return 0;
}