/*  Author: Brian Ngeunjuntr
    Date: 5/20/22
    Class: CIS-2541
    File: SavingsAccount.h
    Descr: 
        Specification file for the SavingsAccount class.      
*/

#include <iostream>
#include "Account.h"
using namespace std;

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

class SavingsAccount : public Account
{
    private:
        float interestRate;             // Variable to hold the interest rate
        float interest;                 // Variable to hold the interest owed to the account
    public:
        SavingsAccount(float = 0, float = 0);               // Overloaded constructor
        virtual float calculateInterest(float, float);      // returns the interest
        virtual void credit(float);                         // Increases the initial balance
        virtual void debit(float);                          // Decreases the initial balance
};


#endif