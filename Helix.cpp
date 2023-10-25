#include "Helix.h"
#include <random>

//Helix::Helix() {
//	type = HELIX;
//	x = 0;
//	y = 0;
//	z = 0;
//	r = 0;
//	step = 0;
//}

Helix::Helix(double in_r, double in_step) {
	type = HELIX;
	x = 0;
	y = 0;
	r = in_r;
	step = in_step;
}

vector<double> Helix::C(double t) {
	int c = trunc(t / (2 * _Pi));
	double out_x = r * cos(t);
	double out_y = r * sin(t);
	double out_z = step * t + step * c;
	return { out_x, out_y, out_z };
}

vector<double> Helix::C_deriv(double t) {
	double out_x = -r * sin(t);
	double out_y = r * cos(t);
	double out_z = step;
	return { out_x, out_y, out_z };
}

void Helix::printParams()
{
	//Curve::printParams();
	cout << "Radius: " << fixed << setprecision(6) << (cpp_dec_float_50)r << endl << "Step: " << (cpp_dec_float_50)step << endl;
}