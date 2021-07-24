#include "Figure.h"

class Circle: public Figure
{
public:
    Circle()
    {
        from = this;
        coord.x = 0;
        coord.y = 0;
        weight = 100;
        height = 50;
    }
    std::vector <Figure*>getVec(int place)
    {
        return body;
    }
    std::string getType()
    {
        return "Circle";
    }
    void add(Figure *a, int place)
    {
        body.push_back(a);
    }
    std::vector <Figure*> body;

};
