/*  Author: Brian Ngeunjuntr
    Date: 5/20/22
    Class: CIS-2541
    File: Account.cpp
    Descr: 
        Implementation file for the Account class.      
*/

#include <iostream>
#include "Account.h"
using namespace std;

// Overloaded constructor for the Account class.
Account::Account(float i)
{
    initialBalance = i;     
}

// Definition of getBalance function that returns the balance
float Account::getBalance() const
{
    return initialBalance;
}

// Definition of credit function that increases the balance by the amount input by the user.
void Account::credit(float m)
{
    initialBalance = initialBalance + m;
}

// Definition of debit function that decreases the balance by the amount input by the user.
void Account::debit(float money)
{
    // Input validaiton
    if (initialBalance > 0)
    {
        initialBalance = initialBalance - money;
    } 
    else 
    {
        cout << "There is no money left in the account to withdraw.";
    }
}

// Function meant to be overriden
float Account::calculateInterest(float, float)
{
    return 0;
}