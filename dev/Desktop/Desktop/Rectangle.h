#pragma once
#include "Figure.h"

class Rectangle: public Figure
{
public:
    Rectangle(Figure *a)
    {
        from = a;
        coord.x = 0;
        coord.y = 0;
        weight = 100;
        height = 50 + 50;
    }
    std::string getType()
    {
        return "Rectangle";
    }
    void add(Figure *a, int place)
    {
        from = a;
        coord.x = 0;
    }
    std::vector <Figure*>getVec(int place)
    {
        return a;
    }
    std::vector<Figure*>a;

};

