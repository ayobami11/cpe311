#ifndef _HEADER_H_
#define _HEADER_H_

enum Colour
{
    Red,
    Yellow,
    Green,
    Blue
};

struct House
{

    Colour color;
    int member;
    bool status;

    // Default struct constructor - https://linuxhint.com/struct-constructor-cpp/
    House()
    {
        color = Red;
        member = 4;
        status = false;
    };

    /*
        Alternative syntax: initializer list syntax

        House(): color(Red), member(4), status(false) {};
    */
};

struct Player
{
    char name[40];
    // a player can be assigned a maximum of two houses
    House houses[2];
};

// using a reference parameter for type_of_color (fourth parameter)
void ConfigureGame(Player[4], int, char[40], char &);

void DeductMembers(Player[4], int);

void PrintResults(Player[4], int);

#endif