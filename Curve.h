#pragma once
using namespace std;
#include <vector>
#include <cmath>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <iostream>
using boost::multiprecision::cpp_dec_float_50;

enum curve_type {
	ELLIPSE,
	CIRCLE,
	HELIX
};

class Curve
{
protected:
	double x, y;
	//void printParams();
	curve_type type;
public:
	vector<double> getCenter();
	virtual vector<double> C(double t) = 0;
	virtual vector<double> C_deriv(double t) = 0;
	virtual void printParams();
	curve_type getType();
	virtual ~Curve() {}
	//double getX(), getY(), getZ();
};

