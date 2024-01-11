#include <iostream>
// for pow, sqrt functions
#include <cmath>
// provides support for complex numbers when used
#include <complex>

using namespace std;

enum RootsType
{
    RealAndEqual,
    RealAndUnequal,
    Complex
};

struct Coefficient
{
    float SecondOrderCoeff;
    float FirstOrderCoeff;
    float ConstantCoeff;
};

struct ComplexRoots
{
    complex<float> root1;
    complex<float> root2;
};

class Quadratic
{

public:
    Coefficient coefficients;

    /*
        Quadratic() is the constructor of the Quadratic class - link
        Since two 'versions' of the constructor are required, the constructor is said to be overloaded - link
    */

    // sets the coefficients of the equation to default values, if none are provided
    Quadratic()
    {
        coefficients.SecondOrderCoeff = 0.0;
        coefficients.FirstOrderCoeff = 0.0;
        coefficients.ConstantCoeff = 0.0;
    }

    // sets the coefficients of the equation with user-defined values
    Quadratic(float SecondOrderCoeff, float FirstOrderCoeff, float ConstantCoeff)
    {
        SetCoefficient(SecondOrderCoeff, FirstOrderCoeff, ConstantCoeff);
    }

    // sets the coefficients of the equation after the object has been instantiated (or, created)
    void SetCoefficient(float SecondOrderCoeff, float FirstOrderCoeff, float ConstantCoeff)
    {
        coefficients.SecondOrderCoeff = SecondOrderCoeff;
        coefficients.FirstOrderCoeff = FirstOrderCoeff;
        coefficients.ConstantCoeff = ConstantCoeff;
    }

private:
    int CalcDeterminant()
    {
        float determinant = pow(coefficients.FirstOrderCoeff, 2) - (4 * coefficients.SecondOrderCoeff * coefficients.ConstantCoeff);

        cout << "det: " << determinant << endl;

        int root_type;

        if (determinant > 0.0)
        {
            // real and unequal roots
            root_type = RootsType::RealAndUnequal;
        }
        else if (determinant < 0.0)
        {
            // complex roots
            root_type = RootsType::Complex;
        }
        else
        {
            // real and equal roots
            root_type = RootsType::RealAndEqual;
        }

        return root_type;
    }

public:
    // the function returns a reference to a Coefficient variable (so all its values can be accessed using the same variable)
    Coefficient &GetCoefficient(Coefficient *coefficient)
    {
        return *coefficient;
    }

    void QuadraticRoots(ComplexRoots *roots)
    {
        // CalcDeterminant() returns an integer indicating the type of roots expected
        int root_type = CalcDeterminant();

        Coefficient &coefficients_ref = GetCoefficient(&coefficients);

        roots->root1 = (-coefficients_ref.FirstOrderCoeff + sqrt(complex<float>(pow(coefficients_ref.FirstOrderCoeff, 2) - (4 * coefficients_ref.SecondOrderCoeff * coefficients_ref.ConstantCoeff)))) / (2 * coefficients_ref.SecondOrderCoeff);
        roots->root2 = (-coefficients_ref.FirstOrderCoeff - sqrt(complex<float>(pow(coefficients_ref.FirstOrderCoeff, 2) - (4 * coefficients_ref.SecondOrderCoeff * coefficients_ref.ConstantCoeff)))) / (2 * coefficients_ref.SecondOrderCoeff);
    }

    void WriteRoots(ComplexRoots *roots)
    {

        QuadraticRoots(roots);

        cout << "The roots are: ";

        cout << "\nx1: " << roots->root1.real() << (roots->root1.imag() > 0 ? "+" : "") << roots->root1.imag();
        cout << "\nx2: " << roots->root2.real() << (roots->root2.imag() > 0 ? "+" : "") << roots->root2.imag();
    }
};

int main(void)
{

    Coefficient coefficients;
    ComplexRoots roots;

    Quadratic equation(2, 2, 2);

    cout << equation.coefficients.SecondOrderCoeff << endl;
    cout << equation.coefficients.FirstOrderCoeff << endl;
    cout << equation.coefficients.ConstantCoeff << endl;

    equation.WriteRoots(&roots);

    cout << endl;

    system("pause");

    return 0;
}