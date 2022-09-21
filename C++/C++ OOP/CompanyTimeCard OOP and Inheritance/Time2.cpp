/*  Author: Brian Ngeunjuntr
    Date: 5/15/22
    Class: CIS-2541
    File: Time2.cpp
    Descr: 
        Implementation file for the Time2 class.
*/

#include <iostream>
#include "Time2.h"
using namespace std;

// Default constructor for the Time2 class
Time2::Time2()
{
}

// Overloaded consturctor for the Time2 class.
Time2::Time2(int h, int m, int s)
{
    hour = h;
    minute = m;
    second = s;
}

// Definition of getHour function that returns hours
int Time2::getHour() const
{
    return hour;
}

// Definition of getMinute function that returns minutes
int Time2::getMinute() const
{
    return minute;
}

// Definition of getSecond function that returns seconds
int Time2::getSecond() const
{
    return second;
}