#include <iostream>

#include "header.h"

using namespace std;

int main(void)
{

    WriteHellos();
    WriteHellos(12, 3);
    WriteHellos(5, 11);
    // for this call, either or both of the arguments can be 0
    WriteHellos(0, 1);

    cout << endl;

    system("pause");

    return 0;
}