#ifndef _HEADER_H_
#define _HEADER_H_

enum Colour
{
    Red,
    Yellow,
    Green,
    Blue,
    No_Colour
};

struct House
{

    Colour color;
    int member;
    bool status;

    House(Colour c = Red, int m = 4, bool s = false)
    {
        color = c;
        member = m;
        status = s;
    }
};

struct Player
{
    char name[40];
    House houses[2];
};

void ConfigureGame(Player[4], int, char[40], char &);

void DisplayResults(Player[4], int);

void DeductMembers(Player[4], int);

#endif