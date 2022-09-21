/*  Author: Brian Ngeunjuntr
    Date: 5/15/22
    Class: CIS-2541
    File: CompanyTimeCard.h
    Descr: 
        This program displays the Time Cards of company employees and displays the amount of money they earned for their shift.
        Demonstrates the TimeCard and Time2 class.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include "TimeCard.h"
#include "TimeCard.cpp"
#include "Time2.cpp"
using namespace std;

// Function prototype
void DisplayTimeCard(TimeCard c);

int main()
{
    // Declare Time2 Objects
    Time2 punchInTime1(8,0,0);         
    Time2 punchOutTime1(3,30,0);
    Time2 punchInTime2(8,0,0);
    Time2 punchOutTime2(4,30,0);

    // Declare TimeCard Objects
    TimeCard Card1("123456789",12.50, punchInTime1, punchOutTime1);
    TimeCard Card2("997654321", 12.50, punchInTime2, punchOutTime2);

    // Display TimeCards in Table format
    cout << left << setw(20) << "Worker ID" << setw(15) << "Start Time" << setw(15) << "End Time" << setw(15) << "Pay Rate" 
         << setw(20) << "Hours Worked" << setw(15) << "Day's Earning \n" ;
    cout << "-------------------------------------------------------------------------------------------------- \n";
    DisplayTimeCard(Card1); 
    cout << endl;
    DisplayTimeCard(Card2);
    

    return 0;
}

// Definition of DisplayTimeCard function. Displays the worker's ID, their start time, end time, pay rate, hours worked, and day's earnings.
// The c parameter references a TimeCard object.
void DisplayTimeCard(TimeCard c)
{
    // Displays the worker's ID
    cout << left << setw(20) << c.getWorkerID();

    // Displays the time that the worker punched in for work.
    c.showTimeIn();

    cout << " AM" << right << setw(6) << setfill(' ');

    // Displays the time that the worker punches out from work.
    c.showTimeOut();

    // Displays the pay rate, hours worked, and total earnings by the worker.
    cout << " PM" << right << setw(6) << setfill(' ') << "$" << setprecision(2) << fixed << showpoint << c.getPayRate() << setw(13) 
         << setfill(' ') << c.calcHoursWorked() << setw(17) 
         << "$" << setprecision(2) << fixed << showpoint <<  c.calcPay();
}