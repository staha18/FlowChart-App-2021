#pragma once
#include <SFML/Graphics.hpp>
class Drawer : public sf::RenderTexture
{
private:

	sf::RenderTexture renderTexture;
public:
	Drawer();
	void drawShape(float x, float y);
	void drawRec(float x, float y, float height, float weight);
	void drawLine(float x, float y, float length, float thickness, float angle);
	void drawSquare(float x, float y, float weight, float height);
	void saveToDisk(const char* path);
};

