#include <iostream>
// for strcpy function, string data type
#include <string>
// for toupper function
#include <cctype>
// for left manipulator
#include <iomanip>

#include "header.h"

using namespace std;

void ConfigureGame(Player players[4], int number_of_players, char player_name[40], char &type_of_color)
{

    // keeps track of which houses have been assigned
    // corresponds to houses Red, Yellow, Green and Blue respectively
    bool assigned_houses[4] = {false, false, false, false};

    // No_Colour is just a placeholder for invalid house inputs, and also serves as the default value
    Colour selected_house = No_Colour;
    // indicates if the selected house (house provided chosen by the gamemaster) is one of the possible 4
    bool is_selected_house_valid = false;

    char house_colours[4] = {'R', 'Y', 'G', 'B'};

    cout << "\nPlayers' information";

    for (int i = 0; i < number_of_players; i++)
    {

        cout << "\nPlayer " << (i + 1);
        cout << "\nName: ";
        cin.getline(player_name, 40);

        strcpy(players[i].name, player_name);

        for (int j = 0; j < (number_of_players == 2 ? 2 : 1); j++)
        {

            /*
                This loop is guaranteed to run at least once.
                The do-while loop is terminated when a player has been assigned a valid house.
            */
            do
            {

                cout << "\nPlease select a house:\nPossible values are R for Red, Y for Yellow, G for Green, B for Blue: ";
                cin >> type_of_color;
                // this is very important
                cin.ignore(10, '\n');

                // converts the input char to uppercase so we don't have to worry about if the user used uppercase or lowercase
                type_of_color = toupper(type_of_color);

                // in this switch block, we assume all inputs of R, Y, G, B are valid inputs whether they have been assigned already or not
                switch (type_of_color)
                {
                case 'R':
                    selected_house = Red;
                    is_selected_house_valid = true;
                    break;
                case 'Y':
                    selected_house = Yellow;
                    is_selected_house_valid = true;
                    break;
                case 'G':
                    selected_house = Green;
                    is_selected_house_valid = true;
                    break;
                case 'B':
                    selected_house = Blue;
                    is_selected_house_valid = true;
                    break;
                default:
                    selected_house = No_Colour;
                    cerr << "\nInvalid house selection.";
                }

                /* enums (in this case, selected house) are stored implicitly as integers already, it is not necessary to convert them to an int first
                 we use the index associated with an enum value to access and modify the assigned houses array

                 we then check if the selected house has been assigned, if it has, our assumption was wrong and we invalidate the selected house
                 by setting is_selected_house_valid to false
                 */

                // remember assigned_houses is just an array of booleans indicating if the corresponding house has been assigned
                if (selected_house != No_Colour && assigned_houses[selected_house])
                {
                    selected_house = No_Colour;
                    is_selected_house_valid = false;
                    cout << "\nThe house selected has been assigned to a different player. Please choose another house.";
                }

            } while (!is_selected_house_valid);

            // at this point, the selected house is a valid house that has not been assigned yet
            players[i].houses[j] = House(selected_house, 4, true);
            // enums (in this case, selected house) are stored implicitly as integers already, it is not necessary to convert them to an int first
            assigned_houses[selected_house] = true;
        }
    }
};

void DisplayResults(Player players[4], int number_of_players)
{

    string house_colours[4] = {"Red", "Yellow", "Green", "Blue"};

    cout << '\n'
         << left << setw(20) << "Name" << setw(20) << "House" << setw(20) << "Member";

    for (int i = 0; i < number_of_players; i++)
    {
        for (int j = 0; j < (number_of_players == 2 ? 2 : 1); j++)
        {
            cout << '\n'
                 << left << setw(20) << players[i].name << setw(20) << house_colours[players[i].houses[j].color] << setw(20) << players[i].houses[j].member;
        }
    }

    cout << endl;
};

void DeductMembers(Player players[4], int number_of_players) {

	for (int i = 0; i < number_of_players; i++) {
		for (int j = 0; j < (number_of_players == 2 ? 2 : 1); j++) {
			players[i].houses[j].member -= (i + 1);
		}
	}
};