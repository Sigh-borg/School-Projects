/*  Author: Brian Ngeunjuntr
    Date: 5/8/22
    Class: CIS-2541
    File: Invoice.cpp
    Descr:
        Implementation file for the Invoice class. 
        
*/

#include <iostream>
#include <string>
#include "Invoice.h"
using namespace std;

// Definition of Constructor for the Invoice class.
Invoice::Invoice(int num, string d, int q, float p)
{
    // Initialize the private members.
    partNum = num;
    partDescr = d;
    quantity = q;
    price = p;
}

// Definition of getNum function that returns part number.
int Invoice::getNum() const
{
    return partNum;
}

// Definition of getDescr function that returns the part desceription.
string Invoice::getDescr() const
{
    return partDescr;
}

// Definition of getQuantity function that returns the quantity of the part.
int Invoice::getQuantity() const
{
    return quantity;
}

// Definition of getPrice function that returns the price of the part.
float Invoice::getPrice() const
{
    return price;
}

// Definition of the getTotal function that returns the total price of the part.
float Invoice::getTotal() const
{
    return price*quantity;
}



