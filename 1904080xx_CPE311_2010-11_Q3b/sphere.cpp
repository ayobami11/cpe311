// needed for us to be able to access the M_PI in cmath
#define _USE_MATH_DEFINES

#include <iostream>
// for M_PI; pow function
#include <cmath>
// for fixed; setprecision function
#include <iomanip>

#include "sphere.h"

using namespace std;

float Sphere::CalcArea()
{
    float area = 4.0 * M_PI * pow(radius, 2);
    return area;
}

float Sphere::CalcVol()
{
    float volume = (4.0 * M_PI * pow(radius, 3)) / 3.0;
    return volume;
}

Sphere::Sphere()
{
    cout << "Please pass in the radius of the sphere: ";

    char temp[15];
    cin >> temp;
    radius = atof(temp);
}

void Sphere::PrintResults()
{
    cout << "\nSphere information: ";

    // fixed - converts number from floating-point to fixed point
    // setprecision - sets the decimal precision
    cout << "\nRadius: " << fixed << setprecision(2) << radius;
    cout << "\nArea: " << fixed << setprecision(2) << CalcArea();
    cout << "\nVolume: " << fixed << setprecision(2) << CalcVol();
}