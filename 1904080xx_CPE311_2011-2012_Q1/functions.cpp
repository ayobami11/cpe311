#include <iostream>
// for toupper function
#include <cctype>
// for strcpy function
#include <string>
// for left manipulator; setw function
#include <iomanip>
// for file operations
#include <fstream>

#include "header.h"

using namespace std;

void GetStudentInfo(Student &student)
{

    // temporary variable for stroring user input before storage
    char temp[40];

    cout << "\nPlease provide the following information: \n";

    cout << "\nName: ";
    cin.getline(temp, 40);
    strcpy(student.name, temp);

    cout << "\nNumber of registered courses: ";
    cin >> temp;
    // converts char array to int before storing it
    student.number_of_courses = atoi(temp);

    cin.ignore(10, '\n');

    for (int i = 0; i < student.number_of_courses; i++)
    {

        // (i + 1) because arrays are zero-indexed
        cout << "\n\nCourse " << (i + 1) << endl;

        cout << "\nCourse code: ";
        cin.getline(temp, 10);
        strcpy(student.courses[i].CourseCode, temp);

        cout << "\nCourse unit: ";
        cin.getline(temp, 2);
        student.courses[i].CourseUnit = atoi(temp);

        // I just need a char for grade, not a char array
        char grade;
        cout << "\nCourse grade: ";
        cin >> grade;
        student.courses[i].CourseGrade = grade;

        cin.ignore(10, '\n');
    }
}

void CalculateResults(Student &student)
{

    int units_attempted = 0;
    int units_passed = 0;
    int weighted_score = 0;

    for (int i = 0; i < student.number_of_courses; i++)
    {

        Course current_course = student.courses[i];

        units_attempted += current_course.CourseUnit;

        // converts the grades provided to uppercase first
        switch (toupper(current_course.CourseGrade))
        {
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
            units_passed += 1;
            break;
        default:
            // handles case 'F', and invalid inputs
            units_passed += 0;
        }

        // converts the grades provided to uppercase first
        switch (toupper(current_course.CourseGrade))
        {
        case 'A':
            weighted_score += current_course.CourseUnit * GradePoint_A;
            break;
        case 'B':
            weighted_score += current_course.CourseUnit * GradePoint_B;
            break;
        case 'C':
            weighted_score += current_course.CourseUnit * GradePoint_C;
            break;
        case 'D':
            weighted_score += current_course.CourseUnit * GradePoint_D;
            break;
        case 'E':
            weighted_score += current_course.CourseUnit * GradePoint_E;
            break;
        case 'F':
            weighted_score += current_course.CourseUnit * GradePoint_F;
            break;
        default:
            cout << "\nInvalid course grade.";
        }
    }

    student.UA = units_attempted;
    student.UP = units_passed;
    student.WS = weighted_score;
    // int / int would give an int so we need to explicitly convert one of the operands to a float
    student.GPA = (float)weighted_score / units_attempted;
}

void WriteResultsToScreen(Student &student)
{

    cout << "\n\n";

    cout << student.name << endl;

    cout << left << setw(15) << "\nCourse Code" << setw(11) << "Unit" << setw(11) << "Grade";

    for (int i = 0; i < student.number_of_courses; i++)
    {
        cout << "\n"
             << setw(15) << left << student.courses[i].CourseCode << setw(11) << student.courses[i].CourseUnit << setw(11) << student.courses[i].CourseGrade;
    }

    cout << "\n\nUA = " << student.UA;
    cout << "\nUP = " << student.UP;
    cout << "\nWS = " << student.WS;
    cout << "\nGPA = " << student.GPA;

    cout << "\n\n";
}

void WriteResultsToFile(Student &student)
{

    // opens file for writing operations
    fstream ResultsFile("results.txt", ios::out);

    if (ResultsFile.is_open())
    {

        ResultsFile << student.name << endl;

        ResultsFile << setw(15) << left << "\nCourse Code" << setw(11) << "Unit" << setw(11) << "Grade";

        for (int i = 0; i < student.number_of_courses; i++)
        {
            ResultsFile << "\n"
                        << left << setw(15) << student.courses[i].CourseCode << setw(11) << student.courses[i].CourseUnit << setw(11) << student.courses[i].CourseGrade;
        }

        ResultsFile
            << "\n\nUA = " << student.UA
            << "\nUP = " << student.UP
            << "\nWS = " << student.WS
            << "\nGPA = " << student.GPA;
    }
    else
    {
        cout << "\nAn error occurred while trying to write to results.txt";
    }

    ResultsFile.close();
}