#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

#include "header.h"

using namespace std;

void ConfigureGame(Player players[4], int number_of_players, char player_name[40], char &type_of_color)
{

    Colour chosen_house = NoColor;
    bool assigned_houses[4] = {false, false, false, false};
    bool exists = false;

    cout << "\nPlayers' information.\n";

    for (int i = 0; i < number_of_players; i++)
    {

        cout << "\nPlayer" << (i + 1) << ":";
        cout << "\nName: ";

        cin.getline(player_name, 40);
        strcpy(players[i].name, player_name);

        for (int j = 0; j < (number_of_players == 2 ? 2 : 1); j++)
        {

            do
            {
                // as the gamemaster
                cout << "\nAssign a house to a player:\n\tR for Red\n\tY for Yellow\n\tG for Green\n\tB for Blue.";
                cout << "\nValid options are R, Y, G and B: ";

                cin >> type_of_color;

                cin.ignore(10, '\n');

                type_of_color = toupper(type_of_color);

                switch (type_of_color)
                {
                case 'R':
                    chosen_house = Red;
                    exists = true;
                    break;
                case 'Y':
                    chosen_house = Yellow;
                    exists = true;
                    break;
                case 'G':
                    chosen_house = Green;
                    exists = true;
                    break;
                case 'B':
                    chosen_house = Blue;
                    exists = true;
                    break;
                default:
                    cerr << "\nInvalid house color.";
                }

                // if a house has already been assigned
                if (chosen_house != NoColor && assigned_houses[chosen_house])
                {
                    exists = false;
                    cout << "\nPlease select a different house, this house has already been assigned.\n";
                }

            } while (!exists);

            players[i].houses[j] = House(chosen_house, 4, true);
            assigned_houses[chosen_house] = true;
        }
    }
};

void DisplayResults(Player players[4], int number_of_players)
{

    string house_colors[4] = {"Red", "Yellow", "Green", "Blue"};
    int members_to_deduct = 0;

    cout << '\n'
         << left << setw(20) << "Name" << setw(20) << "House" << setw(20) << "Member";

    for (int i = 0; i < number_of_players; i++)
    {
        for (int j = 0; j < (number_of_players == 2 ? 2 : 1); j++)
        {
            cout << '\n'
                 << left << setw(20) << players[i].name << setw(20) << house_colors[players[i].houses[j].color] << setw(20) << players[i].houses[j].member;
        }
    }

    cout << endl;
};

void DeductMembers(Player players[4], int number_of_players)
{

    int members_to_deduct = 0;

    for (int i = 0; i < number_of_players; i++)
    {
        for (int j = 0; j < (number_of_players == 2 ? 2 : 1); j++)
        {
            players[i].houses[j].member -= ++members_to_deduct;
        }
    }
}