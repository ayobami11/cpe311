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
    Date birthday;
};

Person FillPerson();

void WritePerson(Person);

void WhoIsOlder(Person, Person);

#endif