/****
 *
 * USE VS 2010
 *
 * Question Three [50 marks]
Write a program that sets up a Date structure (integer for month, day and year) and a
Person structure (name and birthday – using the Date struct). The program should have a
function (FillPerson) that asks the user to enter all the names and birthday information. The
prototype for this function is:
Person FillPerson();
You should also have a function called WritePerson that writes out all the person
information using the name of the month (as opposed to the integer value) for the birthday
month. The prototype for this function is:
void WritePerson(Person);
your program should have two Person variables. It should fill these two variables and then
call a function called WhoIsOlder, which is sent both Person variables. The function
determines who is older and writes the age status to the screen. (Note: WhoIsOlder should
call WritePerson twice.)
 *
 *
 *  ***/

#include <iostream>

#include "header.h"

using namespace std;

int main(void)
{

    Person hazel, gus;
    hazel = FillPerson();
    gus = FillPerson();

    WhoIsOlder(hazel, gus);

    cout << endl;

    system("pause");

    return 0;
}