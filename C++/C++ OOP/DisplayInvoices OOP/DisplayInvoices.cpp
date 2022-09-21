/*  Author: Brian Ngeunjuntr
    Date: 5/8/22
    Class: CIS-2541
    File: DisplayInvoices.cpp
    Descr:
        This program displays a list of invoices sorted in different ways and demonstrates the Invoice class.
        
*/

#include <iostream>
#include <string>
#include <iomanip>
#include "Invoice.h"
#include "Invoice.cpp"
using namespace std;

// Function Prototypes
void displayInvoices(Invoice array[], int size);
void SortByDescr(Invoice array[], int size);
void SortByPrice (Invoice array[], int size);
void SortByTotals(Invoice array[], int size);
void displayTotals(Invoice array[], int size);


int main()
{
    // Initialize an array of Invoice ojects.
    Invoice invoices [] = 
    {
          Invoice( 83, "Electric sander", 7, 57.98 ),
          Invoice( 24, "Power saw", 18, 99.99 ),
          Invoice( 7, "Sledge hammer", 11, 21.5 ),
          Invoice( 77, "Hammer", 76, 11.99 ),
          Invoice( 39, "Lawn mower", 3, 79.5 ),
          Invoice( 68, "Screwdriver", 106, 6.99 ),
          Invoice( 56, "Jig saw", 21, 11.00 ),
          Invoice( 3, "Wrench", 34, 7.5 )
    };

    // Size of the array of Invoice ojects.
    int arrSize = sizeof(invoices)/sizeof(invoices[0]);

    // Displays the array of Invoice objects sorted by description, in alphabetical order.
    cout << "Here are the invoices sorted by description in ascending order: \n";
    SortByDescr(invoices, arrSize);         // Sorts the array by description.
    displayInvoices(invoices, arrSize);     // Displays the array

    // Displays the array of Invoice objects sorted by price, in descending order.
    cout << "Here are the invoices sorted by price in descending order: \n";
    SortByPrice(invoices, arrSize);         // Sorts the array by price.
    displayInvoices(invoices, arrSize);     // Displays the array

    // Displays the array of Invoice objects sorted by total price, in ascending order.
    cout << "Here are the invoices sorted by the total prices in ascending order: \n";
    SortByTotals(invoices, arrSize);        // Sorts the array by total price.
    displayTotals(invoices, arrSize);       // Displays the array


    return 0;
}


// Definition of displayInvoices function that displays the array.
// The array parameter references an array of Invoice objects.
// The size parameter holds the size of the array.
void displayInvoices(Invoice array[], int size)
{

    // For each element in the array, display the object's part number, part description, quantity, and price.
    for (int i = 0; i < size; i++ )
    {
        cout << right << setw(2) << array[i].getNum() << " "
             << left << setw(15) << array[i].getDescr()
             << right << setw(4) << array[i].getQuantity()
             << right << "  $" << setprecision(2) << fixed << showpoint << array[i].getPrice() << " \n";
        
    }
    cout << endl;

}

// Defintion of SorByDescr function that uses a selection sort to sort the array by description.
// The array parameter references an array of Invoice objects.
// The size parameter holds the size of the array.
void SortByDescr(Invoice array[], int size)
{
    // Selection Sort in Ascending Order
    
	int minIndex;       // Holds the index that the minimum element will be moved to.
    string minDescr;    // Holds the part description of an element that is earliest in the alphabet
	
    // Finds the element with its part description being earliest in the alphabet and places it at the minimum boundary.
    // Augments the minimum boundary after each iteration.
	for (int start = 0; start < (size - 1); start++)
	{
		minIndex = start;
		minDescr = array[start].getDescr();
		for (int i = start + 1; i < size; i++)
		{
            // Find the minimum element (the element with the part description earliest in the alphabet) in the array.
			if (array[i].getDescr() < minDescr)
			{
				minDescr = array[i].getDescr();
				minIndex = i;
			}
		}
        // Swaps the found minimum element with the first element 
		swap(array[minIndex], array[start]);
	}

}

// Defintion of SorByPrice function that uses an insertion sort to sort the array by price.
// The array parameter references an array of Invoice objects.
// The size parameter holds the size of the array.
void SortByPrice (Invoice array[], int size)

// Insertion Sort in Descending Order
{
    int i, j;       // Counter variables
    float val;      // Holds the price of the  Invoice object that is currently being moved to its rightful place.
    Invoice temp;   // Holds the  Invoice object that is currently being moved to its rightful place.

    // For each element in the array, move the object to its rightful place in descending order.
    for (i = 1; i < size; i++)
    {
        temp = array[i];
        val = array[i].getPrice();
        j = i - 1;
 
        // Move all elements that have prices
        // lower than val, to one position ahead
        // of their current position 
        while (j >= 0 && array[j].getPrice() < val)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
}

// Defintion of SorByTotals function that uses an insertion sort to sort the array by total price.
// The array parameter references an array of Invoice objects.
// The size parameter holds the size of the array.
void SortByTotals(Invoice array[], int size)
{
    // Selection Sort in Ascending Order
    
	int minIndex;       // Holds the index that the minimum element will be moved to.
    float minTotal;     // Holds the minimum total price of an element.
	
    // Finds the element with the minimum total price and places it at the minimum boundary.
    // Augments the minimum boundary after each iteration.
	for (int start = 0; start < (size - 1); start++)
	{
		minIndex = start;
		minTotal = array[start].getTotal();

        // Find the element with the minimum total price of the array.
		for (int i = start + 1; i < size; i++)
		{
			if (array[i].getTotal() < minTotal)
			{
				minTotal = array[i].getTotal();
				minIndex = i;
			}
		}
        // Swaps the found minimum element with the first element.
		swap(array[minIndex], array[start]);
	}

}

// Defintion of displayTotals that displays the array with just their description and price totals.
// The array parameter references an array of Invoice objects.
// The size parameter holds the size of the array.
void displayTotals(Invoice array[], int size)
{
    // For each element in the array, display the object's part description and price total.
    for (int i = 0; i < size; i++ )
    {
        cout << left << setw(15) << array[i].getDescr()
             << right << "  $" << setprecision(2) << fixed << showpoint << array[i].getTotal() << " \n";
    }
}


