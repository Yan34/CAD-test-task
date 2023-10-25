#pragma once
#include "Curve.h"

class Helix :
    public Curve
{
protected:
    double step;
    double r;
public:
    //Helix();
    Helix(double in_r, double in_step);
    vector<double> C(double t);
    vector<double> C_deriv(double t);
    void printParams();
};

