#include "Figure.h"

class Func: public Figure
{
public:
    Func()
    {
        from = this;
        coord.x = 0;
        coord.y = 1000;
        weight = 100;
        height = 50 + 50;
    }
    std::vector <Figure*>getVec(int place)
    {
        return body;
    }
    std::string getType()
    {
        return "Main";
    }
    void add(Figure *a, int place)
    {
        body.push_back(a);
    }
    std::vector <Figure*> body;

};
