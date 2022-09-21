/*  Author: Brian Ngeunjuntr
    Date: 3/27/22
    Class: CIS-2541
    File: MovieStatistics.cpp
    Descr:
        Program designed to gather statistical data about the number of movies college students see in a month.
        The program will ask the user how many students were surveyed, allow the user to enter the number of
        movies each suden saw into an array, calculateand display the average, median, and mode of the values entered.
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <memory>
using namespace std;

// Function prototypes.
void getNumMovies(int * mPtr, int size);
void getAverage(int * mPtr, int size);
void selectionSort (int * mPtr, int size);
void calcMedian (int *mPtr, int size);
int calcMode(int *mPtr, int size);

int main()
{

    int numStudents;    // Variable to hold the size of the array.
    int *moviePtr = nullptr;    // Pointer array assigned to address 0.

    // Prompts the user for the number of students surveyed.
    cout << "Hello. This program gathers statistical data about the number of movies college students see in a month. \n" 
         << "How many students were surveyed?\n";
    cin >> numStudents;     // Stores the number of students surveyed.

    // Makes sure that  a valid number of students was entered.
    while (numStudents <= 0) 
    {
        cout << "Please enter a valid number. How many students were surveyed? \n";
        cin >> numStudents;
    }

    // Dynamic allocation of an array of integers to hold the number of movies watched by each student.
    moviePtr = new int[numStudents];    

    // Prompts the user to enter the number of movies watched by each student and stores them.
    getNumMovies(moviePtr, numStudents);    

    // Sorts the array of numbers of movies watched
    selectionSort(moviePtr, numStudents);

    // Displays the average number of movies watched
    cout << "The average number of movies watched is ";
    getAverage(moviePtr, numStudents);
    cout << endl;
    
    // Displays the median number of movies watched 
    cout << "The median number of movies watched is ";
    calcMedian(moviePtr, numStudents);
    cout << endl;

    // Displays the mode of the moviePtr arrray.
    if (calcMode(moviePtr, numStudents) == -1)
    {
        cout << "There is no mode. None of the values for the number of movies watched occur more than once \n";
    }
    else
    {
        cout << "The mode is " << calcMode(moviePtr, numStudents) << "\n";
    }
    
    // Frees the memory in the dynamically allocated array.
    delete [] moviePtr;

    return 0;
}

// Definition of function getNumMovies which prompts the user to enter the number of movies watched by each
// student and stores them in the moviePtr array.
// The mPtr parameter points to an int.
// The size parameter holds the size of the array.
void getNumMovies(int *mPtr, int size)
{
    int numMovies;
    for (int i = 0; i < size; i++)
    {
        // Prompts the user for the number of movies watched by each student
        cout << "How many movies did student " << (i + 1) << " watch in one month?\n";
        cin >> numMovies;

        // Validation check
        while (numMovies < 0) 
        {
            cout << "Please enter a valid number. How many movies did this student watch? \n";
            cin >> numMovies;
        }

        // Stores the number of movies of each student in the moviePtr array.
        mPtr[i] = numMovies;
    }
}

// Definition of function getAverage which displays the average number of movies watched by students in a month.
// The mPtr parameter points to an int.
// The size parameter holds the size of the array.
void getAverage(int *mPtr, int size)
{
    double total = 0.0;     // Variable to hold the total sum of the values in the array.
    double avg;             // Variable to hold the average value of the array.

    // Loops through the array and totals up all the values
    for (int i = 0; i < size; i++)
    {
        total += mPtr[i];
    }

    // Calculates the average.
    avg = total / size;
    
    // Displays the avg
    cout << avg;
}

// Definition of function selectionSort that sorts an array.
// The mPtr parameter points to an int.
// The size parameter holds the size of the array.
void selectionSort (int *mPtr, int size)
{
    int minIndex, minValue;

    // Loops through the array and moves values immediately to their final position in the array.
    for (int start = 0; start < (size - 1); start++)
    {
        minIndex = start;
		minValue = mPtr[start];
		for (int index = start + 1; index < size; index++)
		{
			if (mPtr[index] < minValue)
			{
				minValue = mPtr[index];
				minIndex = index;
			}
		}
		swap(mPtr[minIndex], mPtr[start]);

    }
}


// Definition of calcMedian that displays the median number of movies watched by students in a month.
// The mPtr parameter points to an int.
// The size parameter holds the size of the array.
void calcMedian (int *mPtr, int size)
{
    double median = 0.0;    // Variable to hold the median

    // If the size of the array is odd, then the median is the middle term.
    // If the size of the array is even, then the median is the average of the two middle terms.
    if (size % 2 != 0)
    {
        median = mPtr[size/2];
        cout << median;
    }
    else 
    {
        median = (mPtr[(size/2)-1] + mPtr[size/2])/2.0;
        cout << median;
    }
}

// Definition of function getAverage which returns the mode of the array or -1 if there is no mode.
// The mPtr parameter points to an int.
// The size parameter holds the size of the array.
int calcMode(int *mPtr, int size)
{
    int count = 1;   // Variable to hold the number of times a number appears.
    int max = 0;     // Variable to hold the maximum number of times a  number appeared.
    int mode = 1;    // Variable to hold the mode.

    // Loops through the array and compares each consecutive element.
    for (int i = 0; i < size - 1; i++)
    {
        // If consecutive elements are equal, count increases.
        if (mPtr[i] == mPtr[i+1])
        {
            count++;

            // If the number of times a number appears is greater than the current maximum number of times
            // a  number appeared, then that number becomes the new maximum, and the mode becomes the new value of
            // this maximum.
            if (count > max)
            {
                    mode = mPtr[i];
                    max = count;
                    
            }
        }
        else
        {
            // Resets the count variable for the next different value in the array.
            count = 1;
        }
    }

    // If none of the values in the array occur more than once, return -1. Otherwise, return the mode.
    if (max == 0)
    {
        return -1;
    }
    else 
    {
        return mode;
    }
}