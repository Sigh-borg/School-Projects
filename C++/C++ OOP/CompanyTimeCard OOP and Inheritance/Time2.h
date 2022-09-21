/*  Author: Brian Ngeunjuntr
    Date: 5/15/22
    Class: CIS-2541
    File: Time2.h
    Descr: 
        Specification file for the Time2 class.      
*/

#include <iostream>
using namespace std;
#ifndef TIME2_H
#define TIME2_H

class Time2
{
    private:
        int hour;           // Variable to hold the hours
        int minute;         // Variable to hold the minutes
        int second;         // Variable to hold the seconds
    public:
        Time2();                    // Default constructor
        Time2(int, int, int);       // Overloaded constructor       
        int getHour() const;        // Returns the hours
        int getMinute() const;      // Returns the minutes
        int getSecond() const;      // Returns the seconds

};

#endif 