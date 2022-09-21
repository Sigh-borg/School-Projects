/*  Author: Brian Ngeunjuntr
    Date: 5/20/22
    Class: CIS-2541
    File: CheckingAccount.cpp
    Descr: 
        Implementation file for the CheckingAccount class.      
*/

#include <iostream>
#include "CheckingAccount.h"
using namespace std;

// Overloaded constructor for the CheckingAccount class.
CheckingAccount::CheckingAccount(float f, float balance) : Account(balance)
{
    fee = f;
}


// Definition of credit function that increases the balance by the amount input by the user. Overrides the Account class credit function.
void CheckingAccount::credit(float m)
{
    float money = m;

    // Input validation
    while ( (money-fee) <= 0)
    {
        cout << "Sorry, please enter a valid amount of money to deposit. Please take into consideration of the $" << getFee() << " fee. \n";
        cin >> money;
    }

    money = money - fee;
    // Increase the balance by the amount input by the user.
    initialBalance = initialBalance + money;
    cout << "A fee of $" << fee << " has been charged. \n"; 
}

// Definition of getFee function that returns the fee
float CheckingAccount::getFee()
{
    return fee;
}

// Definition of debit function that decreases the balance by the amount input by the user. Overrides the Account class debit function.
void CheckingAccount::debit(float m)
{
    float money = m;

    // Input validation
    while ((money - fee) <= 0 || (money + fee) > initialBalance)
    {
        cout << "Please enter a proper balance to withdraw from the account. Please take into consideration of the $" << getFee() << " fee. \n";
        cin >> money;
    }
    money = money + fee;

    // Decrease the balance by the amount input by the user.
    initialBalance = initialBalance - money;
    cout << "A fee of $" << fee << " has been charged. \n"; 
}

// Unused function
float CheckingAccount::calculateInterest(float rate, float balance)
{
    cout << "There is no interest for a Checking Account. \n";
    return 0;
}