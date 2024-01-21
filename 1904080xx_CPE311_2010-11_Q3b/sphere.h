#ifndef _HEADER_H_
#define _HEADER_H_

class Sphere
{
private:
    float radius;
    float CalcArea();
    float CalcVol();

public:
    Sphere();
    void PrintResults();
};

#endif