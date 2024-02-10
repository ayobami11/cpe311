#include <iostream>
// for srand and rand
#include <stdlib.h>
// for left manipulator; setw function
#include <iomanip>
// for strcpy
#include <string.h>

#include "header.h"

using namespace std;

void AssignRandomHouse(Player &player, HousesAssigned &assigned_houses, int number_of_players)
{

    // generates a seed value for producing random numbers
    srand((unsigned)time(NULL));

    /*
        number_of_players because:
            for a 2-player game: number of houses for a single player should be 2 i.e. i = 0 then i = 1 (2 iterations of the loop)
            for a 4-player game: number of houses for a single player should be 1 i.e. i = 0 (1 iteration of the loop)
    */
    int i = 0;

    // do-while loops are guaranteed to run at least one
    // in this case, the loop only runs a second time if it is a 2-player game meaning a player should have 2 houses
    do
    {

        // Assigns a house randomly to a player; this loop runs until an unassigned house is found
        while (!player.houses[i].status)
        {

            // generates a random int between 0 and 3
            int random_number = rand() % 4;

            /*
                Mapping of integers to houses:
                    0 - Red
                    1 - Yellow
                    2 - Green
                    3 - Blue
            */
            switch (random_number)
            {
            case 0:
                if (!assigned_houses.Red)
                {
                    player.houses[i].colour = Red;
                    player.houses[i].status = true;
                    assigned_houses.Red = true;
                }

                break;
            case 1:
                if (!assigned_houses.Yellow)
                {
                    player.houses[i].colour = Yellow;
                    player.houses[i].status = true;
                    assigned_houses.Yellow = true;
                }

                break;
            case 2:
                if (!assigned_houses.Green)
                {
                    player.houses[i].colour = Green;
                    player.houses[i].status = true;
                    assigned_houses.Green = true;
                }

                break;
            case 3:
                if (!assigned_houses.Blue)
                {
                    player.houses[i].colour = Blue;
                    player.houses[i].status = true;
                    assigned_houses.Blue = true;
                }

                break;
            default:
                cout << "\nInvalid house index.";
            }
        }

        i++;

    } while (number_of_players == 2 && i < 2);
}

void ConfigureGame(Player players[4], int number_of_players)
{

    HousesAssigned assigned_houses;

    char temp[40];

    cout << "\nPlayers' information:\n";

    for (int i = 0; i < number_of_players; i++)
    {
        cout << "\nPlayer " << (i + 1);
        cout << "\n\tName: ";
        cin.getline(temp, 40);
        strcpy(players[i].name, temp);

        // 4-player game: a player is assigned 1 house
        // 2-player game: a player is assigned 2 houses
        for (int j = 0; j < (number_of_players / 2); j++)
        {
            AssignRandomHouse(players[i], assigned_houses, number_of_players);
        }
    }
};

void DisplayResults(Player players[4], int number_of_players)
{

    char house_names[4][10] = {"Red", "Yellow", "Green", "Blue"};

    cout << left << setw(20) << "Name" << setw(20) << "House" << setw(20) << "Member"
         << "\n";

    for (int i = 0; i < number_of_players; i++)
    {

        int j = 0;

        do
        {
            cout << left << setw(20) << players[i].name << setw(20) << house_names[players[i].houses[j].colour] << setw(20) << players[i].houses[j].member << "\n";

            j++;
        } while (number_of_players == 2 && j < 2);
    }

    cout << endl;
};