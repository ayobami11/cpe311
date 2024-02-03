#ifndef _HEADER_H_
#define _HEADER_H_

// the use of enums, structs or functions was not specified in the question
enum GradePoint
{
    GradePoint_A = 5,
    GradePoint_B = 4,
    GradePoint_C = 3,
    GradePoint_D = 2,
    GradePoint_E = 1,
    GradePoint_F = 0
};

struct Course
{
    char CourseCode[10];
    int CourseUnit;
    char CourseGrade;
};

struct Student
{
    char name[40];
    int number_of_courses;
    // we are allowing only a maximum of 15 courses
    Course courses[15];
    int UA;    // Units Attempted
    int UP;    // Units Passed
    int WS;    // Weighted Score
    float GPA; // Grade Point Average
};

void GetStudentInfo(Student &);
void CalculateResults(Student &);
void WriteResultsToScreen(Student &);
void WriteResultsToFile(Student &);

#endif