#include "Ellipse.h"

Ellipse::Ellipse() {
	type = ELLIPSE;
	x = 0.0; y = 0.0; r_x = 0.0; r_y = 0.0;
}

Ellipse::Ellipse(double in_x, double in_y,  double in_r_x,  double in_r_y) {
	type = ELLIPSE;
	x = in_x;
	y = in_y;
	r_x = in_r_x;
	r_y = in_r_y;
}

vector<double> Ellipse::C(double t) {
	double out_x = r_x * cos(t) + x;
	double out_y = r_y * sin(t) + y;
	return { out_x, out_y };
}

vector<double> Ellipse::C_deriv(double t) {
	double out_x = -r_x * sin(t) + x;
	double out_y = r_y * cos(t) + y;
	return { out_x, out_y };
}

void Ellipse::printParams() {
	Curve::printParams();
	cout << "Radius X: " << fixed << setprecision(6) << (cpp_dec_float_50)r_x << endl << "Radius Y: " << (cpp_dec_float_50)r_y << endl;
}