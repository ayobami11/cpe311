#include <iostream>
// for string data type; strcpy function
#include <string>
// for left manipulator; setw function
#include <iomanip>

#include "header.h"

using namespace std;

/*
	player_name is a char array so what we are accessing in the function is actually a pointer to player_name (i.e. address of player_name) - just as for a normal array
	no need to dereference though using * or -> since it is already handled internally (for arrays)
*/
void ConfigureGame(Player players[4], int number_of_players, char player_name[40], char &type_of_color) {

	char possible_houses[4] = {'R', 'Y', 'G', 'B'}; // for Red, Yellow, Green, Blue
	// keeps track of the current position in the possible_houses array
	// in this solution, houses are assigned starting from the left of the array so house Red is assigned first, then Yellow, ...
	int house_index = 0;

	for (int i = 0; i < number_of_players; i++) {
		// (i + 1) because index starts from 0
		cout << "\nPlayer " << (i + 1);
		cout << "\nName: ";

		cin.getline(player_name, 40);

		strcpy(players[i].name, player_name);

		/*
			(number_of_players == 2 ? 2 : 1) - shorthand for if-else statement
				if the number_of_players is 2, this inner loop runs twice because a single player can be assigned two houses i.e. j = 0, then j = 1
				if not (i.e. number_of_players is 4 or anything other than 2), this loop runs just once i.e. j = 0
		*/
		for (int j = 0; j < (number_of_players == 2 ? 2 : 1); j++) {

			type_of_color = possible_houses[house_index++];
			/*
				equivalent to:
				type_of_color = possible_houses[house_index];
				house_index++;
			*/

			switch (type_of_color) {
				case 'R':
					players[i].houses[j].color = Red;
					players[i].houses[j].status = true;
					break;
				case 'Y':
					players[i].houses[j].color = Yellow;
					players[i].houses[j].status = true;
					break;
				case 'G':
					players[i].houses[j].color = Green;
					players[i].houses[j].status = true;
					break;
				case 'B':
					players[i].houses[j].color = Blue;
					players[i].houses[j].status = true;
					break;
				default:
					cerr << "\nInvalid house color.";
			}
		}

	}
};

void PrintResults(Player players[4], int number_of_players) {

	string houses[4] = {"Red", "Yellow", "Green", "Blue"};
	
	cout << left << setw(20) << "Name" << setw(20) << "House" << setw(20) << "Member" << '\n';

	for (int i = 0; i < number_of_players; i++) {
		for (int j = 0; j < (number_of_players == 2 ? 2 : 1); j++) {
			/*
				players[i].houses[j].color is an enum value of type Colour which is actually stored as an integer
				this integer is then used to access the corresponding house from the houses array
			*/
			cout << left << setw(20) << players[i].name << setw(20) << houses[players[i].houses[j].color] << setw(20) << players[i].houses[j].member << '\n';
		}
	}	
	

	cout << endl;
};

void DeductMembers(Player players[4], int number_of_players) {

	int members_to_deduct = 0;

	for (int i = 0; i < number_of_players; i++) {
		for (int j = 0; j < (number_of_players == 2 ? 2 : 1); j++) {
			// increments members_to_deduct first before decreasing the number of members associated with a house
			/*
				equivalent to:
				members_to_deduct += 1;
				players[i].houses[j].member -= members_to_deduct;
			*/
			players[i].houses[j].member -= ++members_to_deduct;
		}
	}
}