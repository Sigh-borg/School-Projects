/*  Author: Brian Ngeunjuntr
    Date: 5/15/22
    Class: CIS-2541
    File: TimeCard.cpp
    Descr: 
        Implementation file for the TimeCard class. Derived from the Time2 class.
*/

#include <iostream>
#include <iomanip>
#include "TimeCard.h"
using namespace std;

// Overloaded constructor for the TimeCard class
TimeCard::TimeCard(string ID, double r, Time2 in, Time2 out)
{
    // Initialize the private member variables.
    workerID = ID;
    payrate = r;
    punchInTime = in;
    punchOutTime = out;
};

// Definition of the getWorkerID function that returns the worker ID.
string TimeCard::getWorkerID() const
{
    return workerID;
};

// Definition of the getPayRate function that returns the pay rate.
float TimeCard::getPayRate() const
{
    return payrate;
}

// Definition of the calcHoursWorked function that calculates the total number of hours worked by the worker.
float TimeCard::calcHoursWorked() const
{
    float hIn = punchInTime.getHour();                 // holds hours when punched in
    float mIn = (punchInTime.getMinute()/60.0);        // holds minutes when punched in, calculated into hours
    float sIn = (punchInTime.getSecond()/3600.0);      // holds seconds when punched in, calculated into hours
    float hOut = punchOutTime.getHour() + 12;          // holds hours when punched out
    float mOut = (punchOutTime.getMinute()/60.0);      // holds minutes when punched in, calculated into out
    float sOut = (punchOutTime.getSecond()/3600.0);    // holds seconds when punched in, calculated into out

    // Total hours when punched in - total hours when punched out.
    float total = (hOut+mOut+sOut)-(hIn+mIn+sIn);
    return total;
}

// Definition of the calcPay function that calculates the total earnings the worker made for their shift.
float TimeCard::calcPay() const
{
    return calcHoursWorked() * payrate;
}


// Definition of the showTimeIn function that displays the punch-in time of the worker in a clock format.
void TimeCard::showTimeIn() const
{
    cout << punchInTime.getHour() << ":" << setw(2) << setfill('0') << punchInTime.getMinute() 
         << ":" << setw(2) << setfill('0') << punchInTime.getSecond(); 
}


// Definition of the showTimeIn function that displays the punch-out time of the worker in a clock format.
void TimeCard::showTimeOut() const
{
    cout << punchOutTime.getHour() << ":" << setw(2) << setfill('0') << punchOutTime.getMinute() 
         << ":" << setw(2) << setfill('0') << punchOutTime.getSecond(); 
}