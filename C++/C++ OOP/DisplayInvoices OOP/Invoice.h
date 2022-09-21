/*  Author: Brian Ngeunjuntr
    Date: 5/8/22
    Class: CIS-2541
    File: Invoice.h
    Descr: 
        Specification file for the invoice class.
        This has a default constructor and an overloaded constructor.
        
*/

#include <iostream>
using namespace std;
#ifndef INVOICE_H
#define INVOICE_H

class Invoice
{
    private:
        int partNum;            // Variable to hold the part number.
        string partDescr;       // String variable to hold the part description.
        int quantity;           // Variable to hold the part quantity.
        float price;            // Variable to hold the price of the part.
    public:
        Invoice(int num = 0, string d = "", int q = 0, float p = 0.0);      // Default/Overloaded constructor
        int getNum() const;             // Returns the part number.
        string getDescr() const;        // Returns the part description
        int getQuantity() const;        // Returns the part quantity.
        float getPrice() const;         // Returns the price of the part.
        float getTotal() const;         // Returns the total cost of the part.
        
};

#endif