#include <iostream>
#include <cmath>

#include "header.h"

using namespace std;

void Get_Coefficients(float *a_ptr, float *b_ptr, float *c_ptr)
{

    char temp[10];

    cout << "\nA quadratic equation is of the form: ax^2 + bx + c = 0";
    cout << "\nPlease provide the coefficients of the equation: ";

    cout << "\na: ";
    cin >> temp;
    *a_ptr = atof(temp);

    cout << "\nb: ";
    cin >> temp;
    *b_ptr = atof(temp);

    cout << "\nc: ";
    cin >> temp;
    *c_ptr = atof(temp);
}

char Calc_Discriminant(float a, float b, float c)
{

    float discriminant = pow(b, 2) - (4 * a * c);

    if (discriminant > 0.0)
    {
        return 'r';
    }
    else if (discriminant < 0.0)
    {
        return 'i';
    }
    else
    {
        return 's';
    }
}

void Calc_Root(float a, float b, float c)
{

    float discriminant = Calc_Discriminant(a, b, c);

    cout << "\nThe roots of the quadratic equation are: ";

    if (discriminant == 'r')
    {
        float root1 = (-b + sqrt(pow(b, 2) - (4 * a * c))) / (2 * a);
        float root2 = (-b - sqrt(pow(b, 2) - (4 * a * c))) / (2 * a);

        cout << "\nroot1: " << root1;
        cout << "\nroot2: " << root2;
    }
    else if (discriminant == 'i')
    {

        float real_part = -b / (2 * a);
        float imaginary_part = sqrt(abs(pow(b, 2) - (4 * a * c))) / (2 * a);

        cout << "\nroot1: " << real_part << " + " << imaginary_part << "i";
        cout << "\nroot2: " << real_part << " - " << imaginary_part << "i";
    }
    else if (discriminant == 's')
    {
        float root = (-b + sqrt(pow(b, 2) - (4 * a * c))) / (2 * a);

        cout << "\nroot1: " << root;
        cout << "\nroot2: " << root;
    }
}