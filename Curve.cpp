#include "Curve.h"

//double Curve::getX() {
//	return x;
//}
//
//double Curve::getY() {
//	return y;
//}
//
//double Curve::getZ() {
//	return z;
//}

curve_type Curve::getType() {
	return type;
}

vector<double> Curve::getCenter() {
	return { x, y };
}

void Curve::printParams() {
	cout << "Center Point: " << fixed << setprecision(6) << (cpp_dec_float_50)x << ", " << (cpp_dec_float_50)y << endl;
}