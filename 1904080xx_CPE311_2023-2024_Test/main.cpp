#include <iostream>

#include "header.h"

using namespace std;

int main(void)
{

    char player_name[40];
    int number_of_players;
    char type_of_color;

    Player players[4];

    // temporary variable which accepts the input for the number of players before it is stored
    char temp[10];

    // loop runs until user provides a valid input
    do
    {
        cout << "\nNumber of players (valid values are 2 or 4): ";

        cin.getline(temp, 10);
        number_of_players = atoi(temp);

    } while (number_of_players != 2 && number_of_players != 4);

    ConfigureGame(players, number_of_players, player_name, type_of_color);

    cout << "\nPlayers' information before deduction of members.\n";
    PrintResults(players, number_of_players);

    // helper function to deduct members as specified in the question
    DeductMembers(players, number_of_players);

    cout << "\nPlayers' information after deduction of members.\n";
    PrintResults(players, number_of_players);

    system("pause");

    return 0;
};