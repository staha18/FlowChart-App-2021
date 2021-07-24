#include <SFML/Graphics.hpp>
#include "Drawer.h"
#include <vector>
#include "parse.h"
#include <string>

int main() {
    pair<vector<Figure*>, vector <Line>> res (parse());
    vector<Figure*>ans = res.first;
    vector<Line>lines = res.second;


	Drawer img;
	for(int i = 0; i < lines.size(); i++)
    {
        img.drawLine(lines[i].y, lines[i].x, lines[i].len, lines[i].tick, lines[i].angle);
    }
	for(int i = 0; i < ans.size()-1; i++)
    {
        cout << ans[i] -> getType() << " " << ans[i] -> coord.x << " " << ans[i]->coord.y << " " << ans[i]->height << endl;
        if(ans[i] -> getType() != "Rectangle")
        {
            if(ans[i] -> getType() == "Circle")
            {
                img.drawShape(ans[i] -> coord.y, ans[i] -> coord.x);
            }else
                img.drawSquare(ans[i] -> coord.y, ans[i] -> coord.x, 100, 50);
        }else{
            img.drawRec(ans[i] -> coord.y, ans[i] -> coord.x,100, 50);
        }
    }



	//img.drawRec(0.f, 0.f, 100.f, 50.f);
	//img.drawRec(900.f, 300.f, 100.f, 50.f);
	//img.drawRec(900.f, 400.f, 100.f, 50.f);
	//img.drawLine(900.f, 250.f, 50, 1, 90);
	//img.drawLine(900.f, 350.f, 50, 1, 90);
	//img.drawLine(900.f, 450.f, 50, 1, 90);
	//img.drawSquare(900.f, 500.f, 50);
	//img.drawLine(950.f, 550.f, 50, 1, 0);
	//img.drawLine(850.f, 550.f, 50, 1, 180);

	img.saveToDisk("toto.png");
	system("toto.png");
	return 0;

}
