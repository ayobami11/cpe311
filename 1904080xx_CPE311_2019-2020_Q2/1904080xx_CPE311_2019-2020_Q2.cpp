/*

    QUESTION 2

    Write a C++ program that setup a class Cgpa that has two constructors, a default
    constructor that set data members units_taken, units_passed, weighted_score and gpa
    (grade point average) all being integer except gpa that is a floating-point number to
    zero and the parameter constructor initilaizes them too a user defined values. The
    methods CalcParameters takes in an array of Course value up to twelve elements that is a user defined structure having datatypes string, int, char and float for data
    members course_code, course_unit, course_grade and course_point, respectively, and
    the number of courses passed to it. The member function calculates the total units
    taken, total units passed and weighted score for a student. The gpa of a student is
    determine from a function CalcGpa which divides the weighted score with the total
    unit taken. The unit pass of a course is when the grade point is greater than zero,
    where a course grade and its grade point is represented by A-5, B-4, C-3, D-2, E-1
    and F-0. A function GetSummaryResults takes a pointer to a structure Summary
    having data members similar to the class data members and returns the results of the
    computation of the students semester result to the calling function. Also set up an
    overlaoded operator + that adds the students previous cumulative results with that of
    the semeter results and calculate the cumulative gpa.
    In the main function, instantiate objects of type Cgpa, Summary and three Course
    arrays and preset the Course object with three courses code, units, grades and then
    call the CalcParameter function to obtain the units taken, units passed and weighted
    score. Using the Summary object retrieve the results from the object Cgpa and
    display them on the screen. Also create two more Cgpa object, the first holds the
    cumulative result while the second accept the sum of the addition operation of the
    student’s cumulative result with that of the semester result. From the cumulative
    result object, print the data to screen and then the results of the addition operation.

*/

#include <iostream>
// to use the string class
#include <string>
// for the toupper function
#include <cctype>

using namespace std;

enum CourseGrade
{
    CourseGrade_A = 5,
    CourseGrade_B = 4,
    CourseGrade_C = 3,
    CourseGrade_D = 2,
    CourseGrade_E = 1,
    CourseGrade_F = 0
};

struct Course
{
    string course_code;
    int course_unit;
    char course_grade;
    float course_point;
};

// has the same data members as the Cgpa class
struct Summary
{
    int units_taken;
    int units_passed;
    int weighted_score;
    float gpa;
};

class Cgpa
{

public:
    int units_taken;
    int units_passed;
    int weighted_score;
    float gpa;

    // First constructor: initializes data members to zero
    Cgpa()
    {
        units_taken = 0;
        units_passed = 0;
        weighted_score = 0;
        gpa = 0.0;
    }

    // Second constructor: initializes data members to user-defined value
    // _p just indicates it's a parameter; just to distinguish between the data members and the parameters
    Cgpa(int units_taken_p, int units_passed_p, int weighted_score_p, float gpa_p)
    {
        units_taken = units_taken_p;
        units_passed = units_passed_p;
        weighted_score = weighted_score_p;
        gpa = gpa_p;
    }

    void CalcParameters(Course courses[12], int number_of_courses)
    {

        for (int i = 0; i < number_of_courses; i++)
        {
            // sums up the total units taken
            units_taken += courses[i].course_unit;

            // sums up the total units passed
            // converts the grade to uppercase first just in case it's lowercase - https://www.programiz.com/cpp-programming/library-function/cctype/toupper
            switch (toupper(courses[i].course_grade))
            {
            /*
                Intentional fallthrough for the first 5 cases - https://www.learncpp.com/cpp-tutorial/switch-fallthrough-and-scoping/#:~:text=Use%20the%20%5B%5Bfallthrough%5D%5D,statement)%20to%20indicate%20intentional%20fallthrough.&text=This%20suffers%20from%20the%20same,is%20being%20evaluated%20each%20time.
            */
            case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'E':
                units_passed += courses[i].course_unit;
                break;
            default:
                // handles 'F' and other invalid values
                // same as doing nothing
                units_passed += 0;
            }

            // sums up the weighted score
            switch (toupper(courses[i].course_grade))
            {
            case 'A':
                weighted_score += CourseGrade_A * courses[i].course_unit;
                break;
            case 'B':
                weighted_score += CourseGrade_B * courses[i].course_unit;
                break;
            case 'C':
                weighted_score += CourseGrade_C * courses[i].course_unit;
                break;
            case 'D':
                weighted_score += CourseGrade_D * courses[i].course_unit;
                break;
            case 'E':
                weighted_score += CourseGrade_E * courses[i].course_unit;
                break;
            case 'F':
                weighted_score += CourseGrade_F * courses[i].course_unit;
                break;
            default:
                cout << "\nInvalid grade.";
            }
        }

        gpa = CalcGpa();
    }

    float CalcGpa()
    {
        // since we are using two integer operands for the division, we get an integer quotient by default
        // so we have to explicitly convert at least one of the operands to a float, to get a float quotient
        return (float)weighted_score / units_taken;
    }

    Summary GetSummaryResults(Summary *summary)
    {
        summary->units_taken = units_taken;
        summary->units_passed = units_passed;
        summary->weighted_score = weighted_score;
        summary->gpa = gpa;

        return *summary;
    }

    // operator overloading - https://www.programiz.com/cpp-programming/operator-overloading#:~:text=To%20overload%20an%20operator%2C%20we,.%20..%20...%20%7D%3B
    Cgpa operator+(const Cgpa &semester_gpa)
    {
        Cgpa new_cgpa;

        new_cgpa.units_taken = units_taken + semester_gpa.units_taken;
        new_cgpa.units_passed = units_passed + semester_gpa.units_passed;
        new_cgpa.weighted_score = weighted_score + semester_gpa.weighted_score;

        // computes and returns the new cgpa after addition
        new_cgpa.gpa = (float)new_cgpa.weighted_score / new_cgpa.units_taken;
        return new_cgpa;
    }
};

int main(void)
{

    /*
        For the semester GPA
    */
    Cgpa student_sgpa;
    Summary semester_summary;
    Course semester_course1, semester_course2, semester_course3;

    semester_course1.course_code = "MSC315";
    semester_course1.course_unit = 3;
    semester_course1.course_grade = 'A';
    /*
        explicitly convert the integer value associated with the enum value to a float;
        this is already performed implicitly; done to make it clear to the examiner we're using a float, not an int
    */
    semester_course1.course_point = (float)CourseGrade_A;
    // same as: course1.course_point = 5.0;

    semester_course2.course_code = "BSC335";
    semester_course2.course_unit = 1;
    semester_course2.course_grade = 'E';
    semester_course2.course_point = (float)CourseGrade_E;

    semester_course3.course_code = "ABC331";
    semester_course3.course_unit = 2;
    semester_course3.course_grade = 'C';
    semester_course3.course_point = (float)CourseGrade_C;

    Course semester_courses[3] = {semester_course1, semester_course2, semester_course3};
    student_sgpa.CalcParameters(semester_courses, 3);

    student_sgpa.GetSummaryResults(&semester_summary);

    cout << "\nSemester GPA results of student: \n";
    cout << "\nUnits taken: " << semester_summary.units_taken;
    cout << "\nUnits passed: " << semester_summary.units_passed;
    cout << "\nWeighted score: " << semester_summary.weighted_score;
    cout << "\nGPA: " << semester_summary.gpa;

    cout << endl;

    /*
        For the previous CGPA (CGPA before adding the semester GPA)
    */
    Cgpa student_cgpa(6, 6, 25, (float)25 / 6);
    // no need to call CalcParameters here since the parameters are already provided

    /*
    OR:
        Cgpa student_cgpa;

        Course course1, course2, course3;

        course1.course_code = "CSC207";
        course1.course_unit = 3;
        course1.course_grade = 'A';
        course1.course_point = (float) CourseGrade_A;

        course2.course_code = "ACC211";
        course2.course_unit = 2;
        course2.course_grade = 'B';
        course2.course_point = (float) CourseGrade_B;

        course3.course_code = "IDK219";
        course3.course_unit = 1;
        course3.course_grade = 'D';
        course3.course_point = (float) CourseGrade_D;

        Course student_courses[3] = {course1, course2, course3};

        student_cgpa.CalcParameters(student_courses, 3);
    */

    // Current CGPA results (before addition)
    cout << "\nCGPA results of student  (before addition): \n";
    cout << "\nUnits taken: " << student_cgpa.units_taken;
    cout << "\nUnits passed: " << student_cgpa.units_passed;
    cout << "\nWeighted score: " << student_cgpa.weighted_score;
    cout << "\nGPA: " << student_cgpa.gpa;

    cout << endl;

    /*
        For the new CGPA (CGPA after adding the semester GPA)
    */
    cout << "\nNew CGPA results of student (after addition): \n";
    // the addition operator (+) is overloaded in the Cgpa class - https://www.programiz.com/cpp-programming/operator-overloading#:~:text=To%20overload%20an%20operator%2C%20we,.%20..%20...%20%7D%3B
    Cgpa student_new_cgpa = student_cgpa + student_sgpa;

    cout << "\nUnits taken: " << student_new_cgpa.units_taken;
    cout << "\nUnits passed: " << student_new_cgpa.units_passed;
    cout << "\nWeighted score: " << student_new_cgpa.weighted_score;
    cout << "\nGPA: " << student_new_cgpa.gpa;

    cout << endl;

    system("pause");

    return 0;
}