/*  Author: Brian Ngeunjuntr
    Date: 6/24/22
    Class: CIS-2542
    File: CartesianCoordinate2D.h
    Descr:
        Specification file for the CartesianCoordinate2D class.
*/

#pragma once
#include <iostream>
using namespace std;

class CartesianCoordinate2D
{
private:
    double XCoord;
    double YCoord;

public:
    CartesianCoordinate2D(double x = 0.0, double y = 0.0);
    CartesianCoordinate2D(const CartesianCoordinate2D& obj);
    
    double GetXCoordinate() const;
    double GetYCoordinate() const;

    void SetXCoordinate(double x);
    void SetYCoordinate(double y);

    double GetDistance() const;
    int GetQuadrant() const;

    CartesianCoordinate2D &operator = (const CartesianCoordinate2D &right);
    CartesianCoordinate2D operator - (const CartesianCoordinate2D &right);
    CartesianCoordinate2D &operator -= (const CartesianCoordinate2D &right);

    friend ostream &operator << (ostream& strm, const CartesianCoordinate2D &right);
    
    bool operator > (const CartesianCoordinate2D &right);

};