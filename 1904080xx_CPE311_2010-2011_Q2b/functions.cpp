// for rand functio
#include <stdlib.h>
// for time function
#include <ctime>

#include "header.h"

int GetRandomNum(int m)
{
    // generates a random int between 0 and (m - 1)
    int random_number = rand() % m;
    return random_number;
}

int GetRandomNum(int i, int j)
{
    // generates a random int between (i + 1) and (j - 1)
    int random_number = (i + 1) + (rand() % (j - i - 1));
    return random_number;
}

double GetRandomNum()
{

    // both rand() and RAND_MAX return ints so we need to cast at least one of them to a double to get a double
    double random_double = (double)rand() / RAND_MAX;

    return random_double;
}