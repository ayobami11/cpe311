#include <iostream>

#include "header.h"

using namespace std;

int main(void)
{

    Person hazel, gus;
    hazel = FillPerson();
    gus = FillPerson();

    WhoIsOlder(hazel, gus);

    cout << endl;

    system("pause");

    return 0;
}