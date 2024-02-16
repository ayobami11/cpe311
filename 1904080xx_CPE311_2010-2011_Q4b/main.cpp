#include <iostream>

#include "header.h"

using namespace std;

int main(void)
{

    // objects formed from the derived classes
    Cone cone;
    Sphere sphere;
    Pyramid pyramid;
    Box box;

    // creates an array of shape pointers

    Shape *shape_pointers[4] = {&cone, &sphere, &pyramid, &box};

    for (int i = 0; i < 4; i++)
    {
        // remember shape_pointers[i] returns a pointer so we have to access the value being pointed at first using ->
        // shape_pointers[i]->WhatAmI() is equivalent to (*shape_pointers[i])WhatAmI()
        shape_pointers[i]->WhatAmI();
    }

    system("pause");

    return 0;
}