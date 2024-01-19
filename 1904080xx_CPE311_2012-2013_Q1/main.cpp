/***
 * USE VS 2010
 *
 * Question One [50 marks]
Write a complete C++ program that asks the user to enter a character string. Send the string
to a function called ReverseIt. This function will fill a second string so that the original string
is reversed. Limit the size of the strings to fifty characters. The last character in the original
string (before the null) should be the first character of the second string. Incorporate a loop
so that the user can continue to enter strings until he or she chooses to stop.
 *
 *
*/

#include <iostream>

#include "header.h"

using namespace std;

int main(void)
{

    char play_again;

    do
    {
        cout << "\nPlease type in a string: ";

        char input_string[50];
        cin.getline(input_string, 50);

        ReverseIt(input_string);

        cout << "\n\nDo you want to reverse another string? (Press Y for yes, any other key for no) ";
        cin >> play_again;
        cin.ignore(10, '\n');

    } while (play_again == 'Y' || play_again == 'y');

    system("pause");

    return 0;
}