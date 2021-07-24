#pragma once
#include "Figure.h"

class While: public Figure
{
public:
    While(Figure * a)
    {
        from = a;
        coord.x = 0;
        coord.y = 0;
        weight = 100;
        height = 50 + 50;
    }
    std::vector <Figure*>getVec(int place)
    {
        return body;
    }
    std::string getType()
    {
        return "While";
    }
    void add(Figure *a, int place)
    {
        body.push_back(a);
    }
    std::vector <Figure*> body;
};
