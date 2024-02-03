#include <iostream>
// for srand function
#include <stdlib.h>
// for time function
#include <ctime>
// for set precision function
#include <iomanip>

#include "header.h"

using namespace std;

int main(void)
{

    // https://www.digitalocean.com/community/tutorials/random-number-generator-c-plus-plus
    // Initialize random number generator
    srand((unsigned)time(NULL));

    cout << "\nRandom number between 0 and 27 (27, exclusive): " << GetRandomNum(27);

    cout << "\nRandom number between 3 and 73 (3 and 73 exclusive): " << GetRandomNum(3, 73);

    // https://www.scaler.com/topics/setprecision-function-in-cpp/
    // // https://www.google.com/amp/s/www.softwaretestinghelp.com/random-number-generator-cpp/amp/
    cout << "\nRandom number between 0.000 and 1.000: " << setprecision(3) << GetRandomNum();

    cout << endl;

    system("pause");

    return 0;
}