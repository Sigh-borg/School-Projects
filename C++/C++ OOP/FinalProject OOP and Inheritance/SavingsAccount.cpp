/*  Author: Brian Ngeunjuntr
    Date: 5/20/22
    Class: CIS-2541
    File: SavingsAccount.cpp
    Descr: 
        Implementation file for the SavingsAccount class.      
*/

#include <iostream>
#include "SavingsAccount.h"
using namespace std;

// Overloaded constructor for the SavingsAccount class.
SavingsAccount::SavingsAccount(float i, float balance) : Account(balance)
{
    interestRate = i;
}

// Definittion of calcualteInterest function that returns the interest owed to the account.
float SavingsAccount::calculateInterest(float rate, float balance)
{
    return (rate/100) * balance;
}

// Definition of credit function that increases the balance by the amount input by the user. Overrides the Account class credit function.
void SavingsAccount::credit(float m)
{
    float money = m;
    // Input validation
    while ( (money) < 0)
    {
        cout << "Sorry, please enter a valid amount of money to deposit. \n";
        cin >> money;
    }

    // Increase the balance by the amount input by the user.
    initialBalance = initialBalance + money;

}

// Definition of debit function that decreases the balance by the amount input by the user. Overrides the Account class debit function.
void SavingsAccount::debit(float m)
{
    float money = m;
    // Input validation
    while ( (money) < 0 || (money > initialBalance))
    {
        cout << "Sorry, please enter a valid amount of money to withdraw. There is $" << getBalance() << " left in the account. \n";
        cin >> money;
    }
    
    // Decrease the balance by the amount input by the user.
    initialBalance = initialBalance - money;
}

