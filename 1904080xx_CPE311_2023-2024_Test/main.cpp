#include <iostream>

#include "header.h"

using namespace std;

int main(void)
{

    // temporary variable for storing user input before storage
    char temp[40];

    // these variables are for the gamemaster I guess - I didn't use player_name and type_of_color
    char player_name[40];
    int number_of_players;
    char type_of_color;

    do
    {

        cout << "\nNumber of players (the only valid options are 2 or 4): ";
        cin.getline(temp, 40);

        number_of_players = atoi(temp);

        cout << number_of_players;

    } while (number_of_players != 2 && number_of_players != 4);

    // maximum of 4 players
    Player players[4];

    ConfigureGame(players, number_of_players);

    DisplayResults(players, number_of_players);

    if (number_of_players == 2)
    {
        players[0].houses[0].member -= 1;
        players[0].houses[1].member -= 2;
        players[1].houses[0].member -= 3;
        players[1].houses[1].member -= 4;
    }
    else if (number_of_players == 4)
    {
        players[0].houses[0].member -= 1;
        players[1].houses[0].member -= 2;
        players[2].houses[0].member -= 3;
        players[3].houses[0].member -= 4;
    }

    DisplayResults(players, number_of_players);

    system("pause");

    return 0;
}