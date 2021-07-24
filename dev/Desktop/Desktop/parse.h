#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Func.h"
#include "For.h"
#include "If.h"
#include "While.h"
#include "Rectangle.h"
#include "Circle.h"

using namespace std;

struct Line
{
    double x, y, angle, len;
    int tick;
};

void lineRectangle(vector <Line>&lines, Figure * a)
{
    Line line;
    line.x = a -> coord.x + 50;
    line.y = a -> coord.y;
    line.tick = 1;
    line.len = 50;
    line.angle = 90;
    lines.push_back(line);
}

void ifLine(vector <Line>&lines, Figure * a)
{
    Line line1, line2;
    line1.angle = 90;
    line1.x = a->coord.x + 25;
    line1.y = a->coord.y - (a -> weight)/4;
    line1.tick = 1;
    line1.len = a->height - 50;
    lines.push_back(line1);

    line1.angle = 90;
    line1.x = a->coord.x + 25;
    line1.y = a->coord.y + (a -> weight)/4;
    line1.tick = 1;
    line1.len = a->height - 50;
    lines.push_back(line1);

    line2.angle = 0;
    line2.x = a->coord.x + 25;
    line2.y = a->coord.y - (a -> weight)/4;
    line2.tick = 1;
    line2.len = a->weight/2;
    lines.push_back(line2);

    line2.angle = 0;
    line2.x = a->coord.x + a -> height - 25;
    line2.y = a->coord.y - (a -> weight)/4;
    line2.tick = 1;
    line2.len = a->weight/2;
    lines.push_back(line2);


    line1.angle = 90;
    line1.x = a->coord.x + a -> height - 25;
    line1.y = a->coord.y;
    line1.tick = 1;
    line1.len = 25;
    lines.push_back(line1);

}

void forLine(vector <Line>&lines, Figure * a)
{
    Line line;
    line.x = a -> coord.x + 50;
    line.y = a -> coord.y;
    line.tick = 1;
    line.len = 50;
    line.angle = 90;
    lines.push_back(line);

        Line line1, line2;
        line2.angle = 0;
        line2.x = a->coord.x + 25;
        line2.y = a->coord.y - (a -> weight);
        line2.tick = 1;
        line2.len = a->weight * 2;
        lines.push_back(line2);

        line1.angle = 90;
        line1.x = a->coord.x + 25;
        line1.y = a->coord.y - (a -> weight);
        line1.tick = 1;
        line1.len = a->height - 60;
        lines.push_back(line1);

        line1.angle = 90;
        line1.x = a->coord.x + 25;
        line1.y = a->coord.y + (a -> weight);
        line1.tick = 1;
        line1.len = a->height - 40;
        lines.push_back(line1);

        line2.angle = 0;
        line2.x = a -> coord.x + (a->height - 35);
        line2.y = a->coord.y - (a -> weight);
        line2.tick = 1;
        line2.len = a->weight;
        lines.push_back(line2);

        line2.angle = 0;
        line2.x = a -> coord.x + (a->height - 15);
        line2.y = a->coord.y;
        line2.tick = 1;
        line2.len = a->weight;
        lines.push_back(line2);


        line1.angle = 90;
        line1.x = a->coord.x + a -> height - 15;
        line1.y = a->coord.y;
        line1.tick = 1;
        line1.len = 15;
        lines.push_back(line1);

        line1.angle = 90;
        line1.x = a->coord.x + a -> height - 50;
        line1.y = a->coord.y;
        line1.tick = 1;
        line1.len = 15;
        lines.push_back(line1);
}

bool isWordSymbol(char c)
{
    if(c <= '9' && c >= '0')
        return 1;
    if(c >= 'a' && c <= 'z')
        return 1;
    if(c >= 'A' && c <= 'Z')
        return 1;
    if(c == '_')
        return 1;
    return 0;
}

bool isKeyWord(string s)
{
    if(s == "for" || s == "if" || s == "while" || s == "else")
        return 1;
    return 0;
}

void dfs(Figure * a, int q)
{
    vector <Figure*>flag;
    if(a -> getType() == "If")
    {
        flag = a -> getVec(1);
        for(int i = 0; i < flag.size(); i++)
        {
            dfs(flag[i], 1);
        }
        flag = a -> getVec(0);
        for(int i = 0; i < flag.size(); i++)
        {
            dfs(flag[i], 0);
        }

    }
    if(a -> getType() != "If")
    {
        flag = a -> getVec(1);
        for(int i = 0; i < flag.size(); i++)
        {
            dfs(flag[i], 1);
        }
    }


    if(q == 1)
    {
        a -> from ->height += a -> height;
    }else{
        a -> from ->firstBrunch += a->height;
    }

    if(a -> from -> getType() == "If")
    {
        a -> from -> weight += (a -> weight)/2 + 100;
    }

    if(a -> getType() == "If")
    {
        a -> height = max(a->height, a->firstBrunch);
        a -> from -> weight += (a -> weight);
    }



}

void dfs2(Figure * a, int q, vector <Figure*>&res, vector <Line>&lines)
{
    vector <Figure*>flag;

    if(a -> getType() == "If")
    {
        flag = a -> getVec(0);
        if(!flag.empty())
        {
            flag[0] -> coord.x = a->coord.x + 100;
            flag[0] -> coord.y = a->coord.y;
            flag[0] -> coord.y += (a->weight/4);

        }
        for(int i = 1; i < flag.size(); i++)
        {
            flag[i] -> coord.x = flag[i-1] -> coord.x + flag[i-1] -> height;
            flag[i] -> coord.y = flag[i-1] -> coord.y;
            flag[i] -> coord.y = flag[i-1] -> coord.y;
        }
    }

    flag = a -> getVec(1);
    if(!flag.empty())
    {
        flag[0] -> coord.x = a->coord.x + 100;
        flag[0] -> coord.y = a->coord.y;
        if(a -> getType() == "If")
        {
            flag[0] -> coord.y -= (a->weight/4);
        }
    }
    for(int i = 1; i < flag.size(); i++)
    {
        flag[i] -> coord.x = flag[i-1] -> coord.x + flag[i-1] -> height;
        flag[i] -> coord.y = flag[i-1] -> coord.y;
    }

    if(a -> getType() == "If")
    {
        flag = a -> getVec(1);
        for(int i = 0; i < flag.size(); i++)
        {
            dfs2(flag[i], q + 1, res, lines);
        }
        flag = a -> getVec(0);
        for(int i = 0; i < flag.size(); i++)
        {
            dfs2(flag[i], q + 1, res, lines);
        }

    }
    if(a -> getType() == "For" || a -> getType() == "Main")
    {
        flag = a -> getVec(1);
        for(int i = 0; i < flag.size(); i++)
        {
            dfs2(flag[i], q + 1, res, lines);
        }
    }

    if(a -> getType() == "For" || a -> getType() == "While")
    {
        forLine(lines, a);
    }else if(a -> getType() == "If")
    {
        ifLine(lines, a);
    }else if(a -> getType() != "Main")
    {
        if(a -> getType() == "Circle")
        {
            if(a -> coord.x < 101)
            {
                cout << a -> coord.x << endl;
                lineRectangle(lines, a);
            }
        }else{
            lineRectangle(lines, a);
        }
    }

    res.push_back(a);

}

pair<vector<Figure*>, vector <Line>> parse()
{
    ifstream in;
    in.open("C:\\Users\\pesch\\Desktop\\FlowChart-App\\dev\\Desktop\\Desktop\\data.txt");
    string s, res;
    while(!in.eof())
    {
        getline(in, s);
        res += s;
    }

    s.clear();

    Func flag;

    Circle* head = new Circle;
    Circle* tail = new Circle;

    Figure *ptr = &flag;
    Figure *ptrPrev = &flag;

    ptr -> add(head, 0);
    Rectangle *fict4 = new Rectangle(ptr);
    ptr -> add(fict4, 0);


    bool yesBrunch = 1;

    for(int i = 0; i < res.size(); i++)
    {
        if(isWordSymbol(res[i]))
        {
            s.push_back(res[i]);
        }else{
            if(isKeyWord(s))
            {
                if(s == "if")
                {
                    If * q = new If(ptr);
                    ptr -> add(q, yesBrunch);
                    Rectangle *fict = new Rectangle(q);
                    q -> add(fict, 1);
                    Rectangle *fict2 = new Rectangle(q);
                    q -> add(fict2, 0);

                    ptr = q;


                }else if(s == "for")
                {
                    For *q = new For(ptr);
                    ptr -> add(q, yesBrunch);
                    Rectangle *fict = new Rectangle(q);
                    q -> add(fict, 0);
                    ptr = q;
                }else if(s == "else")
                {
                    ptr = ptrPrev;
                    yesBrunch = !yesBrunch;
                }else if(s == "while")
                {
                    While *q = new While(ptr);
                    ptr -> add(q, yesBrunch);
                    Rectangle *fict = new Rectangle(q);
                    q -> add(fict, yesBrunch);
                    ptr = q;
                }
            }
            s.clear();
        }
        if(res[i] == '}')
        {
            ptrPrev = ptr;
            ptr = ptr -> from;
            yesBrunch = 1;
        }

    }

    ptr -> add(tail, 0);
    vector <Line>lines;
    vector<Figure*>ans;
    dfs(&flag, 1);
    dfs2(&flag, 0, ans, lines);
    return make_pair(ans, lines);
}

