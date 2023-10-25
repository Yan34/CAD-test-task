#include "Circle.h"

Circle::Circle(double in_x, double in_y,  double in_r)
	: Ellipse(in_x, in_y, in_r, in_r)
{
	type = CIRCLE;
	r = in_r;
}

void Circle::printParams()
{
	Curve::printParams();
	cout << "Radius: " << fixed << setprecision(6) << (cpp_dec_float_50)r << endl;
}

double Circle::getR()
{
	return r;
}

bool Circle::operator<(const Circle& other)
{
	return r < other.r;
}
//
//bool Circle::compareLess(const Circle& c1, const Circle& c2)
//{
//	return c1.r < c2.r;
//}
