#pragma once
#include "Curve.h"

class Ellipse :
    public Curve
{
protected:
     double r_x, r_y;
public:
    Ellipse();
    Ellipse(double in_x, double in_y, double in_r_x, double in_r_y);
    void printParams();
    vector<double> C(double t);
    vector<double> C_deriv(double t);
};

