#include <iostream>
#include <string.h>
#include <ctime>

#include "header.h"

using namespace std;

Person FillPerson()
{

    Person new_person;

    cout << "\nPlease input the following information: ";

    char temp[40];

    cout << "\nName: ";
    cin.getline(temp, 40);
    strcpy_s(new_person.name, temp);

    cout << "\nBirthday information (format: dd-mm-yyyy) : ";
    cout << "\n\tDay: ";
    // max size for input here has to be 3 (not 2) because the last space is reserved for the null character I guess
    cin.getline(temp, 3);
    // atoi - converts char array to int
    new_person.birthday.day = atoi(temp);

    cout << "\tMonth: ";
    cin.getline(temp, 3);
    new_person.birthday.month = atoi(temp);

    cout << "\tYear: ";
    // max size for input here has to be 5 (not 4) because the last space is reserved for the null character I guess
    cin.getline(temp, 5);
    new_person.birthday.year = atoi(temp);

    return new_person;
}

void WritePerson(Person person)
{

    char months[12][15] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    cout << "\nPerson information:";

    cout << "\nName: " << person.name;

    cout << "\nBirthday information: ";

    cout << "\n\tDay: " << person.birthday.day;
    // month - 1 because arrays are zero-indexed
    cout << "\n\tMonth: " << months[person.birthday.month - 1];
    cout << "\n\tYear: " << person.birthday.year;

    cout << endl;
}

void WhoIsOlder(Person person1, Person person2)
{

    WritePerson(person1);
    WritePerson(person2);

    struct tm new_time;
    time_t now = time(0);

    localtime_s(&new_time, &now);

    // new_time.tm_hour returns years elapsed since 1990
    int current_year = 1900 + new_time.tm_year;

    cout << "\n"
         << person1.name << " is " << (current_year - person1.birthday.year) << " years old.";
    cout << "\n"
         << person2.name << " is " << (current_year - person2.birthday.year) << " years old.";

    bool is_person1_older;

    is_person1_older = (person1.birthday.year < person2.birthday.year) || (person1.birthday.month < person2.birthday.month) || (person1.birthday.day < person1.birthday.day);

    cout << "\n"
         << (is_person1_older ? person1.name : person2.name) << " is older than " << (!is_person1_older ? person1.name : person2.name) << " by about " << abs(person1.birthday.year - person2.birthday.year) << " years." << endl;
}