/*  Author: Brian Ngeunjuntr
    Date: 5/20/22
    Class: CIS-2541
    File: Account.h
    Descr: 
        Specification file for the Account class.      
*/

#include <iostream>
using namespace std;

#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
    protected:
        float initialBalance;                   // Variable to hold the initial balance
        void inputValidation() const;           // Input validation function.
    public:
        Account () {};                                      // Default constructor
        Account (float);                                    // Overloaded constructor
        virtual float getBalance() const;                   // Return the initial balance
        virtual void credit(float);                         // Increases the initial balance
        virtual void debit(float);                          // Decreases the initial balance
        virtual float calculateInterest(float, float);      // Function meant to be overriden.


};

#endif