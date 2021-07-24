#pragma once
#include "Figure.h"

class If: public Figure
{
public:
    If(Figure * a)
    {
        from = a;
        weight = 100;
        height = 50 + 50;
        coord.x = 0;
        coord.y = 0;
        firstBrunch = 0;
    }
    std::string getType()
    {
        return "If";
    }

    std::vector <Figure*>getVec(int place)
    {
        if(place == 1)
        {
            return bodyYes;
        }else{
            return bodyNo;
        }
    }
    void add(Figure *a, int place)
    {
        if(place == 1)
        {
            bodyYes.push_back(a);
        }else{
            bodyNo.push_back(a);
        }
    }
    int firstBrunch;
    std::vector <Figure*> bodyYes;
    std::vector <Figure*> bodyNo;
};
