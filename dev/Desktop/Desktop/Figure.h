#pragma once
#include <iostream>
#include <fstream>
#include <vector>

struct coords
{
    double x, y;
};

class Figure
{
public:
    virtual void add(Figure *a, int place) = 0;
    virtual std::vector <Figure*>getVec(int place) = 0;
    virtual std::string getType() = 0;
    Figure *from;
    std::string text;
    int weight;
    int firstBrunch;
    int height;
    coords coord;
};

