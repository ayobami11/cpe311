#include <iostream>
// for reading and writing to files
#include <fstream>
// for strcpy, strcat functions
#include <string.h>
// used for std::left; setw function
#include <iomanip>

#include "header.h"

using namespace std;

void ReadStudentInfo(Student students[3])
{

    // open a file for read operations
    fstream StudentInfoFile("StudentInfo.txt", ios::in);

    if (StudentInfoFile.is_open())
    {

        for (int i = 0; i < 3; i++)
        {
            char first_name[20];
            char last_name[20];

            StudentInfoFile >> first_name >> last_name >> students[i].Score1 >> students[i].Score2 >> students[i].Score3 >> students[i].Score4;

            strcpy(students[i].Name, first_name);
            // concatenates the first name, a space, and last name (strcat is used because + concatenates strings not char arrays)
            strcat(students[i].Name, " ");
            strcat(students[i].Name, last_name);
        }
    }
    else
    {
        cerr << "An error occurred when trying to read from StudentInfo.txt" << endl;
    }

    // closes the file
    StudentInfoFile.close();
}

void CalcAverage(Student students[3])
{
    for (int i = 0; i < 3; i++)
    {
        students[i].AvgScore = (float)(students[i].Score1 + students[i].Score2 + students[i].Score3 + students[i].Score4) / 4;
    }
}

void WriteAvgScore(Student students[3])
{

    // open a file for write operations
    fstream AvgScoreFile("AvgScoreFile.txt", ios::out);

    if (AvgScoreFile.is_open())
    {

        for (int i = 0; i < 3; i++)
        {
            // setw - set the width (number of character spaces) between two portions of text
            // left - aligns to output to the left
            AvgScoreFile << left << setw(20) << students[i].Name << setw(20) << students[i].AvgScore << "\n";
        }
    }
    else
    {
        cerr << "An error occurred when trying to write to AvgScoreFile.txt" << endl;
    }

    // closes the file
    AvgScoreFile.close();
}