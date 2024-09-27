// simple array introduction -- prints the days for each month 
// PROG71990 F24 - Professor SteveH - Oct 2024
//
// borrowed from textbook

#include <stdio.h>

#define MONTHS 12
#define LEAPYEAR 1

int main(void)
{
    int days[MONTHS] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    int anotherDays[MONTHS];
    int index;

    if (LEAPYEAR)
        days[1] = 29;

    //anotherDays = days;  *NOT ALLOWED
    
    //days[13] = 5;  *OUT of BOUNDS

    for (index = 0; index < MONTHS; index++)\
    {
        anotherDays[index] = days[index];  //loop to copy
        printf("Month %d has %2d days.\n", index + 1, days[index]);
    }


    return 0;
}