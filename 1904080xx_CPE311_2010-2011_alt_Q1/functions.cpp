#include <iostream>

#include "header.h"

using namespace std;

void WriteHellos(int number_of_hellos, int number_of_lines)
{

    cout << "\n";

    if (number_of_hellos == 0 || number_of_lines == 0)
    {

        cout << "No Hellos for You.";

        // return statement terminates the execution of the function
        // meaning the rest of the code in the function body is ignored if the if-condition is satisfied
        return;
    }

    for (int i = 0; i < number_of_lines; i++)
    {

        for (int j = 0; j < number_of_hellos; j++)
        {

            cout << "hello ";
        }

        cout << "\n";
    }
}