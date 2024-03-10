#include <iostream>

#include "header.h"

using namespace std;

int main(void)
{

    char player_name[40];
    int number_of_players;
    char type_of_grade;

    Player players[4];

    char temp[10];

    do
    {
        cout << "\nNumber of players (valid values are 2 and 4): ";
        cin.getline(temp, 10);
        number_of_players = atoi(temp);

    } while (number_of_players != 2 && number_of_players != 4);

    ConfigureGame(players, number_of_players, player_name, type_of_grade);

    DisplayResults(players, number_of_players);

    DeductMembers(players, number_of_players);

    DisplayResults(players, number_of_players);

    cout << endl;

    system("pause");

    return 0;
}