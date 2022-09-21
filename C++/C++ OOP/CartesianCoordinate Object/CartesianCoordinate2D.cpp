/*  Author: Brian Ngeunjuntr
    Date: 6/24/22
    Class: CIS-2542
    File: CartesianCoordinate2D.cpp
    Descr:
        Implementation file for the CartesianCoordinate2D class.
*/

#include <iostream>
#include "CartesianCoordinate2D.h"
#include <cmath>
using namespace std;

CartesianCoordinate2D::CartesianCoordinate2D(double x, double y)
    : XCoord(x), YCoord(y)
{
}

CartesianCoordinate2D::CartesianCoordinate2D(const CartesianCoordinate2D& obj)
    : CartesianCoordinate2D(obj.XCoord, obj.YCoord)
{
}

double CartesianCoordinate2D::GetXCoordinate() const
{
    return XCoord;
}

double CartesianCoordinate2D::GetYCoordinate() const
{
    return YCoord;
}

void CartesianCoordinate2D::SetXCoordinate(double x)
{
    XCoord = x;
}

void CartesianCoordinate2D::SetYCoordinate(double y)
{
    YCoord = y;
}

double CartesianCoordinate2D::GetDistance() const
{
    return sqrt((XCoord * XCoord) + (YCoord * YCoord));
}

int CartesianCoordinate2D::GetQuadrant() const
{
    if (XCoord > 0)
    {
        if (YCoord > 0)
        {
            return 1;
        }
        else if (YCoord < 0)
        {
            return 4;
        }
        return 0;
    }

    if (XCoord < 0)
    {
        if (YCoord > 0)
        {
            return 2;
        }
        else if (YCoord < 0)
        {
            return 3;
        }
        return 0;
    }

    return 0;
}



CartesianCoordinate2D& CartesianCoordinate2D::operator=(const CartesianCoordinate2D& right)
{
    if (this != &right)
    {
        XCoord = right.XCoord;
        YCoord = right.YCoord;
    }

    return *this;
}

CartesianCoordinate2D CartesianCoordinate2D::operator - (const CartesianCoordinate2D& right)
{
    CartesianCoordinate2D temp;

    temp.XCoord = XCoord - right.XCoord;
    temp.YCoord = YCoord - right.YCoord;
    return temp;
}

CartesianCoordinate2D& CartesianCoordinate2D::operator -= (const CartesianCoordinate2D& right)
{
    XCoord -= right.XCoord;
    YCoord -= right.YCoord;
    return *this;
}

ostream &operator << (ostream &strm, const CartesianCoordinate2D &right)
{
    strm << "(" << right.XCoord << "," << right.YCoord << ")";
    return strm;
}

bool CartesianCoordinate2D::operator > (const CartesianCoordinate2D &right)
{
    bool status;

    if (GetDistance() > right.GetDistance())
    {
        status = true;
    }
    else
        status = false;

    return status;
}
