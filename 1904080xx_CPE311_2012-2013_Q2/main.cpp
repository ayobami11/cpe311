/****
 *
 * USE VS 2010
 *
 * Question Two [50 marks]
Write a structure tag and short main program that sets up a struct for a baseball pitcher that
contains his name, earned run average (ERA), innings pitched and strikeout percentage. In
the program, declare one pitcher variable and pass its address to a function called Smokin’.
This function fills the pitcher variable with the following information:
Name: Smokin’ Joe Green ERA: 1.2
Innings pitched: 55 Strikeout percentage: 0.25
Once the data is in the structure, write the pitcher information to the screen.
 *
 *
 *  ***/

#include <iostream>

#include "header.h"

using namespace std;

int main(void)
{

    Pitcher joegreen;

    Smokin(&joegreen);

    cout << "\nPitcher information: ";

    cout << "\nName: " << joegreen.Name << " ERA: " << joegreen.ERA;
    cout << "\nInnings pitched: " << joegreen.InningsPitched << " Strikeout percentage: " << joegreen.StrikeoutPercentage;

    cout << endl;

    system("pause");

    return 0;
}