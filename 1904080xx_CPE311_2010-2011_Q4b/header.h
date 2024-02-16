#ifndef _HEADER_H_
#define _HEADER_H_

// base class
class Shape
{

public:
    // the function doesn't do anything when called (nothing was specified in the question)
    void WhatAmI(){};
};

// derived classes

// the derived classes inherit the WhatAmI() function from the base class Shape
// Inheritance in C++ - https://www.programiz.com/cpp-programming/inheritance

class Cone : public Shape
{
};

class Sphere : public Shape
{
};

class Pyramid : public Shape
{
};

class Box : public Shape
{
};

#endif