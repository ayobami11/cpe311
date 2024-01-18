#include <iostream>
#include "header.h"

int main(void)
{

    Student students[3];

    ReadStudentInfo(students);
    CalcAverage(students);
    WriteAvgScore(students);

    system("pause");

    return 0;
}