#ifndef _HEADER_H_
#define _HEADER_H_

// the integers on the right have those values assigned to them implicitly; this is just to be clear
enum Colour
{
    Red = 0,
    Yellow = 1,
    Green = 2,
    Blue = 3
};

struct House
{
    Colour colour;
    int member;
    bool status;

    // default struct constructor
    House()
    {
        colour = Red;
        member = 4;
        status = false;
    };
};

// keeps track of the houses that are assignable (not already taken by a player)
struct HousesAssigned
{
    bool Red, Yellow, Green, Blue;

    HousesAssigned()
    {
        Red = false;
        Yellow = false;
        Green = false;
        Blue = false;
    };
};

struct Player
{
    char name[40];
    // a player can have a maximum of two houses; 1 for a 4-player game, 2 for a 2-player game
    House houses[2];
};

void AssignRandomHouse(Player &, HousesAssigned &, int number_of_players);

void ConfigureGame(Player[4], int number_of_players);

void DisplayResults(Player[4], int number_of_players);

#endif