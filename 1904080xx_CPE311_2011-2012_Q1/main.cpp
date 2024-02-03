// This question is very flexible, I just tried to make use of as many concepts that we covered in class
#include <iostream>

#include "header.h"

using namespace std;

int main(void)
{

    Student john;

    GetStudentInfo(john);

    CalculateResults(john);

    WriteResultsToScreen(john);

    WriteResultsToFile(john);

    cout << endl;

    system("pause");

    return 0;
}