/*  Author: Brian Ngeunjuntr
    Date: 5/20/22
    Class: CIS-2541
    File: CheckingAccount.h
    Descr: 
        Specification file for the CheckingAccount class.      
*/

#include <iostream>
#include "Account.h"
using namespace std;

#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

class CheckingAccount : public Account
{
    private:
        float fee;      // Variable to hold the fee 
    public:
        CheckingAccount(float = 0, float = 0);              // Overloaded constructor
        void credit(float);                                 // Increases the initial balance
        void debit(float);                                  // Decreases the initial balance
        float getFee();                                     // Returns the fee
        virtual float calculateInterest(float, float);      

};



#endif
