#pragma once
#include "Ellipse.h"
class Circle :
    public Ellipse
{
protected:
     double r;
public:
    Circle(double in_x, double in_y,  double in_r);
    void printParams();
    double getR();
    bool operator<(const Circle& other);
    //static bool compareLess(const Circle& c1, const Circle& c2);
};

