/*  Author: Brian Ngeunjuntr
    Date: 5/15/22
    Class: CIS-2541
    File: TimeCard.h
    Descr: 
        Specification file for the TimeCard class. Derived from the Time2 class.
*/

#include <iostream>
#include "Time2.h"
using namespace std;
#ifndef TIMECARD_H
#define TIMECARD_H

class TimeCard : public Time2
{
    private:
        string workerID;                                    // Holds the worker's ID number.
        Time2 punchInTime, punchOutTime;                    // Time2 objects.
        double payrate;                                     // Holds the hourly pay.
        bool hasPunched;                                    // Set to true after worker punches out.
    public:
        TimeCard();                                         // Default constructor.
        TimeCard (string, double , Time2, Time2);           // Overloaded constructor.
        string getWorkerID() const;                         // Returns the worker ID.
        float getPayRate() const;                           // Returns the pay rate.
        void sethasPunched();                               
        float calcHoursWorked() const;                      // Returns the total hours worked.
        float calcPay() const;                              // Returns the total pay earned by the worker.
        void showTimeIn() const;                            // Displays the time the worker punched in.
        void showTimeOut() const;                           // Displays the time the worker punched out.

};

#endif