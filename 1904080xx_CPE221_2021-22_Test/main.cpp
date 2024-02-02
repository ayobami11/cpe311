// Our mid-semester test in year 2 but using multi-file approach

#include <iostream>

#include "header.h"

using namespace std;

int main(void)
{

    char run_again;

    do
    {

        float a, b, c;

        Get_Coefficients(&a, &b, &c);
        Calc_Root(a, b, c);

        cout << "\nDo you want to run this program again? ";
        cin >> run_again;

    } while (run_again == 'y' || run_again == 'Y');

    cout << endl;

    system("pause");

    return 0;
};