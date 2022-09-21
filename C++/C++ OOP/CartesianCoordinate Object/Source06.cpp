/*  Author: Brian Ngeunjuntr
    Date: 6/24/22
    Class: CIS-2542
    File: Source06.cpp
    Descr:
        Demonstrates the CartesianCoordinate2D class.
*/

#include <iostream>
#include <iomanip>
#include "CartesianCoordinate2D.h"
#include <cmath>
using namespace std;

int main()
{
    CartesianCoordinate2D a;
    CartesianCoordinate2D b(9.0, 6.0);
    CartesianCoordinate2D c(3.0, 4.0);

    CartesianCoordinate2D d = b;
    
    d = b - c;
    d -= c;
    cout << a << d << c << endl;
    if (d > c)
    {
        cout << "D";
    }
    else
        cout << "C";

    // d = b = a;
    return 0;
}