/*  Author: Brian Ngeunjuntr
    Date: 3/13/22
    Class: CIS-2541
    File: EmployeeDatabase.cpp
    Descr:
        Program designed to record the data of employees. The program will prompt the user and record employee names, employee
        IDs, employee hours worked, and employee pay rate. This program will give the user a menu with options to 
        display all employee information, search for a specific employee's information, display a report of all employees
        based on lastname or ID, calculate the total pay to employees, and quit the program.
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

// Function prototypes
void showMenu();
void getData(string first[], string last[], int id[], int hours[], double pay[],  int size);
void printReport(string first[], string last[], int id[], int hours[], double pay[], double totalPay[],  int size);
void getTotalPay (int hours[], double pay[], double totalPay[], int size);
double getAvgHoursWorked (int hours[], int size);
void searchEmployee (string first[], string last[], int id[], int hours[], double pay[], double totalPay[],  int size);
void sortByID(string first[], string last[], int id[], int hours[], double pay[], double totalPay[],  int size);
void displaySortedByID (string first[], string last[], int id[], int hours[], double pay[], double totalPay[],
                        int elements[],  int size);
void sortByLastName(string first[], string last[], int id[], int hours[], double pay[], double totalPay[],  int size);
void displaySortedByLastName (string first[], string last[], int id[], int hours[], double pay[], double totalPay[],
                              int elements[],  int size);
void totalCompanyWages (int id[], int hours[], double pay[], double totalPay[], int size);

// Global constant for the size of the arrays
const int NUM_EMPLOYEES = 5;

int main()
{
    // Uncomment the following code and comment out everything from string firstName[NUM_EMPLOYEES];
    // through getData(firstName, lastName, employeeId, hoursWorked, payRate, NUM_EMPLOYEES); to skip
    // the intro process.
    
    string firstName[] = { "Brian", "David", "Kathy", "Janet", "Steve"};
    string lastName[] = {"Adams", "Eisenhower", "Jones", "Williams", "Bradford"};
    int employeeId[] = {612366, 957654, 123456, 245695, 245690};
    int hoursWorked[] = {36, 38, 43, 39, 39};
    double payRate[] = {10, 10, 10, 10, 10, 10};
    double totalPay[NUM_EMPLOYEES];
    
   /*
   // Declare arrays to hold employee information.
    string firstName[NUM_EMPLOYEES];
    string lastName[NUM_EMPLOYEES];
    int employeeId[NUM_EMPLOYEES];
    int hoursWorked[NUM_EMPLOYEES];
    double payRate[NUM_EMPLOYEES];
    double totalPay[NUM_EMPLOYEES];

    // Program intro
    cout << "\nWelcome to the Employee Database Program \n"
         << "The database will hold information on a total of 5 employees. \n"
         << "Before we can proceed, please enter the following employee information: \n";
    cout << endl;

    // Prompts the user employee information
    getData(firstName, lastName, employeeId, hoursWorked, payRate, NUM_EMPLOYEES);
    */
    // Gets the total pay of each employee and stores it in the totalPay array
    getTotalPay(hoursWorked, payRate, totalPay, NUM_EMPLOYEES);

    // Constants for the menu choices
    const int PRINT = 1, SEARCH = 2, SORTED = 3, CALCPAY = 4, QUIT = 5;


    int choice;         // To hold a menu choice
    int goBack = 0;     // Holds 0 or -1. Will be used to determine whether program returns back to the menu.
    int reply = 0;      // Used to decide whether menu option 3 will sort by last name or by ID number.

    // Loop that keeps displaying the menu unless the user enters the value to quit the menu.
    do 
    {
        // Displays the menu and gets the user's choice.
        showMenu();

        cin >> choice;


        // Makes sure that a valid menu choice was entered.
        while (choice < PRINT || choice > QUIT)
        {
            cout << "Please enter a valid menu choice: ";
            cin >> choice;
        }

        // If the user does not want to quit, proceed.
        if (choice != QUIT)
        {
            // Depending on their choice, the program will respond with a different report.
            switch (choice)
            {

                case 1 : 
                    // Displays all employee information in a data chart.
                    printReport(firstName, lastName, employeeId, hoursWorked, payRate, totalPay, NUM_EMPLOYEES);
                    cout << endl;

                    // Displays the average number of hours workedby employees.
                    cout << "Average Hours Worked: " << getAvgHoursWorked(hoursWorked, NUM_EMPLOYEES) << " Hours per Week";
                    cout << endl;
                    
                    // Prompts user to return back to the menu.
                    cout << "Enter -1 to return to the menu. \n";
                    cin >> goBack;
                    while (goBack != -1)
                    {
                        cout << "Enter -1 to return to the menu. \n";
                        cin >> goBack;
                    }
                    goBack = 0;
                    break;
                
                case 2 :
                    // Searches for a specific employee by last name and ID number and displays all of their information.
                    searchEmployee(firstName, lastName, employeeId, hoursWorked, payRate, totalPay, NUM_EMPLOYEES);
                    
                    // Prompts user to return back to the menu.
                    cout << "Enter -1 to return to the menu. \n";
                    cin >> goBack;
                    while (goBack != -1)
                    {
                        cout << "Enter -1 to return to the menu. \n";
                        cin >> goBack;
                    }
                    goBack = 0;
                    break;
                
                case 3 :
                    // Prompts user whether they want the employee report to be displayed as sorted by ID number or by last name
                    cout << "Would you like to sort by 1. ID Number or 2. Last Name?\n"
                         << "Enter 1 or 2. \n";
                    cin >> reply;
                    while (reply < 1 || reply > 2)
                    {
                        cout << "Enter a valid choice. \n";
                        cin >> reply;
                    }
                    if (reply == 1) 
                    {
                        // Displays all employee information sorted by ID number from lowest to highest.
                        sortByID(firstName, lastName, employeeId, hoursWorked, payRate, totalPay, NUM_EMPLOYEES);
                    }
                    else 
                    {
                        // Displays all employee information sorted by last name in alphabetical order.
                        sortByLastName(firstName, lastName, employeeId, hoursWorked, payRate, totalPay, NUM_EMPLOYEES);
                    }
                    reply = 0;

                    // Prompts user to return back to the menu.
                    cout << "Enter -1 to return to the menu. \n";
                    cin >> goBack;
                    while (goBack != -1)
                    {
                        cout << "Enter -1 to return to the menu. \n";
                        cin >> goBack;
                    }
                    goBack = 0;

                    break;
                
                case 4 :
                    // Displays employee information pertaining to the total amount of spent on employees.
                    totalCompanyWages(employeeId, hoursWorked, payRate, totalPay, NUM_EMPLOYEES);

                    // Prompts user to return back to the menu.
                    cout << "Enter -1 to return to the menu. \n";
                    cin >> goBack;
                    while (goBack != -1)
                    {
                        cout << "Enter -1 to return to the menu. \n";
                        cin >> goBack;
                    }
                    goBack = 0;

                    break;
            } 
        }
    } while (choice != QUIT);
}

// Definition of function showMenu which displays the menu.
void showMenu()
{
    cout << "\n\n\n********* Employee Database Program *******\n\n"
         << "1. Employee Report \n"
         << "2. Search for an Employee \n"
         << "3. Sorted Employee Report \n"
         << "4. Calculate the Pay \n"
         << "5. Quit\n"
         << "Enter a number corresponding to the option you desire: ";

}

// Definition of function getData which prompts the user for all of the Employee information and stores it in the arrays.
// The first parameter references the firstName array.
// The last parameter references the lastName array.
// The id parameter references the employeeID array.
// The hours parameter references the hoursWorked array.
// The pay parameter references the payRate array.
// The size parameter holds the size of the arrays.
void getData(string first[], string last[], int id[], int hours[], double pay[],  int size)
{
    for (int index = 0; index < size; index++)
    {
	    cout << "Enter the following data for employee #" << index + 1 << "\n";
        cout << "First Name: ";
        cin >> first[index];
        cout << "Last Name: ";
        cin >> last[index];
        cout << "ID Number: ";
        cin >> id[index];
        cout << "Hours Worked: ";
        cin >> hours[index];
        cout << "Hourly Pay Rate: $";
        cin >> pay[index];
        cout << endl;


    }
}

// Definition of function printReport which displays all of the employee information in a formulated 
// employee report data chart.
// The first parameter references the firstName array.
// The last parameter references the lastName array.
// The id parameter references the employeeID array.
// The hours parameter references the hoursWorked array.
// The pay parameter references the payRate array.
// The totalPay parameter references the totalPay array.
// The size parameter holds the size of the arrays.
void printReport(string first[], string last[], int id[], int hours[], double pay[], double totalPay[],  int size)
{
    cout << "\n\nEmployee Report:\n";
    cout << left << setw(20)<< "First Name" << setw(20) << "Last Name" << setw(20) << "ID Number" << setw(20)
         << "Hours Worked" << setw(20) << "Hourly Rate" << setw(20) << "Total Pay";
    cout << "\n";
    
    for (int index = 0; index < size; index++) 
    {
        cout << left << setw(20) << first[index] << setw(20) << last[index] << setw(20) << id[index]
             << setw(20) << hours[index] << "$" << setw(20) << fixed << setprecision (2) << pay[index] << "$" 
             << setw(20) << totalPay[index] << fixed << setprecision(0) << "\n";
    }
}

// Definition of function getTotalPay which determines the total amount of pay to each employee, and stores it 
// in the totalPay array.
// The hours parameter references the hoursWorked array.
// The pay parameter references the payRate array.
// The totalPay parameter references the totalPay array.
// The size parameter holds the size of the arrays.
void getTotalPay (int hours[], double pay[], double totalPay[], int size)
{
    for (int index = 0; index < size; index++)
    {
        totalPay[index] = hours[index] * pay[index];
    }
}

// Definition of function getAvgHoursWorked which returns the average number of hours worked by employees.
// The hours parameter references the hoursWorked array.
// The size parameter holds the size of the arrays.
double getAvgHoursWorked (int hours[], int size)
{
    int total = 0;
    double avg;
    // Calculates the total number of hours worked by employees
    for (int index = 0; index < size; index++)
    {
        total += hours[index];
    }
    // Calculates the average nymber of hours worked by employees.
    avg = total / size;

    return avg;
}

// Definition of function searchEmployee that prompts the user to enter the last name and ID number of the desired employee.
// It will return all of the information on the employee if the entered information matches the stored information.
// Otherwise, it will return an error message saying that the desired employee could not be found.
// The first parameter references the firstName array.
// The last parameter references the lastName array.
// The id parameter references the employeeID array.
// The hours parameter references the hoursWorked array.
// The pay parameter references the payRate array.
// The totalPay parameter references the totalPay array.
// The size parameter holds the size of the arrays.
void searchEmployee (string first[], string last[], int id[], int hours[], double pay[], double totalPay[],  int size)
{
    int idNum;
    string lastName;
    cout << "Enter the following to search for an employee: \n";
    cout << "Last Name: ";
    cin >> lastName;
    cout << "ID Number: ";
    cin >> idNum;
    cout << endl;

    for (int index = 0; index < size; index++)
    {
        if (last[index] == lastName && id[index] == idNum)
        {
            cout << "Here is the data on employee #" << index + 1 << "\n";
            cout << "First Name: " << first[index] << "\n";
            cout << "Last Name: " << last[index] << "\n";
            cout << "ID Number: " << id[index] << "\n";
            cout << "Hours Worked: " << hours[index] << "\n";
            cout << "Hourly Pay Rate: $" << fixed << setprecision(2) << pay[index] << "\n";
            cout << "Total Pay: $" << totalPay[index] << "\n" << fixed << setprecision(0);
            return;
        }
    }
    cout << "Employee unable to be found\n";
    
}

// Definition of function sortByID which sorts all of the employee information by ID Number. 
// This function does not affect the data in the original arrays.
// This function contains the function displaySortedByID to display the sorted employee report.
// The first parameter references the firstName array.
// The last parameter references the lastName array.
// The id parameter references the employeeID array.
// The hours parameter references the hoursWorked array.
// The pay parameter references the payRate array.
// the totalPay parameter references the totalPay array.
// The size parameter holds the size of the arrays.
void sortByID(string first[], string last[], int id[], int hours[], double pay[], double totalPay[],  int size)
{
    int sortID[NUM_EMPLOYEES];
    int elements[5] = {0, 1, 2, 3, 4};
    int minIndex, minValue;

    for (int i = 0; i < size; i++)
    {
        sortID[i] = id[i];
    }

    // Selection sort
    for (int start = 0; start < size-1; start++)
    {
        minIndex = start;
        minValue = sortID[start];
        for (int index = start + 1; index < size; index++)
        {
            if (sortID[index] < minValue)
            {
                minValue = sortID[index];
                minIndex = index;
            }
        }
        swap(sortID[minIndex], sortID[start]);
        swap(elements[minIndex], elements[start]);
       
    }

    displaySortedByID (first, last, sortID, hours, pay, totalPay, elements, size);
}

// Definition of function displaySortedByID which displays all of the employee information in a formulated
// empl0yee report sorted by ID Number (smallest to largest).
// The first parameter references the firstName array.
// The last parameter references the lastName array.
// The id parameter references the employeeID array.
// The hours parameter references the hoursWorked array.
// The pay parameter references the payRate array.
// The totalPay parameter references the totalPay array.
// The size parameter holds the size of the arrays.
// The elements parameter references the elements array from function sortByID
void displaySortedByID (string first[], string last[], int id[], int hours[], double pay[], double totalPay[],
                        int elements[],  int size)
{
    cout << "\n\nEmployee Report Sorted by ID Number:\n";
    cout << left << setw(20)<< "First Name" << setw(20) << "Last Name" << setw(20) << "ID Number" << setw(20)
         << "Hours Worked" << setw(20) << "Hourly Rate" << setw(20) << "Total Pay";
    cout << "\n";
    
    for (int i= 0; i < size; i++) 
    {
        cout << left << setw(20) << first[elements[i]] << setw(20) << last[elements[i]] << setw(20) << id[i]
             << setw(20) << hours[elements[i]] << "$" << setw(20) << fixed << setprecision (2) << pay[elements[i]] << "$" 
             << setw(20) << totalPay[elements[i]] << fixed << setprecision(0) << "\n";
    }
}

// Definition of function sortByLastName which sorts all of the employee information by last name. 
// This function does not affect the data in the original arrays.
// This function contains the function displaySortedByLastName to display the sorted employee report.
// The first parameter references the firstName array.
// The last parameter references the lastName array.
// The id parameter references the employeeID array.
// The hours parameter references the hoursWorked array.
// The pay parameter references the payRate array.
// The totalPay parameter references the totalPay array.
// The size parameter holds the size of the arrays.
void sortByLastName(string first[], string last[], int id[], int hours[], double pay[], double totalPay[],  int size)
{
    string sortLast[NUM_EMPLOYEES]; // To create an array of the lastName array sorted by last name 
    int elements[5] = {0, 1, 2, 3, 4}; // Array to keep track of the original index points of the unsorted array.
    int minIndex;
    string minValue;
    
    for (int i = 0; i < size; i++)
    {
        sortLast[i] = last[i];
    }

    // Selection sort
    for (int start = 0; start < size-1; start++)
    {
        minIndex = start;
        minValue = sortLast[start];
        for (int index = start + 1; index < size; index++)
        {
            if (sortLast[index] < minValue)
            {
                minValue = sortLast[index];
                minIndex = index;
            }
        }
        swap(sortLast[minIndex], sortLast[start]);
        swap(elements[minIndex], elements[start]);
       
    }

    displaySortedByLastName (first, sortLast, id, hours, pay, totalPay, elements, size);
}

// Definition of function displaySortedByLastName which displays all of the employee information in a formulated
// empl0yee report sorted by last name in alphabetical order.
// The first parameter references the firstName array.
// The last parameter references the lastName array.
// The id parameter references the employeeID array.
// The hours parameter references the hoursWorked array.
// The pay parameter references the payRate array.
// The totalPay parameter references the totalPay array.
// The size parameter holds the size of the arrays.
// The elements parameter references the elements array from function sortByLastName
void displaySortedByLastName (string first[], string last[], int id[], int hours[], double pay[], double totalPay[],
                              int elements[],  int size)
{
    cout << "\n\nEmployee Report Sorted by Last Name:\n";
    cout << left << setw(20)<< "First Name" << setw(20) << "Last Name" << setw(20) << "ID Number" << setw(20)
         << "Hours Worked" << setw(20) << "Hourly Rate" << setw(20) << "Total Pay";
    cout << "\n";
    
    for (int i= 0; i < size; i++) 
    {
        cout << left << setw(20) << first[elements[i]] << setw(20) << last[i] << setw(20) << id[elements[i]]
             << setw(20) << hours[elements[i]] << "$" << setw(20) << fixed << setprecision (2) << pay[elements[i]] << "$" 
             << setw(20) << totalPay[elements[i]] << fixed << setprecision(0) << "\n";
    }
}

// Definition of function totalCompanyWages that displays the total hours worked by employees,
// the total wage rate, and the total amount of wages given to employees.
// The id parameter references the employeeID array.
// The hours parameter references the hoursWorked array.
// The pay parameter references the payRate array.
// The totalPay parameter references the totalPay array.
// The size parameter holds the size of the arrays.
void totalCompanyWages (int id[], int hours[], double pay[], double totalPay[], int size)
{
    double totalWages = 0;
    double totalHours = 0;
    double totalHourly = 0;

    for (int i = 0; i < size; i++)
    {
        totalWages += totalPay[i];
        totalHours += hours[i];
        totalHourly += pay[i];
    }

    cout << "\n\nTotal Company Wages:\n";
    cout << left << setw(20) << "ID Number" << setw(20) << "Hours Worked" << setw(20) << "Hourly Rate" << setw(20) << "Total Pay";
    cout << "\n";
    for (int index = 0; index < size; index++) 
    {
        cout << left << setw(20) << id[index] << setw(20) << hours[index] << "$" << setw(20) << fixed << setprecision (2) 
             << pay[index] << "$" << setw(20) << totalPay[index] << fixed << setprecision(0) << "\n";
    }

    cout << "Employees worked a total of " << totalHours << " hours.\n";
    cout << "Employees were paid at a total rate of $" << fixed << setprecision(2) << totalHourly << " per hour.\n"
         << fixed << setprecision(0);
    cout << "The total amount of money paid out to employees was $" << fixed << setprecision(2) << totalWages << fixed 
         << setprecision(0) << ".\n";

}




