#ifndef _HEADER_H_
#define _HEADER_H_

struct Date
{
    int month;
    int day;
    int year;
};

struct Person
{
    char name[40];
    // birthday variable is of custom data type Date
    Date birthday;
};

Person FillPerson();

void WritePerson(Person);

void WhoIsOlder(Person, Person);

#endif