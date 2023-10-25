// CAD-Test-Task.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <list>
#include <random>
#include <numbers>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Curves.h"

using namespace std;

//template<typename Base, typename T>
//inline bool instanceof(const T* ptr) {
//    return dynamic_cast<const Base*>(ptr) != nullptr;
//}

vector<Curve*> getCurves() {
    srand(time(nullptr));
    mt19937 generator;
    uniform_real_distribution<double> all_real_distribution(-999.0, 999.0);
    uniform_real_distribution<double> positive_real_distribution(0.01, 999.0);
    int count = rand() % 25 + 1;
    vector<Curve*> curves;
    for (int i = 0; i < count; i++) {
        int figure = rand() % 3 + 1;
        double x = all_real_distribution(generator);
        double y = all_real_distribution(generator);
        double z = all_real_distribution(generator);
        double r_x = positive_real_distribution(generator);
        double r_y = positive_real_distribution(generator);
        double step = positive_real_distribution(generator);
        switch (figure) {
        case 1:     //circle
        {
            Circle *c = new Circle((double)x, y, r_x);
            curves.push_back(c); 
            break;
        }
            
        case 2:     //ellipse
        {
            Ellipse *e = new Ellipse(x, y, r_x, r_y);
            curves.push_back(e);
            break;
        }
            
        case 3:     //helix
        {
            Helix* h = new Helix(r_x, step);
            curves.push_back(h);
            break;
        }
        default:
        {
            break;
        }
        }
    }
    return curves;
}

bool compareCircles(Circle& c1, Circle& c2) {
    return c1.getR() < c2.getR();
}

int main()
{
    //Populate a container (e.g. vector or list) of objects of these types created in random manner with random parameters
    vector<Curve*> curves = getCurves();
    cout << "Curves count: " << curves.size() << endl << endl;
    //Print coordinates of points and derivatives of all curves in the container at t=PI/4
    //Populate a second container that would contain only circles from the first container.
    vector<Circle*> circles;
    for (auto& curve : curves) {
        cout << "Figure type: ";
        switch (curve->getType()) {
        case ELLIPSE: {
            cout << "Ellipse";
            break;
        }
        case CIRCLE: {
            cout << "Circle";
            circles.push_back((Circle*)curve);
            break;
        }
        case HELIX: {
            cout << "Helix";
            break;
        }
        default: {
            cout << "Unknown";
            break;
        }
        }
        cout << endl;
        curve->printParams();
        vector<double> C = curve->C(_Pi / 4.0);
        vector<double> C_deriv = curve->C_deriv(_Pi / 4.0);
        cout << "Point at pi/4: ";
        for (const cpp_dec_float_50 &a : C) {
            cout << fixed << setprecision(6) << a << ", ";
        }
        cout << endl;
        cout << "Derivative at pi/4: ";
        for (const cpp_dec_float_50 &b : C_deriv)
            cout << fixed << setprecision(6) << b << ", ";
        cout << endl << endl;
    }

    //Sort the second container in the ascending order of circles’ radii.
    sort(circles.begin(), circles.end(), [](Circle* c1, Circle* c2) { return c1->getR() < c2->getR(); });
    cout << "Circle's radii in the ascending order: ";
    //Compute the total sum of radii of all curves in the second container
    double sum = 0.0;
    for (Circle* c : circles) {
        cout << c->getR() << ", ";
        sum += c->getR();
    }
    cout << endl << "Sum of circle's radii: " << fixed << setprecision(6) << (cpp_dec_float_50)sum << endl;
}

