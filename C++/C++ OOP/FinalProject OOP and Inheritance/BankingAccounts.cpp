/*  Author: Brian Ngeunjuntr
    Date: 5/20/22
    Class: CIS-2541
    File: BankingAccounts.cpp
    Descr: 
        This program represents bank customer accounts. All the bank customers can deposit(Credit) money into their 
        account and/or withdraw (debit) money from their account. This program demonstrates the Account class, SavingsAccount
        class, and Checking Account class.      
*/

#include <iostream>
#include "Account.h"
#include "Account.cpp"
#include "SavingsAccount.h"
#include "SavingsAccount.cpp"
#include "CheckingAccount.h"
#include "CheckingAccount.cpp"
#include <vector>
using namespace std;

// Function prototype
void displayMenu();

const int QUIT = 4; // Constant to hold the option to quit the menu.

int main()
{
    std::vector<Account*> accounts;

    
    int choice; // Holds the menu option input from the user.
    int count;  // Counts how many accounts are in the bank system.
    int index;  // Holds the account number of which the user wishes to operate on.

    // Variables to hold various inputs from the user for each account
    float withdraw;
    float deposit;
    float fee;
    float interestRate;
    float initialBalance;

    do
    {
        displayMenu();

        cout << "Enter a number corresponding to option you wish to proceed with: ";
        cin >> choice;

        // Input validation.
        while ((choice <  1) || (choice > QUIT))
        {
            cout << "Please enter a valid menu choice: ";
            cin >> choice;
        }

         // If the user does not want to quit, proceed.
        if (choice != QUIT)
        {
            // Proceeds with a menu option depending on the user's input.
            switch (choice)
            {
                // If the user inputs 1, create an Account object.
                case 1:
                    cout << "Enter 1 to create a Checking Account or Enter 2 to create a Savings Account. \n";
                    cin >> choice;

                    // Input validation
                    while ((choice <  1) || (choice > 2))
                    {
                        cout << "Please enter 1 or 2 \n";
                        cin >> choice;
                    }

                    // If user inputs 1, create a checking account
                    if (choice == 1)
                    {
                        count++;    // Records number of accounts
                        cout << "You chose to create a Checking Account. \n";

                        // Prompt and store the fee of the CheckingAccount object.
                        cout << "What is the fee that is paid for using the checking account? \n";
                        cin >> fee;

                        // Input Validation.
                        while (fee <= 0 )
                        {
                            cout << "Please enter a fee above $0 \n";
                            cin >> fee;
                        }

                        // Prompt and store the initial balance of the CheckingAccount object
                        cout << "What is the initial balance of the account? \n";
                        cin >> initialBalance;

                        // Input validation
                        while (initialBalance < 0)
                        {
                            cout << "Please enter a nonnegative balance \n";
                            cin >> initialBalance;
                        }

                        // Create a CheckingAccount object.
                        accounts.push_back(new CheckingAccount(fee, initialBalance));
                        cout << endl;

                        // Display the CheckingAccount object
                        cout << "Account Number " << count << " is a Checking Account. \n";
                        cout << "The initial balance is $" << (accounts)[count-1]->getBalance() << endl;
                        cout << "There will be a fee of $" << fee << " every time it is accessed. \n";
                    }

                    // If user inputs 2, create a savings account
                    if (choice == 2)
                    {
                        count++;    // Records number of accounts
                        cout << "You chose to create a Savings Account. \n";

                        // Prompt and store the interest of the SavingsAccount object
                        cout << "What is the percentage interest for this savings account? For example, 25 means 25% interest rate. \n";
                        cin >> interestRate;

                        // Input validation.
                        while (interestRate < 0 )
                        {
                            cout << "Please enter an interest rate of at least 0 or greater. \n";
                            cin >> interestRate;
                        }

                        // Prompt and store the initial balance of the SavingsAccount object
                        cout << "What is the initial balance of the account? \n";
                        cin >> initialBalance;

                        // Input validation.
                        while (initialBalance < 0)
                        {
                            cout << "Please enter a nonnegative balance";
                            cin >> initialBalance;
                        }

                        // Create a SavingsAccount object
                        accounts.push_back(new SavingsAccount(interestRate, initialBalance));
                        cout << endl;

                        // Display the SavingsAccount object
                        cout << "Account Number " << count << " is a Savings Account. \n";
                        accounts[count-1]->credit(accounts[count -1]->calculateInterest(interestRate, initialBalance));
                        cout << "The initial balance is $" << accounts[count-1]->getBalance() << endl;
                        cout << "after an interest of $" << accounts[count-1]->calculateInterest(interestRate, initialBalance) << " has been added. \n";
                    }
                    cout << endl;
                    break;


                // If user inputs 2, allow the user to withdraw money from one of the Account objects.
                case 2:

                    // Do not allow the user to withdraw money if there are no accounts in the system.
                    if (count == 0)
                    {
                        cout << "\n Sorry, but there are no accounts in the system yet. Please create an account. \n";
                        break;
                    }

                    // Prompt and store the account number that the user wishes to withdraw from.
                    cout << "Which account number would you like to withdraw from? Enter a number starting at 1: ";
                    cin >> index;

                    // Input validation
                    while (index < 0 || index > count)
                    {
                        cout << "Sorry, there are only " << count << " accounts in the system. Please enter an appropriate account number. \n";
                        cin >> index;
                    }

                    // Display the account that the user selected
                    cout << "You have selected Account " << index << endl;
                    cout << "Balance: $" << accounts[index-1]->getBalance() << endl;

                    // Prompt and store how much money the user wishes to withdraw.
                    cout << "How much would you like to withdraw? \n";
                    cin >> withdraw;

                    // Withdraw money from the account.
                    accounts[index-1]->debit(withdraw);

                    // Display the account
                    cout << "\nThe new balance is: $" << accounts[index-1]->getBalance() << "\n\n";
                    break;


                // If user inputs 3, allow the user to deposit money into one of the Account objects.
                case 3:

                    // Do not allow the user to deposit money if there are no accounts in the system.
                    if (count == 0)
                    {
                        cout << "\n Sorry, but there are no accounts in the system yet. Please create an account. \n";
                        break;
                    }

                    // Prompt and store the account number that the user wishes to deposit money into.
                    cout << "Which account number would you like to deposit money into? Enter a number starting at 1: ";
                    cin >> index;

                    // Input validation.
                    while (index < 0 || index > count)
                    {
                        cout << "Sorry, there are only " << count << " accounts in the system. Please enter an appropriate account number. \n";
                        cin >> index;
                    }

                    // Display the account that the user selected
                    cout << "You have selected Account " << index << endl;
                    cout << "Balance: $" << accounts[index-1]->getBalance() << endl;

                    // Prompt and store how much money the user wishes to deposit.
                    cout << "How much would you like to deposit? \n";
                    cin >> deposit;

                    // Deposit money into the account.
                    accounts[index-1]->credit(deposit);

                    // Display the account
                    cout << "\nThe new balance is: $" << accounts[index-1]->getBalance() << "\n\n";
                    break;
            }

            // If the user inputs 4, quit the menu and the program.
        }
    } while (choice != QUIT);
    


return 0;
}

// Displays the menu
void displayMenu()
{
    cout << "Welcome to the Bank Account System \n";
    cout << "1. Create an Account \n";
    cout << "2. Withdraw \n";
    cout << "3. Deposit \n";
    cout << "4. QUIT \n";

}