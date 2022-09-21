/*  Author: Brian Ngeunjuntr
    Date: 3/6/22
    Class: CIS-2541
    File: ArithmeticQuiz.cpp
    Descr:
        Program designed to help an elementary school student learn addition, subtraction, division, multiplication, and modulus.
        The program will give the user a menu option and depending on their choice, will produce a problem with random values
        for the chosen arithmetic operation. The user will be able to try the same question until they get it correct.
        This program also keeps track of how many problems the user got correct for each arithmetic operation.
       
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

// Function prototypes
void showMenu();
void showSummary(int, int, int, int);
void giveProb(int ,double &);
bool verifyAnswer(double, double);
double roundDecimal(double);

int main()
{
    
    int choice;             // To hold a menu choice
    int correct = 0;        // Counter variable to hold the number of times the user answered correctly in one round
    int incorrect = 0;      // Counter variable to hold the number of times the user answered incorrectly in one round
    int total = 0;          // Counter variable to hold the total number of questions played in one round
    double userAns = 0;     // To hold the user's answer to a problem

    // Constants for the menu choices
    const int ADD = 1, SUBTRACT = 2, MULTIPLY = 3, DIVIDE = 4, MODULUS = 5, QUIT = 6;

    // Loop that keeps displaying the menu unless the user enters the value to quit the menu.
    do
    {
        // Displays the menu and gets the user's choice.
        showMenu();
        cin >> choice;

        double answer = 0; // To hold the actual answer to a problem.

        // Makes sure that a valid menu choice was entered.
        while (choice < ADD || choice > QUIT)
        {
            cout << "Please enter a valid menu choice: ";
            cin >> choice;
        }

        // If the user does not want to quit, proceed
        if (choice != QUIT)
        {
            // Depending on their choice, the user will be given a problem with the respective numerical operator.
            // All cases follow the same line of code. 
            switch (choice)
            {
                case 1 : 
                    // Makes sure that the user did not enter the value 100 to exit the questions.
                    while (userAns != 100)
                    {
                        // Displays an addition problem with random numbers from 1 through 9.
                        giveProb(ADD, answer);

                        // Stores the user's answer
                        cin >> userAns;
                        
                        // If the user's answer is incorrect, the incorrect counter is incremented. It is not incremented
                        // if the user enters the exiting value 100.
                        // The user is given the option to retry the same problem as many times as they like
                        // unless they enter 100.
                        while (!(verifyAnswer(answer, userAns)) && (userAns != 100)) 
                        {
                            // Increments the incorrect counter variable
                            incorrect++;

                            // Displays that the user's answer is wrong. Prompts them to answer the same question again 
                            // or return to the menu.
                            cout << "That is incorrect. Try again.\n"  << "Enter your answer (100 to return to the menu)\n";

                            // Stores the user's new answer
                            cin >> userAns;
                            
                        }

                        // If the user's answer is correct, the correct counter is incremented.
                        if (verifyAnswer(answer, userAns))
                        {
                            // Displays that the user's answer is correct
                            cout << "That is correct. Very good!\n";  

                            // Increments the correct counter variable
                            correct++;
                        }
                        // Increments the total questions counter variable
                        total++;
                    } 
                    // Shows a summary of 1 round of addition questions
                    showSummary (ADD, total, correct, incorrect);
                    
                    // Resets the the counter variables and user's answer variable for the next round of questions.
                    userAns = 0;
                    total = 0;
                    correct = 0;
                    incorrect = 0;
                    break;
                
                // Follows the same thought process as case 1    
                case 2 :
                    while (userAns != 100)
                    {
                        // Displays a subtraction problem with random numbers from 1 through 9.
                        giveProb(SUBTRACT, answer);

                        cin >> userAns;
                        
                        while (!(verifyAnswer(answer, userAns)) && (userAns != 100)) 
                        {
                            incorrect++;
                            cout << "That is incorrect. Try again.\n"  << "Enter your answer (100 to return to the menu)\n";
                            cin >> userAns;
                            
                        }

                        if (verifyAnswer(answer, userAns))
                        {
                            cout << "That is correct. Very good!\n";  
                            correct++;
                        }
                        total++;
                    } 
                    // Shows a summary of 1 round of subtraction questions
                    showSummary (SUBTRACT, total, correct, incorrect);

                    // Resets the variables
                    userAns = 0;
                    total = 0;
                    correct = 0;
                    incorrect = 0;
                    break;

                // Follows the same thought process as case 1    
                case 3 :
                    while (userAns != 100)
                    {
                        // Displays a multiplication problem with random numbers from 1 through 9.
                        giveProb(MULTIPLY, answer);

                        cin >> userAns;
                        
                        while (!(verifyAnswer(answer, userAns)) && (userAns != 100)) 
                        {
                            incorrect++;
                            cout << "That is incorrect. Try again.\n"  << "Enter your answer (100 to return to the menu)\n";
                            cin >> userAns;
                            
                        }

                        if (verifyAnswer(answer, userAns))
                        {
                            cout << "That is correct. Very good!\n";  
                            correct++;
                        }
                        total++;
                    } 
                    // Shows a summary of 1 round of multiplication questions
                    showSummary (MULTIPLY, total, correct, incorrect);

                    // Resets the variables
                    userAns = 0;
                    total = 0;
                    correct = 0;
                    incorrect = 0;
                    break;
                
                // Follows the same thought process as case 1
                case 4 : 
                    while (userAns != 100)
                    {
                        // Displays a division problem with random numbers from 1 through 9.
                        giveProb(DIVIDE, answer);

                        cin >> userAns;
                        
                        while (!(verifyAnswer(answer, userAns)) && (userAns != 100)) 
                        {
                            incorrect++;
                            cout << "That is incorrect. Try again.\n"  << "Enter your answer (100 to return to the menu)\n";
                            cin >> userAns;
                            
                        }

                        if (verifyAnswer(answer, userAns))
                        {
                            cout << "That is correct. Very good!\n";  
                            correct++;
                        }
                        total++;
                    } 
                    // Shows a summary of 1 round of addition questions
                    showSummary (DIVIDE, total, correct, incorrect);

                    // Resets the variables
                    userAns = 0;
                    total = 0;
                    correct = 0;
                    incorrect = 0;
                    break;
                
                // Follows the same thought process as case 1
                case 5 :
                    while (userAns != 100)
                    {
                        // Displays a modulus problem with random numbers from 1 through 9.
                        giveProb(MODULUS, answer);

                        cin >> userAns;
                        
                        while (!(verifyAnswer(answer, userAns)) && (userAns != 100)) 
                        {
                            incorrect++;
                            cout << "That is incorrect. Try again.\n"  << "Enter your answer (100 to return to the menu)\n";
                            cin >> userAns;
                            
                        }

                        if (verifyAnswer(answer, userAns))
                        {
                            cout << "That is correct. Very good!\n";  
                            correct++;
                        }
                        total++;
                    } 
                    // Shows a summary of 1 round of modulus questions
                    showSummary (MODULUS, total, correct, incorrect);

                    // Resets the variables
                    userAns = 0;
                    total = 0;
                    correct = 0;
                    incorrect = 0;
                    break;

            }
        }    


    } while (choice != QUIT);
    return 0;
}

// Definition of function showMenu which displays the menu.
void showMenu()
{
    cout << "\n\n********* Welcome to the Arithmetic Quiz *******\n\n"
         << "1. Addition \n"
         << "2. Subtraction \n"
         << "3. Multiplication \n"
         << "4. Division\n"
         << "5. Modulus\n"
         << "6. Exit\n"
         << "Enter a number corresponding to the arithmetic operator you wish to be tested on: ";

}

// Definition of function showSummary which displays the summary of a round of questions.
// The choice parameter holds the menu number the user entered. The total parameter holds the total 
// number of questions answered. The correct parameter holds the total number of correct attempts.
// The incorrect parameter holds the total number of inccorect attempts.
void showSummary(int choice, int total, int correct, int incorrect)
{
    switch(choice)
    {
        case 1 : cout << "\nAddition Problems Played: " << total << "\nNumber of times answered correctly: " << correct
                      << "\nNumber of times answered incorrectly: " << incorrect;
                break;
        case 2 : cout << "\nSubtraction Problems Played: " << total << "\nNumber of times answered correctly: " << correct
                      << "\nNumber of times answered incorrectly: " << incorrect;
                break;
        case 3 : cout << "\nMultiplication Problems Played: " << total << "\nNumber of times answered correctly: " << correct
                      << "\nNumber of times answered incorrectly: " << incorrect;
                break;
        case 4 : cout << "\nDivision Problems Played: " << total << "\nNumber of times answered correctly: " << correct
                      << "\nNumber of times answered incorrectly: " << incorrect;
                break;
        case 5 : cout << "\nModulus Problems Played: " << total << "\nNumber of times answered correctly: " << correct
                      << "\nNumber of times answered incorrectly: " << incorrect;
                break;
    }

}

// Definition of function giveProb. This function displays a problem with random single digit numbers
// between 1 and 9, inclusive and records the solution to the problem. The type of problem displayed will be respective
// of the menu option that the user chose. The c parameter holds the menu choice of the user. 
// The ans parameter is in reference to the answer variable. 
void giveProb(int c, double &ans)
{
    // Creates random nymbers between 1 and 9
    unsigned seed = time(0);
    srand(seed);

    int x = (rand() % (9 - 1 + 1)) + 1;
    int y = (rand() % (9 - 1 + 1)) + 1;

    // Each case asks a problem and records the actual solution to the problem. 
    switch (c)
    {
        case 1 : cout << "How much is " << x << " plus " << y <<"?\n" << "Enter your answer (100 to return to the menu)\n";
                 ans = x + y;
                 break;
        case 2 : cout << "How much is " << x << " minus " << y <<"?\n" << "Enter your answer (100 to return to the menu)\n";
                 ans = x - y;
                 break;
        case 3 : cout << "How much is " << x << " multiplied by " << y <<"?\n" << "Enter your answer (100 to return to the menu)\n";
                 ans = x * y;
                 break;
        case 4 : cout << "How much is " << x << " divided by " << y <<" to the nearest thousandth?\n"
                      << "Enter your answer (100 to return to the menu)\n";
                 // The decimal questions are rounded to the nearest thousandsth so they are not unbearable to do.
                 ans = roundDecimal((double)x / y);
                 break;
        case 5 : cout << "How much is the remainder of " << x << " divided by " << y <<"?\n"
                      << "Enter your answer (100 to return to the menu)\n";
                 ans = x % y;
                 break;
    }
    
}

// Definition of function roundDecimal. This function returns decimals rounded to the nearest thousandth.
// The num parameter holds the solution to a decimal question.
double roundDecimal(double num)
{
    double dec = num * 1000;

    return floor(dec + 0.5) / 1000;
}

// Definition of function verifyAnswer. This function determines whether the user's answer is equal
// to the problem's solution or not. The num parameter holds the solution to a problem. The userAns
// parameter holds the user's answer to a problem.
bool verifyAnswer(double num, double userAns)
{

    if (userAns == num)
    {
        return true;
    } 
    else
    {
        return false;
    }
       
}
