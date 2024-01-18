/* File naming format: MatricNo_CPE311_2019-2020_Q?
    QUESTION 1
        Write a C++ program that setup a class Quadratic that uses the C++ complex class to
        determine the roots of quadratic equation ax^2+bx+c=0 where a, b and c are
        coefficients. The class has two constructors, the first initializes all the coefficients to
        zero and the other initializes all the coefficients set by the user. Also within the class
        there are functions SetCoefficient that set the coefficient of the equation by user after
        an object had been instantiated, GetCoefficient that takes in a pointer to an object of
        type Coefficient that have data members that are coefficients of quadratic equation
        which read the values of the coefficients, CalcDeterminant which is a private function
        that determine the type of roots such as real repeated, real different or imaginary,
        QuadraticRoots that calculate the roots of the equation after calling the
        CalcDeterminant and WriteRoots function also takes in a pointer to an object of
        structure type ComplexRoots that have data members root1 and root2 of type
        complex due to the C++ complex class that print the roots of the equation to screen.
        The roots of a quadratic equation and determinant equations are:
        x1,2=(−b ±√(b^2−4*a*c)) / (2*a)
        det=b^2− 4 ac
        For the coefficient a, b and c, use the variable names SecondOrderCoeff,
        FirstOrderCoeff and ConstantCoeff, respectively as their variable declaration.
        In the main function, create thr objects of type Quadratic, Coefficient and
        ComplexRoots. Get the coefficients and the roots of the object and display them on
        the screen. Furthermore create three more objects and set the coefficients of the
        quadratic equation for the three cases of real roots, real repeated roots and complex
        roots. On each occasion determine the roots and display then results on the screen. of
        type Quadratic
*/

#include <iostream>
// for pow, sqrt functions
#include <cmath>
// provides support for complex numbers when used
#include <complex>

using namespace std;

// using enums was not specified in the question, used just for the sake of readability
// https://www.programiz.com/cpp-programming/enumeration
enum RootsType
{
    RealAndEqual,   // === 0
    RealAndUnequal, // === 1
    Complex         // === 2
};

struct Coefficient
{
    float SecondOrderCoeff; // === a
    float FirstOrderCoeff;  // === b
    float ConstantCoeff;    // === c
};

struct ComplexRoots
{
    complex<float> root1;
    complex<float> root2;
};

// Classes in C++ - https:// www.programiz.com/cpp-programming/object-class
class Quadratic
{

public:
    /*
        coefficients - variable that temporarily stores the coefficients of the equation until the user provides one - just to ensure we have
        a default value of type Coefficient that can be used within the class, and prevent errors.

        Once the coefficients are provided using GetCoefficients, this would point to the user-provided coefficient
    */

    Coefficient coefficients;
    Coefficient *coefficients_ptr;

    /*
        Quadratic() is the constructor of the Quadratic class - https://www.programiz.com/cpp-programming/constructors
        Since two 'versions' of the constructor are required, the constructor is said to be overloaded - https://www.programiz.com/cpp-programming/constructor-overloading

    */

    // First constructor: sets the coefficients of the equation to default values (zero), if none are provided
    Quadratic()
    {
        // properties (members) of a class are usually initialized in the constructor
        coefficients_ptr = &coefficients;
        /*
            SetCoefficient(0.0, 0.0, 0.0);
                also works but it was not specified in the question

        */
        coefficients_ptr->SecondOrderCoeff = 0.0;
        coefficients_ptr->FirstOrderCoeff = 0.0;
        coefficients_ptr->ConstantCoeff = 0.0;
    }

    // Second constructor: sets the coefficients of the equation with user-defined values
    Quadratic(float SecondOrderCoeff, float FirstOrderCoeff, float ConstantCoeff)
    {
        coefficients_ptr = &coefficients;

        SetCoefficient(SecondOrderCoeff, FirstOrderCoeff, ConstantCoeff);
    }

    // sets the coefficients of the equation after the object has been instantiated (or, created)
    void SetCoefficient(float SecondOrderCoeff, float FirstOrderCoeff, float ConstantCoeff)
    {
        coefficients_ptr->SecondOrderCoeff = SecondOrderCoeff;
        coefficients_ptr->FirstOrderCoeff = FirstOrderCoeff;
        coefficients_ptr->ConstantCoeff = ConstantCoeff;
    }

    void GetCoefficient(Coefficient *coefficient)
    {
        // replaces the value at the address of coefficient with the value at the address of coefficient_ptr
        // or copies the values of the coeffecients used in the class to the variable provided by the user
        *coefficient = *coefficients_ptr;
        // updates the address of coefficients_ptr to point to the address of coefficient (which is the user-provided coefficient)
        coefficients_ptr = coefficient;
    }

    // private properties and methods can't be accessed outside this Quadratic class (they can only be used internally)
private:
    // determines the type of roots expected using the determinant equation; also returns the determinant (they mean discriminant)
    float CalcDeterminant()
    {
        float determinant = pow(coefficients_ptr->FirstOrderCoeff, 2) - (4 * coefficients_ptr->SecondOrderCoeff * coefficients_ptr->ConstantCoeff);

        RootsType root_type;

        if (determinant > 0.0)
        {
            // real and unequal roots
            root_type = RealAndUnequal;
        }
        else if (determinant < 0.0)
        {
            // complex roots
            root_type = Complex;
        }
        else
        {
            // real and equal roots
            root_type = RealAndEqual;
        }

        return determinant;
    }

public:
    // calculates the roots of the equation
    void QuadraticRoots(ComplexRoots *roots)
    {
        // CalcDeterminant() returns the determinant of the equation
        float determinant = CalcDeterminant();

        /*
            complex<float>(determinant) - converts the determinant to a floating-point, complex number
            This has to be done first because taking the root of a negative real number would result in NaN (not a number)
            https://www.programiz.com/cpp-programming/type-conversion
        */
        roots->root1 = (-coefficients_ptr->FirstOrderCoeff + sqrt(complex<float>(determinant))) / (2 * coefficients_ptr->SecondOrderCoeff);
        roots->root2 = (-coefficients_ptr->FirstOrderCoeff - sqrt(complex<float>(determinant))) / (2 * coefficients_ptr->SecondOrderCoeff);
    }

    // helper function to output the coefficients (not specified in the question)
    // Outputs the coefficients of the equation to the screen
    void WriteCoefficients(Coefficient *coefficients)
    {
        cout << "\n\nThe coefficients of the equation are: ";

        cout << "\n\tSecondOrderCoeff (a): " << coefficients->SecondOrderCoeff;
        cout << "\n\tFirstOrderCoeff (b): " << coefficients->FirstOrderCoeff;
        cout << "\n\tConstantCoeff (c): " << coefficients->ConstantCoeff;
    }

    // Outputs the roots of the equation to the screen
    void WriteRoots(ComplexRoots *roots)
    {
        // calculates and stores the roots of the equation first so it can be displayed later
        QuadraticRoots(roots);

        // \n === newline character
        cout << "\n\nThe roots of the equation are:";

        // \t === tab character

        /*
            (long double)(roots->root1.imag()) - converts the float to a long double before it can be passed to to_string, for compatibility reasons
            Visual Studio 2010 to_string method doesn't support float, but newer versions do - https://stackoverflow.com/questions/10664699/stdto-string-more-than-instance-of-overloaded-function-matches-the-argument
        */
        cout << "\n\tx1: " << roots->root1.real() << (roots->root1.imag() > 0 ? "+" : "") << (roots->root1.imag() != 0 ? (to_string((long double)(roots->root1.imag())) + 'i') : "");
        cout << "\n\tx2: " << roots->root2.real() << (roots->root2.imag() > 0 ? "+" : "") << (roots->root2.imag() != 0 ? (to_string((long double)(roots->root2.imag())) + 'i') : "");
    }
};

int main(void)
{

    Quadratic equation(1, -15, 56);
    /*
        equivalent to:
            Quadratic equation;
            equation.SetCoefficient(1, -15, 56);
    */

    Coefficient coefficient;
    ComplexRoots roots;

    equation.GetCoefficient(&coefficient);
    equation.WriteCoefficients(&coefficient);
    equation.WriteRoots(&roots);

    Quadratic equation1, equation2, equation3;
    Coefficient coefficient1, coefficient2, coefficient3;
    ComplexRoots roots1, roots2, roots3;

    // Example of real and unequal roots
    equation1.GetCoefficient(&coefficient1);
    equation1.SetCoefficient(1, -5, 6);
    equation1.WriteCoefficients(&coefficient1);
    equation1.WriteRoots(&roots1);

    // Example of complex roots
    equation2.GetCoefficient(&coefficient2);
    equation2.SetCoefficient(2, 2, 2);
    equation2.WriteCoefficients(&coefficient2);
    equation2.WriteRoots(&roots2);

    // Example of real and equal roots
    equation3.GetCoefficient(&coefficient3);
    equation3.SetCoefficient(1, -6, 9);
    equation3.WriteCoefficients(&coefficient3);
    equation3.WriteRoots(&roots3);

    cout << "\n\n";

    system("pause");

    return 0;
}