#include <iostream>

#include "header.h"

using namespace std;

int main(void)
{

    char player_name[40];
    int number_of_players;
    char type_of_color;

    Player players[4];

    // using a char temporarily to stor number of players so as to be more tolerant of user input e.g. invalid inputs like letters could cause an infinite loop
    char temp[10];

    // this loop runs until the user provides a valid input of 2 or 4
    do
    {
        cout << "\nNumber of players (valid values are 2 and 4): ";
        cin.getline(temp, 10);
        // converts the user input to an integer, non-numeric inputs would evaluate to 0
        number_of_players = atoi(temp);
    } while (number_of_players != 2 && number_of_players != 4);

    ConfigureGame(players, number_of_players, player_name, type_of_color);

    DisplayResults(players, number_of_players);

    DeductMembers(players, number_of_players);

    DisplayResults(players, number_of_players);

    cout << endl;

    system("pause");

    return 0;
};